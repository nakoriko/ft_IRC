/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:34:07 by nakoriko          #+#    #+#             */
/*   Updated: 2026/03/31 19:05:44 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NAT
#include "../../include/Server.hpp"
#include "../../include/Client.hpp"
#include "../../include/Commands.hpp"


// Check se conessione con client esiste
void cmd_ping (Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {
	(void) server;


//Client invia ping a Server e riceve pong ()
// PING puo essere senza params o con params 
if(params.empty()) {
	client.sendMessage("PONG\r\n");
	return ;
}

std::string msg = "PONG";
for(size_t i = 0; i < params.size(); i++) {
	msg = msg + " " + params[i];
}
if(!trailing.empty()) {
	msg = msg + " :" + trailing;
}
client.sendMessage(msg + "\r\n");

//ramo server->client da realizzare dentro  run(), ma non obbligatorio, visto che subject non lo chiede proprio
//se client non risposto  -server puo chiudere consession (eliminando da ovunque) - 

}