/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:33:45 by nakoriko          #+#    #+#             */
/*   Updated: 2026/04/01 19:10:11 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NAT
#include "../../include/Server.hpp"
#include "../../include/Client.hpp"
#include "../../include/Commands.hpp"

//exit from channel
void cmd_part (Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {
	(void) server;
	(void) client;
	(void) params;
	(void) trailing;
	
	//Client abbandona channel
	if(params.empty()) {
		client.sendMessage("461 " + client.getNickname() + " PART :Not enough parameters\n\r");
		return;
	}
	std::string channel_name = params[0];
	std::string msg = "Leaving";
	if(!trailing.empty())
		msg = trailing;
	
	Channel *channel = server.getChannel(channel_name);
	if(!channel) {
		client.sendMessage("403 " + client.getNickname() + " " + channel_name + " :No such channel\r\n");
		return;
	}
	if(!channel->isMember(&client)) {
		client.sendMessage("442 " + client.getNickname() + " " + channel_name + " :You're not on that channel\n\r");
		return;
	}
	// Server fa il channel->broadcast(); (dal trailing)
	std::string channel_msg = ":" + client.getNickname() + " PART " + channel_name + " :" + msg + "\r\n";
	channel->broadcast(channel_msg);
	channel->removeMember(&client);

	// Server lo elimina dal _channels
	// se il canale rimasto vuoto - eliminare il canale
	if(channel->getMembers().empty()) {
		server.removeChannel(channel_name);
		delete channel;
	}
}