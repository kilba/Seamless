#include <auth/auth.h>
#include <conn.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    // Debugging
    char *type = "";
    if(argc > 1)
	type = argv[1];

    if(strcmp(type, "CreateAccount") == 0) createAccount();

    return 0;
}
