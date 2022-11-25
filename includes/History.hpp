#ifndef FT_IRC_HISTORY_HPP
#define FT_IRC_HISTORY_HPP

#include "utils.hpp"

class UserInfo;

class History
{
private:
	History(const History &copy);
	History &operator=(const History &copy);


public:
	std::vector<UserInfo*> history_list;
	History();
	~History();

	void add_user(const Client &member);
	const std::vector<const UserInfo*> get_history(const std::string &nickname) const;
};

#endif
