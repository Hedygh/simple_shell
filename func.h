#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* malloc string */
char *_memset(char *s, char b, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
void free_array(char **array);
char **strtow(char *str);

#endif
