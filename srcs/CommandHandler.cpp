/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:41:09 by nakoriko          #+#    #+#             */
/*   Updated: 2026/03/28 12:26:15 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/CommandHandler.hpp"

ParsedCommand CommandHandler::parse(const std::string &row) {
	(void) row;
	ParsedCommand result;
	return result;
}

void CommandHandler::execute(Server &server, Client &client, const std::string &raw) {
	(void) server;
	(void) client;
	(void) raw;
}

