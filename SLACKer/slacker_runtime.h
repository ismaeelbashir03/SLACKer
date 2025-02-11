#ifndef SLACKER_H
#define SLACKER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static void *(*real_malloc)(size_t) = malloc;
static int (*real_printf)(const char *, ...) = printf;

void infer(const char* prompt, char* output, size_t output_size);
int getSize(const char* prompt);

void* slacker_malloc(const char *prompt);
void slacker_printf(const char *prompt);
int prompt_condition(const char *prompt);

#define malloc(prompt) slacker_malloc(prompt)
#define printf(prompt) slacker_printf(prompt)
#define condition(prompt) prompt_condition(prompt)
#endif
