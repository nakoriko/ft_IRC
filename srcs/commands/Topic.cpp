//LEO

#include "../../include/Server.hpp"
#include "../../include/Client.hpp"
#include "../../include/Commands.hpp"
#include "../../include/Channel.hpp"

static void giveTopic(Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {
	(void) trailing;
	Channel *channel = server.getChannel(params[0]);

	if (channel->getTopic().empty()) {
			//invia messaggio 331(RPL_NOTOPIC)
			client.sendMessage("331 " + client.getNickname() + " " + channel->getName() + " :No topic is set\r\n");
	}
	else {
		//invia messaggio 332(RPL_TOPIC)
		client.sendMessage(":server 332 " + client.getNickname() + ": the topic of #" + \
			channel->getName() + " is " + channel->getTopic() + "\r\n");
		//invia messaggio 333(RPL_TOPICWHOTIME to let them know who set the topic (<nick>) and when they set it (<setat> is a unix timestamp)
		client.sendMessage(":server 332 " + client.getNickname() + ": topic last changed by " + \
			channel->getTopicCreator() + " on " + channel->getTopicTime() + "\r\n");
	}
}

//cambia topic e aggiorna nome dell'user e data della modifica
static void	changeTopic(Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {
	Channel *channel = server.getChannel(params[0]);

	channel->setTopic(trailing, &client);
	if (channel->getTopic() == "") {
		//invia messaggio 331(RPL_NOTOPIC)
		client.sendMessage(":server 331 " + client.getNickname() + ": has deleted the channel #" + channel->getName() + "'s topic\r\n");
	}
	else {
		client.sendMessage(":server 332 " + client.getNickname() + ": the topic of #" + \
			channel->getName() + " is " + channel->getTopic() + "\r\n");
	}
	//invia messaggio 333(RPL_TOPICWHOTIME)
	client.sendMessage(":server 332 " + client.getNickname() + ": topic last changed by " + \
		channel->getTopicCreator() + " on " + channel->getTopicTime() + "\r\n");
}

//set o mostra topic di canale
void cmd_topic (Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {
	//prima cosa da controllare
	if (params.empty()) {
		//invia messaggio 461 (ERR_NEEDMOREPARAMS)
		client.sendMessage("461 " + client.getNickname() + ": not enough parameters\r\n");
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

	// else if (params.size() == 1) {
	// 	giveTopic(server, client, params, trailing);
	// }

	// Non serve il controllo: dobbiamo controllare trailing, non params
	// else if (params.size() > 1) {
	// 		changeTopic(server, client, params, trailing); 
	// }
}
