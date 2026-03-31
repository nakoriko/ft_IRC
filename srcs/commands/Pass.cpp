/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:32:48 by nakoriko          #+#    #+#             */
/*   Updated: 2026/03/31 17:42:23 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NAT
#include "../../include/Server.hpp"
#include "../../include/Client.hpp"
#include "../../include/Commands.hpp"


#include <iostream>


void cmd_pass (Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {

	(void) trailing;

//1. Controlla che il client ancora non registratro ()
	if(client.isRegistered()) {
		client.sendMessage("462 " + client.getNickname() + " :You may not reregister\r\n");
		return;
	}
//2. Controlla che password e satto inviato (presente in params)
	 if(params.empty()) {
		client.sendMessage("461 " + client.getNickname() + " PASS :Not enough parameters\r\n");
		return;
	 }

//3. Check se password corrisponde a password di server:
	 // se si - client.setPassChecked();
	 if(params[0] == server.getPassword()) {
		client.setPassChecked(true);
		server.checkRegistration(client); // se c'e il pass, nick e user - > inviare welcome message)
		// client.sendMessage(":server  " + client.getNickname() + " :Password accepted\r\n");

	} else {
		client.sendMessage("464 " + client.getNickname() + " :Password incorrect\r\n");
		// se no - error
	 }




	// std::cout << "Debug: PASS cmd call" << std::endl;
	// std::cout << " params size: " << params.size() << std::endl;
	// for(size_t i = 0; i < params.size(); i++) {
	// 	std::cout << "  param[" << i << "]: " << params[i] <<std::endl;
	// }
	// client.sendMessage(":server says: PASS received\r\n");
	// // std::cout << "Debug: response sent" << std::endl;
}