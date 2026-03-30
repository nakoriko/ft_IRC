//LEO

#include "../../include/Server.hpp"
#include "../../include/Client.hpp"
#include "../../include/Commands.hpp"

//cambia i modi di channel (bools in private members of Channel.hpp)

void cmd_mode (Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {
	(void) server;
	(void) client; 
	(void) params;
	(void) trailing; 
	//1. Check se canale (params) esiste
	//2. Check if if client e' un operatore (isOperator)
	//3. interpretare la stringa con i modes(possono essere piu di uno)
	//5. Realizzare i modes:
		//  +i/-i  - setIviteOnly()
		//  +t / -t - set TOpicRestricted()
		//  +k / -k - setKey()
		//  +o/-o - addOperator()
		//  +l / -l setUserLimit()
	//6. Iniiare mode (channel->broadcast())
}