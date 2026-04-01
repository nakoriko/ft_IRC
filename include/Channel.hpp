
//For Alessandro: all this stuff is a functional part of commands (see commands.hpp - this part for NAT and LEO)
// We have 3 category of users: regular members, operators (members who can do more, to execute some of commands) 
//and that ones who was invited

#ifndef CHANNEL_HPP
#define CHANNEL_HPP
#include <string>
#include <set>
#include <map>
#include <ctime>
#include "Client.hpp"

class Channel {
private:
	std::string _name;
	std::string _topic; //command TOPIC
	std::string _topic_creator;
	std::time_t  _topic_time;

	//Modes from subject:
	bool _invite_only; // mode i: invite-only channel
	bool _top_restricted; //mode t: just operator can change TOPIC
	std::string _key; // mode k: channel password
	int _user_limit; //mode l: limit of clients
	
	//"Databases":
	std::map<std::string, Client*> _members; //needs for JOIN, PART,KICK,QUIT, PRIVMSG
	std::map<std::string, Client*> _operators; //needs to check operator rights for KICK, INVITE, TOPIC, MODE
	std::set<std::string> _invited; // to keep nicknames. Needs for INVTE, JOIN (if mode +i);



public:
	Channel(const std::string &name);//creates channel with name


	//MEMBERS (for JOIN, PART, KICK, OUT)
	void addMember(Client *client);//agiungere to channel
	void removeMember(Client *client); //from channel (tutti elenci)
	bool isMember(Client *client) const; //check se presente dentro _members

	//OPERATORS(need to check the rights for commands and for MODE +o / -o)
	void addOperator(Client *client);
	void removeOperator(Client *client); 
	bool isOperator(Client *client) const;

	//INVITES (needs for INVITe and Join if mode +i)
	void addInvited(const std::string &nickname);
	bool isInvited(const std::string &nickname) const;

	//BROADCAST send message to all members of channel
	void broadcast(const std::string &message, Client *exlude = NULL); //+a parte  cliente appena aggiunto (Join.cpp n8.)

	//NICK
	void updateNick(const std::string &old_nick, const std::string & new_nick);
	
	//TOPIC
	void setTopic(const std::string &topic, Client *creator);
	const std::string &getTopic()const;
	const std::string getTopicCreator();
	const std::string getTopicTime();// long timestamp convertito in string

	//MODES
	//-i/+i
	void setInviteOnly(bool value);
	bool isInviteOnly() const;

	//+t /-t
	void setTopicRestricted(bool value);
	bool isTopicRestricted() const;

	//+k / -k
	void setKey(const std::string &key);
	bool checkKey(const std::string &key) const;
	const std::string getKey() const;

	//+l/-l
	void setUserLimit(int limit);
	bool canJoin() const;
	int getUserLimit() const;
	
	
	//GETTERS
	const std::string &getName() const;
	const std::map<std::string, Client*> &getMembers() const;
	const std::map<std::string, Client *> &getOperators() const;
};


#endif