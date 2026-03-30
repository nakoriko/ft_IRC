/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 17:20:45 by nakoriko          #+#    #+#             */
/*   Updated: 2026/03/30 08:25:10 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// g++ -Wall -Werror -Wextra -std=c++98 -Iinclude test_parsing.cpp ../srcs/CommandHandler.cpp -o parsing

#include "../include/CommandHandler.hpp"
#include <iostream>

int main () {
	std::cout << "===== Test 1. Full set =====" <<std::endl;
	std::string raw = ":blablbalba NICK alice : Ciao!";
	ParsedCommand cmd = CommandHandler::parse(raw);
	std::cout << "Parsed command:" << std::endl;
	std::cout << "Prefix: " << cmd.prefix << std::endl;
	std::cout << "Command: " << cmd.command << std::endl;
	std::cout << "Param: " << cmd.params[0] << std::endl;
	std::cout << "Trailing: " << cmd.trailing << std::endl;
	
	std::cout << "===== Test 2. without prfix  =====" <<std::endl;
	std::string new_raw = "JOIN channel noname :Messaggio per channel";
	ParsedCommand new_cmd = CommandHandler::parse(new_raw);

	std::cout << "Parsed command:" << std::endl;
	std::cout << "Prefix: " << new_cmd.prefix << std::endl;
	std::cout << "Command: " << new_cmd.command << std::endl;
	std::cout << "Param: " << new_cmd.params[0] << std::endl;
	std::cout << "Param: " << new_cmd.params[1] << std::endl;
	std::cout << "Trailing: " << new_cmd.trailing << std::endl;


	std::cout << "===== Test 3. spazi e tabs (valid))   =====" <<std::endl;
	std::string raw3 = ":  server  PING 	 channel  noname :   blablabla";
	ParsedCommand cmd3 = CommandHandler::parse(raw3);

	std::cout << "Parsed command:" << std::endl;
	std::cout << "Prefix: " << cmd3.prefix << std::endl;
	std::cout << "Command: " << cmd3.command << std::endl;
	std::cout << "Param: " << cmd3.params[0] << std::endl;
	std::cout << "Param: " << cmd3.params[1] << std::endl;
	std::cout << "Trailing: " << cmd3.trailing << std::endl;

	
	
	return 0;

}