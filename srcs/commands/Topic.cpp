//LEO

#include "../../include/Server.hpp"
#include "../../include/Client.hpp"
#include "../../include/Commands.hpp"

//set o mostra topic di canale
void cmd_topic (Server &server, Client &client, std::vector<std::string> params, std::string trailing) {
	Channel *channel = server.getChannel(params[0]);

	if (params.empty()) {
		//invia messaggio 461 (ERR_NEEDMOREPARAMS)
		client.sendMessage("461 " + client.getNickname() + ": not enough parameters\r\n");
	}
	else if (channel->isMember(&client) == false) {
		client.sendMessage("442 " + client.getNickname() + ": not a member of channel #" + channel->getName() + "\r\n");;
	}
	else if (channel->isTopicRestricted() == true && \
			channel->isOperator(&client) == false) {
		//invia messaggio 482 (ERR_CHANOPRIVSNEEDED)
		client.sendMessage("482 " + client.getNickname() + ": operator privileges needed\r\n");
	}
	else if (params.size() == 1) {
		if (channel->getTopic() == "") {
			//invia messaggio 331(RPL_NOTOPIC)
			client.sendMessage(":server 331 " + client.getNickname() + ": the channel #" + channel->getName() + " has no topic\r\n");
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
	else if (params.size() > 1) {
		//cambia topic
		channel->setTopic(trailing);
		//aggiorna nome dell'user e data della modifica
		//..
		if (channel->getTopic() == "") {
			//invia messaggio 331(RPL_NOTOPIC)
			client.sendMessage(":server 331 " + client.getNickname() + ": the channel #" + channel->getName() + " has no topic\r\n");
		}
		else {
			client.sendMessage(":server 332 " + client.getNickname() + ": the topic of #" + \
				channel->getName() + " is " + channel->getTopic() + "\r\n");
		}
		//invia messaggio 333(RPL_TOPICWHOTIME)
		client.sendMessage(":server 332 " + client.getNickname() + ": topic last changed by " + \
			channel->getTopicCreator() + " on " + channel->getTopicTime() + "\r\n");
	}
}
