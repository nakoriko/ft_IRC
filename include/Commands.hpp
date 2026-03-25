/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:40:10 by nakoriko          #+#    #+#             */
/*   Updated: 2026/03/25 19:07:00 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_HPP
#define COMMANDS_HPP

class Server;
class Client;

//NAT (basic server commands)
//PASS, NICK, USER, JOIN, PRIVMSG, PART, QUIT, PING

//LEO (operator commands)
// KICK, INVITE, TOPIC, MODE (5 modes with +/-flags)



//subject: You must be able to authenticate, set a nickname, a username, 
//join a channel,send and receive private messages using your reference client 
//---->commands from RFC 1459 (OFFICIAL IRC server)

//Basic commands (regular user can do) 
// PASS - authentication
// NICK - set a nickName
// USER - set a username
// JOIN - join a channel;
// PRIVMSG - send and receive private message to channel or another client;

//Operator commands FROM SUBJECTS (just operator of channel can do) - LEO ()

//KICK  - cancel user from channel
//INVITE - invite user to channel
//TOPIC - change/read channel topic
//MODE - change channel modes(i, t, k,o,l)

//OTHER COMMANDS (basic ones) - NAT o LEO
// PART - logout of channel
// QUIT - logout of server(leave all channels)
//PING (+PONG?) - check the connection between client and server


#endif