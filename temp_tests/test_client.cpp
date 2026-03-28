
#include <iostream>
#include "../include/Client.hpp"
#include "../include/CommandHandler.hpp"


int main() {
	Client client(7);

	std::string data = "NICK alice\r\nJOIN #general\r\n";
	client.receiveMessage(data);
	client.parseMessages();

	std::cout << "Client has " << client.hasPendingMessage() << std::endl;
	while(client.hasPendingMessage()) {
		std::string msg = client.getNextMessage();
		std::cout << "Message: " << msg << std::endl;
	}
	return 0;
}