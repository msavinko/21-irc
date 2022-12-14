#ifndef FT_IRC_SERVER_HPP
#define FT_IRC_SERVER_HPP

#include "utils.hpp"

#define BACK_LOG 20

class Server
{
	private:
		typedef int (Server::*irc_methods)(const Message &, Client &);

		int port;
		std::string password;
		int timeout;
		std::vector<Client*> members;
		std::map<std::string, std::string> operators;
		std::vector<std::string> motd;
		static bool is_working;
		int socket_fd;
		std::string info;
		int client_fd;
		std::map<std::string, irc_methods> irc_cmds;
		sockaddr_in addr;
		socklen_t addr_len;
		char* host_ip;
		std::map<std::string, Chat*> chats;
		History history;
		std::vector<struct pollfd> client_fds;

		Server();
		Server(const Server& other);
		Server& operator=(const Server& other);
		void socket_init();
		void bind_socket();
		void listen_socket();
		void accept_socket();
		void poll_socket();
		void connect_members();
		void break_connections();
		void delete_empty_chats();
		static void sig_process(int sig_code);
		bool is_exist_member(const std::string& nick) const;
		void notify(Client& member, const std::string& msg);
		int connect_member(Client& member);
		std::queue<std::string>	fill(const std::string &str, char sep);
		bool is_exist_chat(const std::string& name) const;
		int handle_flags(const Message &msg, Client& member);
		bool is_correct_chat(const std::string& name);
		int connect_to_chat(const Client& member, const std::string& name, const std::string& password);
		void invite_to_chat(const Client& member, const std::string& nick, const std::string& chat_name);
		void init_cmds();
		void parse_motd();
	public:
		void start();
		Server(int Port, std::string Password);
		~Server();
		int nick_cmd(const Message &msg, Client &member);
		int oper_cmd(const Message &msg, Client &member);
		int privmsg_cmd(const Message &msg, Client &member);
		int away_cmd(const Message &msg, Client &member);
		int ping_cmd(const Message &msg, Client &member);
		int notice_cmd(const Message &msg, Client &member);
		int pass_cmd(const Message &msg, Client &member);
		int info_cmd(const Message &msg, Client &member);
		int who_cmd(const Message &msg, Client &member);
		int whois_cmd(const Message &msg, Client &member);
		int handle_mes(Client& member);
		int whowas_cmd(const Message &msg, Client &member);
		int user_cmd(const Message &msg, Client &member);
		int quit_cmd(const Message &msg, Client &member);
		int time_cmd(const Message &msg, Client &member);
		int admin_cmd(const Message &msg, Client &member);
		int rehash_cmd(const Message &msg, Client &member);
		int mode_cmd(const Message &msg, Client &member);
		int version_cmd(const Message &msg, Client &member);
		int join_cmd(const Message &msg, Client &member);
		int invite_cmd(const Message &msg, Client &member);
		int kick_cmd(const Message &msg, Client &member);
		int part_cmd(const Message &msg, Client &member);
		int names_cmd(const Message &msg, Client &member);
		int list_cmd(const Message &msg, Client &member);
		int wallops_cmd(const Message &msg, Client &member);
		int pong_cmd(const Message &msg, Client &member);
		int ison_cmd(const Message &msg, Client &member);
		int topic_cmd(const Message &msg, Client &member);
		int userhost_cmd(const Message &msg, Client &member);
		int kill_cmd(const Message &msg, Client &member);
		int restart_cmd(const Message &msg, Client &member);
		void send_motd(const Client& member) const;
		Client* get_member(const std::string& nick);
};

#endif
