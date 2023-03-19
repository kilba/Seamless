#include <gui/functionalities.h>
#include <stdio.h>

void guiInput(int input_field, int max_len, char *out) {
    if(input_field == INPUTFIELD_CMD) {
	fgets(out, max_len, stdin);
	return;
    }
}
