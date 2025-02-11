#include "slacker_runtime.h"
#include <stdio.h>
#include <string.h>

/*
----------------------------
|     helper functions     |
----------------------------
*/
void infer(const char *prompt, char *output, size_t output_size) {
    system("python SLACKer/python/download_llm.py > /dev/null 2>&1");
    char command[512 + strlen(prompt)];
    snprintf(command, sizeof(command), "python SLACKer/python/infer.py \"%s Your Response:\" > /dev/null 2>&1", prompt);
    system(command);

    FILE *fp = fopen("SLACKer/tmp/response.txt", "r");
    if (fp == NULL) {
        real_printf("Error opening file\n");
        return;
    }
    fgets(output, output_size, fp);
    fclose(fp);
}

int getSize(const char *prompt) {
    char response[256];
    char *sys_prompt = "System: Give the number of bytes required for a malloc() from the users specifications. Respond only with a single number (representing the number of bytes) and no other characters. User:";
    char full_prompt[strlen(sys_prompt)+strlen(prompt)+2];
    strcpy(full_prompt, sys_prompt);
    strcat(full_prompt, prompt);
    infer(full_prompt, response, 256);
    // real_printf("Slacker response for malloc: %s\n", response);
    int size = atoi(response);
    if (size <= 0) size = 64;
    return size;
}

void getprintfString(const char *prompt, char response[256]) {
    char *sys_prompt = "System: Generate a pretty print output string for a printf char* for the user (Dont include the speech marks). ONLY ANSWER with the string and nothing else. User:";
    char full_prompt[strlen(sys_prompt)+strlen(prompt)+2];
    strcpy(full_prompt, sys_prompt);
    strcat(full_prompt, prompt);
    infer(full_prompt, response, 256);
    // real_printf("Slacker response for printf: %s\n", response);
}

/*
----------------------------
|     malloc  function     |
----------------------------
*/
void* slacker_malloc(const char *prompt) {
    int size = getSize(prompt);
    // real_printf("Slacker: Allocating %d bytes based on prompt.\n", size);
    return real_malloc(size);
}

/*
----------------------------
|     printf  function     |
----------------------------
*/
void slacker_printf(const char *prompt) {
    char response[256];
    getprintfString(prompt, response);
    real_printf("%s\n", response);
}

/*
----------------------------
|     condition function    |
----------------------------
*/
int prompt_condition(const char *prompt) {
    char response[256];
    char *sys_prompt = "System: Evaluate whether the users input is true or false. Respond only with the numbers '1' or '0' representing true or false for a condition and no other characters. User:";
    char full_prompt[strlen(sys_prompt)+strlen(prompt)+2];
    strcpy(full_prompt, sys_prompt);
    strcat(full_prompt, prompt);
    infer(full_prompt, response, sizeof(response));
    // real_printf("Slacker response for condition: %s\n", response);
    return atoi(response);
}