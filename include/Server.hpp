/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:35:58 by nakoriko          #+#    #+#             */
/*   Updated: 2026/04/01 17:05:39 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <map>
#include <vector>

#include "Client.hpp"
#include "Channel.hpp"

// - Creates and run server with databases of clients and channels ()all clients/channels/commands/ actions are here). 
// - Stay active until will be stopped(loop);


class Server {
private:
	int _port;
	std::string _password;
	int _server_fd; //get due socket()
	std::map<int, Client*> _clients; //database of pointers to clients +   their fd
	std::map<std::string, Channel*> _channels; //dtaabase of channels with their names
	bool _running; //for stop()
	std::vector<struct pollfd> _pollfds; // vector to keep structures of fd and its parameters 
	

public:
	Server(int port, std::string password);
	~Server();
	void run();  //core. run loop until server will stopped (by signal);
	// void stop();// check if run -> stop
	void acceptNewClient();
	void addChannel(const std::string &name, Channel *channel);
	void removeClient(int fd);
	void handleClientRead(int fd);
	void handleClientWrite(int fd);
	Client *getClient(const std::string &nick); //to find client by his name in map
	Channel *getChannel(const std::string &name);
	std::string getPassword() const;
	bool isNickTaken(const std::string &nick);
	void checkRegistration(Client &client);
	
};

#endif