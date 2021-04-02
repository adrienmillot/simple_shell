#ifndef SHELL_H
#define SHELL_H

#define SEPARATORS " \n"
#define PATH_SEPARATOR ":"

int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void _parsingString(char *prmString, char *prmSeparator, char *argv[]);

void _parsingArguments(char *prmParametersLine, char *prmArgv[]);
int _isBuildIn(char *prmCommandName);
void _execCmd(char *prmArguments[]);

#endif
