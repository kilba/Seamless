#ifndef ERRORS_H
#define ERRORS_H

#include <conn.h>
#include <stdint.h>

#define HTTP_ERROR 1

#define QR_FUL 219 
#define QR_BOT 220
#define QR_TOP 223

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define RES "\e[0m"

#define NBLU		"\x1b[38;2;105;120;237m"
#define NPUR		"\x1b[38;2;185;70;237m"
#define NGRN		"\x1b[38;2;105;160;125m"
#define NORA		"\x1b[38;2;250;120;100m"
#define NYEL		"\x1b[38;2;200;60;120m"
#define NWHEB		"\e[47m"
#define NWHE		"\e[1;37m"
#define NGRY		"\x1b[38;2;50;50;50m"

void errorMessage(char *msg, ...);
void printQr(uint8_t *buf);
int httpErrorHandle(HTTP http);

#endif /* ERRORS_H */
