#include <Server.hpp>

int main(int argc, char** argv)
{
	int port = check_input(argc, argv);
	Server server(port, argv[2]);

	server.start();
	return 0;
}
