/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:33:54 by nakoriko          #+#    #+#             */
/*   Updated: 2026/03/31 19:26:52 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NAT
#include "../../include/Server.hpp"
#include "../../include/Client.hpp"
#include "../../include/Commands.hpp"

//disconettersi dal server
void cmd_quit (Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {
	(void) server;
	(void) client;
	(void) params;
	(void) trailing;

//1. A tuttti i channels ...->broadcast() che member ha fattuo QUIT - quando saranno pronti channels

	// std::string msg = "Quit";
	//if(!trailing.emty())
	//msg = trailing;


//2.Server fa removeMember() da tuttii i channels - quando saranno pronti i channels
	//Server chiude socket e cancella ojectto di client
	// server.removeClient(client.getFd()); //<- questo metodo ha bisogna di Channel
}