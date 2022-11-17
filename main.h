#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# define BUFF_SIZE 1

void _puts(char *str);
int _strcmp(char *s1, char *s2);
void hsh_execute(char **args);
int hsh_launch(char **args);
int _putchar(int c);
void hsh_shell(void);
char **hsh_split_line(char *line);
char *hsh_read_line(void);
int get_next_line(int fd, char **line);
void _strdel(char **as);
char *_strdup(char *str);
char *_strjoin(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strnew(size_t size);
char *_strsub(char *s, unsigned int start, size_t len);
int _strlen(char *s);
char *_strchr(char *s, char c);
int _strlen(char *s);

#endif
