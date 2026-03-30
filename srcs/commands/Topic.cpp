//LEO

#include "../../include/Server.hpp"
#include "../../include/Client.hpp"
#include "../../include/Commands.hpp"

void cmd_topic (Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {

	(void) server;
	(void) client;
	(void) params;
	(void) trailing;

	//set o mostra topic di canale
	
	//1.Check se canale esiste (params)
	//2. Se c'e +t (params) 
	// - check rights (isOPerator())
	// - channel->setTopic()
	//- send nuova topica tutti (broadcast())
	
	//3. Se non'ce +t
	// inviare il messagio client->sendMessage()
	//(check 6.REPLIES RFC + numetic replies in 4.2.4 Topic)
}
