/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:33:54 by nakoriko          #+#    #+#             */
/*   Updated: 2026/04/01 18:50:29 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NAT
#include "../../include/Server.hpp"
#include "../../include/Client.hpp"
#include "../../include/Commands.hpp"

//disconettersi dal server
void cmd_quit (Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {
	(void) params;

//1. A tuttti i channels ...->broadcast() che member ha fattuo QUIT - quando saranno pronti channels

	std::string msg = "Quit";
	if(!trailing.empty())
		msg = trailing;


//2.Server fa removeMember() da tuttii i channels - quando saranno pronti i channels
std::map<std::string, Channel*> channels = server.getAllChannels(); //scrivere getter
for (std::map<std::string, Channel*>::iterator it = channels.begin(); it != channels.end(); it++) {
	Channel *channel = it->second;
	if(channel->isMember(&client)) {
		channel->broadcast(":" + client.getNickname() + " QUIT :" + msg + "\r\n");
		channel->removeMember(&client);
	}
}
//Server chiude socket e cancella ojectto di client
// server.removeClient(client.getFd()); //<- questo metodo ha bisogna di Channel
	server.removeClient(client.getFd());
}