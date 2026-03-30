//LEO

#include "../../include/Server.hpp"
#include "../../include/Client.hpp"
#include "../../include/Commands.hpp"

//invite client to channel
void cmd_invite (Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {
	(void) server;
	(void) client;
	(void) params;
	(void) trailing;


	//1. Controllare che il canale passato (dentro params)
	//2. Trovare o creare il canale (dentro channels - Alessando)
	//3. Controllare i regimi di canale:
	//	 (+i invited only, 
	//		+k - il password deve corrispondere
	//		+l - quantita d membri dentro canale permette di aggiungere ancora uno)
	//4.Aggiungere nuovo membro dentro canale (channel->addMember())
	//5. Se canale e nuovo - in teoria il singolo membro deve essere  operatore (channel._operatprs) - non sono sicura pero'
	//6. Inviare la conferma al client (сlient.senMessage())
	//7. Ogni messaggio dal client al channel devono essere inviati a tutti i membri di channel ()
	//	(la richiesta JOIN - e' un messsagio, allora bisogna di mandare notifica a tuttti)
	//	 broadcast();
	
}