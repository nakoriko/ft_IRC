//LEO

#include "../../include/Server.hpp"
#include "../../include/Client.hpp"
#include "../../include/Commands.hpp"

//set o mostra topic di canale
void cmd_topic (Server &server, Client &client, std::vector<std::string> params, std::string trailing) {

	//(void) server;
	//(void) client;
	//(void) params;
	(void) trailing;


	if (params.size() < 1) {
		//invia messaggio 461 (ERR_NEEDMOREPARAMS)
		client.sendMessage("461 " + client.getNickname() + ": not enough parameters\r\n");
	}
	if (server.getChannel(params[0])->isRestricted() == true && \
			server.getChannel(params[0])->isOperator(&client) == false) {
		//invia messaggio 482 (ERR_CHANOPRIVSNEEDED)
		client.sendMessage("482 " + client.getNickname() + ": operator privileges needed\r\n");
	}
	if (params.size() == 1) {
		if (server.getChannel(params[0])->getTopic() == "") {
			//invia messaggio 331(RPL_NOTOPIC)
			client.sendMessage(":server 331 " + client.getNickname() + ": the channel has no topic\r\n");
		}
		else {
			//invia messaggio 332(RPL_TOPIC)
			client.sendMessage(":server 332 " + client.getNickname() + ": the topic is " + \
				server.getChannel(params[0])->getTopic() + "\r\n");
			//invia messaggio 333(RPL_TOPICWHOTIME to let them know who set the topic (<nick>) and when they set it (<setat> is a unix timestamp)
			client.sendMessage(":server 332 " + client.getNickname() + ": topic last changed by " + \
				server.getChannel(params[0])->getTopicCreator() + " on " + server.getChannel(params[0])->getTopicTime() + "\r\n");
		}
	}
	else if (params.size() > 1) {
		//cambia topic
		server.getChannel(params[0])->getTopic()  = params[1];
		//aggiorna nome dell'user e data della modifica
		//.. 
		client.sendMessage(":server 332 " + client.getNickname() + "the topic is " + \ 
			server.getChannel(params[0])->getTopic() + "\r\n");
		//invia messaggio 333(RPL_TOPICWHOTIME)
		//...
	}
}
