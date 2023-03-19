#include <auth/auth.h>
#include <stdio.h>
#include <conn.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // Debugging
    char *type = "";
    if(argc > 1)
	type = argv[1];

    if(strcmp(type, "CreateAccount") == 0) createAccount();
    if(strcmp(type, "TcpTest") == 0) tcpConnect();

    return 0;
}
