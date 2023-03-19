#include <gui/functionalities.h>
#include <auth/auth.h>

#include <qrcodegen.h>
#include <errors.h>
#include <stdint.h>
#include <stdio.h>
#include <conn.h>
#include <net.h>

void generateQr(char *qr_buf) {
    uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];
    uint8_t qr[qrcodegen_BUFFER_LEN_MAX];

    bool ok = qrcodegen_encodeText(qr_buf,
	tempBuffer, qr, qrcodegen_Ecc_MEDIUM,
	qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX,
	qrcodegen_Mask_AUTO, true);

    if(!ok) {
	errorMessage("Failed to generate QR!");
	exit(1);
    }

    // Debug
    printQr(qr);
}

void loginAccount() {
}

void createAccount() {
    HTTP http;
    Header headers[] = {
	{ "Type", "Create" },
	{ "User", "Henry" },
	HEADER_END
    };
   
    // Step 1, get auth token
    http = get(NULL, headers);
    if(httpErrorHandle(http)) return;

    char auth[8];
    generateQr(http.body + 1);
    guiInput(INPUTFIELD_CMD, 8, auth);

    // Step 2, verify auth token, save login data to cookie
    http = get(auth, headers);
    if(httpErrorHandle(http)) return;
}
