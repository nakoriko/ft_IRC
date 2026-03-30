/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:32:51 by nakoriko          #+#    #+#             */
/*   Updated: 2026/03/30 18:00:51 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NAT
#include "../../include/Server.hpp"
#include "../../include/Client.hpp"
#include "../../include/Commands.hpp"

//Set o change nickName of client

void cmd_nick (Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {
	(void) server;
	(void) client;
	(void) params;
	(void) trailing;

//1. Controllare che c'e il nick dentro params
//2. Check, che non e vuoto (parsing?)
//3. Check se disponibile (server.clients()), inviare un errore se si
//4. SetNickName() (se lo cambia)
//5. Inviar ela conferma (se lo cambiato + messagio per channels (se dentro channels))
//6. Check registrazione + username + nickname -> iviare welcome (RFC)


}