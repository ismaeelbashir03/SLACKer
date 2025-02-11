#include <stdlib.h>
#include <stdio.h>
#include "SLACKer/slacker_runtime.h"

int main() {
    printf("give a friendly short welcome message to the user of my program.");

    int* list = (int*)malloc("bytes for a list of 4 integers");
    for (int i = 0; i < 4; i++) {
        list[i] = i;
        char msg[100];
        snprintf(msg, sizeof(msg), "give the roman numeral for the number: %d", i);
        printf(msg);
    }

    if("today is tuesday") {
        printf("tell the user today is tuesday");
    } else {
        printf("tell the user today is not tuesday");
    }

    printf("give a goodbye message to the user :(");
    return 0;
}
