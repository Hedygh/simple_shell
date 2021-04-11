<p align="center">

  <img src="https://cdn.homesthetics.net/wp-content/uploads/2015/10/21-Sea-Shell-Projects-To-Consider-On-Your-Next-Walk-By-The-Beach-10.jpg" width="400\"/>

  <br>

**SIMPLE SHELL**
A shell is the top level layer of the Unix system.

To put it simply, a shell is a program that takes a command as input, parses it, and executes it.

We will divide the work into several parts:

# Loop back user input
# Parse user input
# Execute the command
# Code the builtins
# Environnment management

**Directions for Use**
Compile with this command:

gcc -Wall -Werror -Wextra -pedantic *.c

Invoke shell by typing its path name

$ ./a.out
hedy_cherif&>i

### List of useful commands
* `cat` - prints and concatenates files to the standard output
* `cp` -copies a file into another file
* `less` - will let you go backward and forward in the files
* `ls` - will list all files and directories in current working directory
* `mv` - helps to move one file into another file
* `pwd` - given you the current working directory

### Builtins
There are two builtins programmed into the shell. Below is a description and use for each builtin.

* `env` - The env command is a command that tells the shell program to display all of the environment variables with their values. It is a    way to access those values through the shell.

* `exit` - If you wish to exit out of the shell the user can use the builtin `exit`.

