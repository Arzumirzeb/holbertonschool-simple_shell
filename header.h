#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

char **_split(char *str, char *delim);
int _getline(char **line);
void free_twod_array(char **arr);

#endif
