#ifndef SHELL_H
#define SHELL_H

#define SEPARATORS " \t\r\a\v\n"
#define PATH_SEPARATOR ":"
#define ENV_SEPARATOR "="
#define PROMPT "$ "
#define BUFFER_SIZE 256

extern char **environ;

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

/**
 * Struct environment - environment variable
 *
 * @name: environment name
 * @value: environment value
 * @next: points to the next node
 */
typedef struct environment_s
{
	char *name;  /* ex: PATH */
	char *value; /* ex: /bin:/usr/bin */
	struct environment_s *next;
} environment_t;

/**
 * Struct data - data variable
 *
 * @arguments: argument's array
 * @buffer: buffer
 * @command: command name
 */
typedef struct data_s
{
	char **arguments;
	char *buffer;
	char *command;
} data_t;

/**
 * struct flags_printf - struct conversion to function
 * @c: flag string
 * @f: pointer to func
 */
typedef struct customCommand_s
{
	char *command;
	void (*func)(data_t *);
} customCommand_t;

/**
 * Strings
 */
int _putchar(char c);
int _puts(char *str);
int _strlen(char *s);
char *_str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
char *_strstr(char *haystack, char *needle, int prmBegin);
char *_strdup(char *str);
unsigned int _strspn(char *s, char *accept);
char *_strchr(char *s, char c);
char *_strncat(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
int _inArray(char c, char *s);

/**
 * Numbers
 */
int isNumber(char c);
int _atoi(char *s);

/**
 * Build
 */
/*int _isBuildIn(char *prmCommandName, char **prmArguments, char *prmBuffer);*/
void (*_isBuildIn(char *prmCommand))(data_t *);
data_t *_setData(char *prmCommand, char **prmArguments, char *prmBuffer);
void _execCmd(char *prmArguments[]);

/**
 * Base
 */
char *_getenv(char *prmEnvironmentName);
char *_which(char *prmCommandName);
char *_generateAbsolutePath(environment_t *prmPaths, char *prmCommandName);

/**
 * Linked list
 */
environment_t *_createNode(char *prmName, char *prmValue);
environment_t *_getLastNode(environment_t *prmHeadNode);
environment_t *_addNodeEnd(environment_t **prmHead, char *prmName, char *prmValue);
void _freeList(environment_t *head);
size_t _printLinkedList(const environment_t *h);

/**
 * Parsing
 */
void _parsingString(char *prmString, char *prmSeparator, char *prmArgv[]);
void _parsingArguments(char *prmParametersLine, char *prmArgv[]);
environment_t *_parsingEnvironment(char *prmEnvironmentName);

/**
 * Memory
 */
void _freeDoublePointer(char **prmPtr);
void _freeData(data_t *prmData);

/**
 * strtow
 */
int _characterNumber(char *prmString, char *prmSeparators);
int _wordNumber(char *prmString, char *prmSeparators);
char *_getWord(char *prmGlobal, int prmOffset, int prmSize);
char **_strtow(char *prmString, char *prmSeparators);

/**
 * getline
 */
char *_getline();

/**
 * env
 */
void _env(data_t *prmData);

/**
 * exit
 */
void _exitStatus(data_t *prmData);
#endif
