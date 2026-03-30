/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrivMsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:33:28 by nakoriko          #+#    #+#             */
/*   Updated: 2026/03/30 18:01:00 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NAT
#include "../../include/Server.hpp"
#include "../../include/Client.hpp"
#include "../../include/Commands.hpp"

//sending private messagis to client or channel


void cmd_privmsg (Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {
	(void) server;
	(void) client;
	(void) params;
	(void) trailing; // (message to send)
	//se msg per channe l -> channel->broadcast() escludendo il cliente stessso
	// se il cliente
		//client(target from params)->sendMesssage();
		// se cliente non esiste - error (RFC numeric)


}