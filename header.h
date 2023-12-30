#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

extern char **environ;
char **_split(char *str, char *delim);
char *_getline(void);

#endif
