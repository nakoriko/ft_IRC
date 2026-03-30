/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:41:55 by nakoriko          #+#    #+#             */
/*   Updated: 2026/03/29 19:54:53 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDHANDLER_HPP
#define COMMANDHANDLER_HPP


#include <string>
#include <vector>
#include "../include/ParamValidator.hpp"

class Server;
class Client;

//1. IRC protocol 2.3 messages
//2. Serve per tenere il commando dopo parsing (i metodi per parsing ed execution, lo facciamo anche qui)
//e la struttura per il dopo parsing

struct ParsedCommand {
	std::string prefix;
	std::string command;
	std::vector<std::string> params;
	std::string trailing;
};

class CommandHandler {
	public:
		static std::string trim(const std::string &str);
		static ParsedCommand parse(const std::string &row);
		static bool isValidCommand(const ParsedCommand &cmd);
		static void execute(Server &server, Client &client, const std::string &raw);
};

#endif


//dispatcher - takes commands from messages, parse and execute, using commands.hpp methods