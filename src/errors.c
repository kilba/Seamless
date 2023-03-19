#include <qrcodegen.h>
#include <errors.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

void printQr(uint8_t *buf) {
    /* Print "____[ QR CODE ]____, based on qr code width" */
    int size = qrcodegen_getSize(buf);

    float underscore_len;
    underscore_len  = (float)size / 2.0 + 1.0;
    underscore_len -= sizeof("[ QR Code ]") / 2.0;
    underscore_len  = ceil(underscore_len);

    printf("\n  ");
    for(int i = 0; i < underscore_len; i++)
	printf("_");
    printf("[ QR CODE ]");
    for(int i = 0; i < underscore_len; i++)
	printf("_");
    printf("\n%s  ", NWHE);

    /* Print row of bottom halves */
    for(int i = 0; i < size+2; i++)
	printf("%c", QR_BOT);

    printf("%s\n", RES);

    /* Display QR Code */
    for (int y = 0; y < size; y+=2) {
	printf("  %s%s ", NWHEB, NGRY);

	for (int x = 0; x < size; x++) {
	    bool top = qrcodegen_getModule(buf, x, y + 0);
	    bool bot = qrcodegen_getModule(buf, x, y + 1);
	    
	    if(top && bot) {
		printf("%c", QR_FUL);
	    } else if(top) {
		printf("%c", QR_TOP);
	    } else if(bot) {
		printf("%c", QR_BOT);
	    } else {
		printf(" ");
	    }
	}
	printf(" %s\n", RES);
    }
    printf("\n");

}

void errorMessage(char *msg, ...) {
    printf("ERROR: ");

    va_list ptr;
    va_start(ptr, msg);
    vfprintf(stderr, msg, ptr);
    va_end(ptr);
}

int httpErrorHandle(HTTP http) {
    // Handle errors made while connecting to server
    if(http.conn_status < 0) {
	int err = WSAGetLastError();
	switch(err) {
	    case WSAECONNREFUSED: errorMessage("Connection refused, server might be down.\n"); break;
	    case WSAECONNRESET: errorMessage("Connection reset.\n"); break;
	    default: errorMessage("WSA Error %d\n", err); break;
	}
	return HTTP_ERROR;
    }

    // Handle errors the server have returned
    char code = http.body[0];

    if(code != '0') {
	printf("%s\n", http.body + 1);
	return HTTP_ERROR;
    }

    return 0;
}
