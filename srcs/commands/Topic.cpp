//LEO

#include "../../include/Server.hpp"
#include "../../include/Client.hpp"
#include "../../include/Commands.hpp"
#include "../../include/Channel.hpp"

// TOPIC reply message example:
//  >invia messaggio 331(RPL_NOTOPIC) o 332(RPL_TOPIC)
//   "<client> <channel> :No topic is set" o "<client> <channel> :<topic>"
//   ":irc.example.com 332 alice #general :Welcome to the general channel"
//  >invia messaggio 333(RPL_TOPICWHOTIME to let them know who set the topic (<nick>) and when they set it (<setat> is a unix timestamp)
//   "<client> <channel> <nick> <setat>"
//   ":irc.example.com 333 alice #general bob *date*"
static void giveTopic(Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {
	(void) trailing;
	Channel *channel = server.getChannel(params[0]);

	if (channel->getTopic().empty()) {
			//invia messaggio 331(RPL_NOTOPIC)
			client.sendMessage("331 " + client.getNickname() + " " + channel->getName() + " :No topic is set\r\n");
	}
	else {
		client.sendMessage(":server 332 " + client.getNickname() + " #" + \
			channel->getName() + " :" + channel->getTopic() + "\r\n");
		client.sendMessage(":server 333 " + client.getNickname() + " " + \
			channel->getTopicCreator() + " " + channel->getTopicTime() + "\r\n");
	}
}

//cambia topic e aggiorna nome dell'user e data della modifica
static void	changeTopic(Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {
	Channel *channel = server.getChannel(params[0]);

	channel->setTopic(trailing, &client);

	//invia messaggio 332(RPL_TOPIC)
	channel->broadcast(":server 332 " + client.getNickname() + " #" + \
		channel->getName() + " :" + channel->getTopic() + "\r\n");
	//invia messaggio 333(RPL_TOPICWHOTIME)
	channel->broadcast(":server 333 " + client.getNickname() + " " + \
			channel->getTopicCreator() + " " + channel->getTopicTime() + "\r\n");
}

//set o mostra topic di canale
//https://modern.ircdocs.horse/#topic-message
void cmd_topic (Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {
	//prima cosa da controllare
	if (params.empty()) {
		//invia messaggio 461 (ERR_NEEDMOREPARAMS)
		client.sendMessage("461 " + client.getNickname() + " TOPIC" + ": not enough parameters\r\n");
		return;//+aggiunto return
	}
	Channel *channel = server.getChannel(params[0]);
	//+aggiunto controllo se canale non esiste
	if(!channel) {
		client.sendMessage("403 " + client.getNickname() + " " + params[0] + " :No such channel\r\n");
		return ;
	}
	
	if (channel->isMember(&client) == false) {
		client.sendMessage("442 " + client.getNickname() + " " + channel->getName() + " :You're not on that channel\r\n"); //sistemato messaggio secondo 6.1. Error replies
		return ; //+ aggiunto return
	}
	//questo controllo solo se esiste il trailng ( = richiesta di cambio)
	if(!trailing.empty()) {
		if (channel->isTopicRestricted() == true && \
			channel->isOperator(&client) == false) {
				//invia messaggio 482 (ERR_CHANOPRIVSNEEDED)
				client.sendMessage("482 " + client.getNickname() + " " + channel->getName() +  " :You're not channel operator\r\n"); //6.1. Error replies
				return ; //+ aggiunto
		}
		changeTopic(server, client, params, trailing);
	}
	else
		giveTopic(server, client, params, trailing);
	return ;
}
