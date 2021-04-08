# Simple Shell

## What is a shell

THe shell is a program that receive commands from user, from keybord to send them to the explotation system in charge of executing them.
>"Shell" signifies interface system.
Shell designates the lowest layer of all the interfaces systems.

## What's the use of a script in shell?

On most Linux systems, a program is called bash (signifies Bourne again Shell) act as shell program.
All shell can execute commands located in files. Each file containing commands intended for shell is called a script.
A script looks like a file text executable by the machine.
but need to be interpreted by the terminal emulator.
It's objective is to launch and coordinates the execution of programs without passing by the graphic interface.

### Exercices

Write a UNIX command line interpreter

The shell should:
• Display a prompt and wait for the user to type a command. A command line always ends with a new line.
• The prompt is displayed again each time a command has been executed.
• The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
• The command lines are made only of one word. No arguments will be passed to programs.
• If an executable cannot be found, print an error message and display the prompt again.
• Handle errors.
• You have to handle the “end of file” condition (Ctrl+D)

#### Usages: 

````
julien@ubuntu:~/shell$ ./shell 
#cisfun$ ls
./shell: No such file or directory
#cisfun$ /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ /bin/ls -l
./shell: No such file or directory
#cisfun$ ^[[D^[[D^[[D
./shell: No such file or directory
#cisfun$ ^[[C^[[C^[[C^[[C
./shell: No such file or directory
#cisfun$ exit
./shell: No such file or directory
#cisfun$ ^C
julien@ubuntu:~/shell$ echo "/bin/ls" | ./shell
#cisfun$ barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ julien@ubuntu:~/shell$
````

Handle command lines with arguments

#### Usage: 

````
/bin/ls -l
````

Handle the PATH

#### Usage:

````
PATH=/bin/ls:/usr/bin/ls: /*and so on*/
````

Implement the exit built-in, that exits the shell

#### Usage:

````
exit(0);
````

Implement the env built-in, that prints the current environment

#### Usage:

````
$ env /* Command line entered by user */
USER=julien
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/julien
C_IS=Fun_:)
DESKTOP_SESSION=ubuntu
LOGNAME=julien
TERM=xterm-256color
PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
````

Contribute to a test suite for your shell. (This is a task shared by everyone in the class)

Write your own getline function

>getline function is usefull for getting the user input in command prompt.

#### Usage:

````
_getline(&buffer, &bufferSize, stdin);
````

You are not allowed to use strtok

>strtok function is usefull fo cutting the character(s) we want in a line

#### Usage:

````
_strtok(string, "character(s)");
````

handle arguments for the built-in exit

>exit function is usefull for exiting a program and printing an integer

#### Usage:

````
$ exit 98
julien@ubuntu:~/shell$ echo $?
98
````

Handle Ctrl+C: your shell should not quit when the user inputs ^C

>Because we already use Ctrl+D to exit our custom shell

#### Usage:

````
signal(SIGINT, SIG_IGN); /* Ignore the Ctrl+c Input */
````
