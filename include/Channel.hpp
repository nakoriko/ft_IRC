
//For Alessandro: all this stuff is a functional part of commands (see commands.hpp - this part for NAT and LEO)
// We have 3 category of users: regular members, operators (members who can do more, to execute some of commands) 
//and that ones who was invited

#ifndef CHANNEL_HPP
#define CHANNEL_HPP
#include <string>
#include <set>
#include <map>
#include "Client.hpp"

class Channel {
private:
	std::string _name;
	std::string _topic; //command TOPIC

	//"Databases":
	std::map<std::string, Client*> _members; //needs for JOIN, PART,KICK,QUIT, PRIVMSG
	std::map<std::string, Client*> _operators; //needs to check operator rights for KICK, INVITE, TOPIC, MODE
	std::set<std::string> _invited; // to keep nicknames. Needs for INVTE, JOIN (if mode +i);


	//Modes from subject:
	bool _invite_only; // mode i: invite-only channel
	bool _top_restricted; //mode t: just operator can change TOPIC
	std::string _key; // mode k: channel password
	int _user_limit; //mode l: limit of clients

public:
	Channel(const std::string &name);//creates channel with name

	//Actions with members (for JOIN, PART, KICK, OUT)
	void addMember(Client *client);
	void removeMember(Client *client);
	bool isMember(Client *client);

	//Actions with Operators (need to check the rights for commands and for MODE +o / -o)
	void addOperator(Client *client);
	void removeOperator(Client *client);
	bool isOperator(Client *client) const;

	//Invites control (needs for INVITe and Join if mode +i)
	void addInvited(std::string &nickname);
	bool isInvited(std::string &nickname);

	//send message to all members of channel
	void broadcast(const std::string *message);

	//Getters for commands
	//......

	//Setter and bool checkerss for Modes:
	// i - invite only
	// t - topic restricted to operators
	// k - channel key
	// l - user limits
};


#endif