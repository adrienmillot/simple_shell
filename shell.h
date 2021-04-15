#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define ENV_SEPARATOR "="
#define ESCAPE_SEPARATOR "#"
#define PATH_SEPARATOR ":"
#define SEPARATORS " \t\r\a\v\n"
#define PROMPT "$ "

/**
 * struct environment_s - environment variable
 *
 * @name: environment name
 * @value: environment value
 * @next: points to the next node
 */
typedef struct environment_s
{
	char *name;  /* ex: PATH */
	char *value; /* ex: /bin:/usr/bin */
	char *global;
	struct environment_s *next;
} environment_t;

/**
 * struct appData_s - data variable
 *
 * @arguments: argument's array
 * @buffer: buffer
 * @command: command name
 */
typedef struct appData_s
{
	char **arguments;
	char *buffer;
	char *commandName;
	char **history;
} appData_t;

/**
 * struct customCommand_s - struct conversion to function
 *
 * @command: flag string
 * @func: pointer to func
 */
typedef struct customCommand_s
{
	char *commandName;
	void (*func)(appData_t *);
} customCommand_t;

environment_t *_addEnvNodeEnd(
	environment_t **prmHeadNode,
	char *prmGlobal
);
int _atoi(char *prmString);
void *_calloc(unsigned int prmNumber, unsigned int prmSize);
void _cdHelp(void);
void _changeDirectory(appData_t *prmData);
void _changeToAnyDirectory(appData_t *prmData, char *prmCurrentDirectory);
void _changeToHomeDirectory(char *prmCurrentDirectory);
void _changeToPreviousDirectory(char *prmCurrentDirectory);
environment_t *_createEnvNode(char *prmGlobal);
void _ctrlC(int prmSignal);
void _defaultHelp(char *prmCommand);
void _prompt(void);
void _env(appData_t *prmData);
void _envHelp(void);
void _execCommand(appData_t *prmData);
void _exitStatus(appData_t *prmData);
void _exitHelp(void);
void _freeAppData(appData_t *prmData);
void _freeCharDoublePointer(char **prmPtr);
void _freeEnvList(environment_t *prmHeadNode);
char *_generateAbsolutePath(environment_t *prmPaths, char *prmCommandName);
char *_getenv(char *prmName);
char *_getenvname(char *prmVariable);
char *_getenvvalue(char *prmVariable);
environment_t *_getEnvNodeAtIndex(
	environment_t *prmHead,
	unsigned int prmIndex
);
environment_t *_getLastEnvNode(environment_t *prmHeadNode);
char *_getline();
char *_getword(char *prmGlobal, int prmOffset, int prmSize);
void _help(appData_t *prmData);
void _helpHelp(void);
int _inArray(char prmChar, char *prmArray);
int _isdigit(char prmChar);
char *_memcpy(char *prmDest, char *prmSrc, unsigned int prmLimit);
char *_memset(char *prmString, char prmCharacter, unsigned int prmLimit);
environment_t *_parsingPathEnvironment();
int _putchar(char prmChar);
int _puts(char *prmStr);
void *_realloc(void *prmPtr, unsigned int prmOldSize, unsigned int prmNewSize);
void _setenv(char *prmName, char *prmValue, int prmOverwrite);
void _setenvHelp(void);
void _setEnvironment(appData_t *prmData);
char *_strcat(char *prmDest, char *prmSrc);
int _strcmp(char *prmString1, char *prmString2);
char *_strconcat(char *prmString1, char *prmString2);
unsigned int _strcspn(char *prmString, char *prmDeny);
char *_strdup(char *prmString);
int _strlen(char *prmStr);
char *_strstr(char *prmHaystack, char *prmNeedle, int prmBegin);
char **_strtow(char *prmString, char *prmSeparators, char *prmEscapeSeparators);
void _unsetenv(char *prmName);
void _unsetenvHelp(void);
void _unsetEnvironment(appData_t *prmData);
char *_which(appData_t *prmData);
int _wordNumber(char *prmString, char *prmSeparators);

#endif
