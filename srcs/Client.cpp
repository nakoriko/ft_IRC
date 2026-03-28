/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:51:18 by nakoriko          #+#    #+#             */
/*   Updated: 2026/03/28 10:10:50 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"


Client::Client(int fd) : _fd(fd), _registered(false), _pass_checked(false) {

};

Client::~Client() {

}

void Client::setNickname(std::string &nickname) {
	(void) nickname;
}

void Client:: setUsername(std::string &username) {
	(void) username;
}

void Client::setPassChecked(bool value) {
	(void) value;
}

void Client::setRegistered(bool value) {
	(void) value;
}


std::string Client::getNickname() const{
	return _nickname;
}

std::string Client::getUsername() const {
	return _username;
}

int Client::getFd() const {
	return _fd;
}

void Client::receiveMessage(std::string &row_msg) {
	(void) row_msg;
}

void Client::parseMessages() {

}

bool Client::hasPendingMessage() {
	return false;
}

void Client::extractFromPending() {

}

void Client::sendMessage(std::string &msg) {
	(void) msg;
}

bool Client::hasMessageToSend() {
	return false;
}

void Client::extractToSend () {
	
}