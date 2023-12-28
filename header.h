#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

char **_split(char *str, char *delim);
<<<<<<< HEAD
int *_getline(void);
=======
int _getline(char **line);
void free_twod_array(char **arr);
>>>>>>> 0a7e3fddd7a82da4dd4d93f4ae641ecbe60f8203

#endif
