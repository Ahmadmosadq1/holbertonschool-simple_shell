# 🐚 SIMPLE SHELL PROJECT 🐚  

****

## 📑 Table of Contents
- **What is the shell? 🐚**
- **About this project ℹ️**
- **Essential Functionalities of the Simple Shell 📝**
- **File Description 📂**
- **List of Allowed Functions and System Calls 📲**
- **Usage ⚙️**
- **Example of Usage 💯**
- **Team 🥇**

****

## 🐚 What is the shell?  
The shell is a program that takes commands from the keyboard via the terminal and gives them to the operating system to perform.  
**To better understand how the shell actually works, you can read our [Article].**

## ℹ️ About this project
This project is a simple version of the Linux shell made for [Holberton School], as part of the "Low-level programming & Algorithm - Linux and Unix system programming" course.  
It is created using the **C programming language** and it mimics many functionalities of a real shell.

## 📝 Essential Functionalities of the Simple Shell:
- Displays a prompt "#$ " and waits for user input.
- Runs all commands of type "executable program" (e.g., `ls` and `/bin/ls`).
- Runs the following built-in commands: **exit**, **env**, **setenv**, and **unsetenv**.
- Handles commands with arguments.
- Handles the `PATH` global variable.
- Handles The EOF (End Of File) condition.
- Handles the Ctrl + C signal → It doesn't exit the shell.

## 📂 Files description:
- **AUTHORS** → List of contributors to this repository.
- **README.md** → Description of the project repository.
- **man_1_simple_shell** → Manual page for the simple_shell.
- **CORE SHELL FILES**:
  - **main.c** → Shell entry point, main loop.
  - **shell_loop.c** → REPL (Read-Execute-Print Loop) implementation.
  - **parser.c** → Command parsing logic.
  - **tokenizer.c** → Splits input into executable tokens.
  - **getLine.c** → Custom input reader.
  
- **BUILTIN COMMANDS**:
  - **builtin.c** → Core built-ins (exit, env, cd).
  - **builtin1.c** → Extended built-ins (setenv, unsetenv).
  - **exits.c** → Exit status handling.
  - **getenv.c** → Environment variable access.
  - **environ.c** → Environment management.
  
- **UTILITIES**:
  - **string.c** → Basic string ops (strlen, strcpy).
  - **string1.c** → Advanced string ops (strcmp, strdup).
  - **_atoi.c** → String to integer conversion.
  - **memory.c** → Memory management.
  - **realloc.c** → Custom realloc implementation.

- **ERROR HANDLING**:
  - **errors.c** → Base error messages.
  - **errors1.c** → Extended error cases.

- **DATA STRUCTURES**:
  - **history.c** → Command history storage.
  - **vars.c** → Shell variable handling.
  - **getinfo.c** → Runtime info access.
  - **lists.c** → Linked list implementation.
  - **lists1.c** → Advanced list operations.

****

## 📲 List of allowed functions and system calls for this project:
- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `_exit` (man 2 _exit)
- `fflush` (man 3 fflush)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `getcwd` (man 3 getcwd)
- `getline` (man 3 getline)
- `isatty` (man 3 isatty)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `opendir` (man 3 opendir)
- `perror` (man 3 perror)
- `read` (man 2 read)
- `readdir` (man 3 readdir)
- `signal` (man 2 signal)
- `stat (__xstat)` (man 2 stat)
- `lstat (__lxstat)` (man 2 lstat)
- `fstat (__fxstat)` (man 2 fstat)
- `strtok` (man 3 strtok)
- `wait` (man 2 wait)
- `waitpid` (man 2 waitpid)
- `wait3` (man 2 wait3)
- `wait4` (man 2 wait4)
- `write` (man 2 write)

****

## ⚙️ USAGE:
You can try our shell by following these steps:
> **Step 1:** Clone our repository using this command (you need to have git installed on your machine first):
````
git clone https://github.com/Ahmadmosadq1/holbertonschool-simple_shell.git
````
> **Step 2:** Change directory to simple_shell:
````
cd holbertonschool-simple_shell
````
> **Step 3:** Compile the C files in this way:
````
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
````
> **Step 4:** Run the shell
````
./hsh
````
**Exiting the shell**
When you want to exit the shell, you can use one of the following methods:
> **1: Type the command "exit"**
````
exit
````
> **2: Press on Ctrl + D**
## Example of Usage💯
````
root@0af34759cb774125854d542ce222dc6a-2377118072:/holbertonschool-simple_shell# gcc -Wall -Wextra -Werror -pedantic *.c -o hsh
root@0af34759cb774125854d542ce222dc6a-2377118072:/holbertonschool-simple_shell# ./hsh
$ echo Hello, This is an example
Hello, This is an example
$ ls
AUTHORS    builtin1.c  exits.c    history.c  main.c              realloc.c     string1.c
README.md  environ.c   getLine.c  hsh        man_1_simple_shell  shell.h       tokenizer.c
_atoi.c    errors.c    getenv.c   lists.c    memory.c            shell_loop.c  vars.c
builtin.c  errors1.c   getinfo.c  lists1.c   parser.c            string.c
$ ^C
$ ls -l
total 156
-rw-r--r-- 1 root root   147 Apr 17 13:36 AUTHORS
-rw-r--r-- 1 root root  5762 Apr 17 13:36 README.md
-rw-r--r-- 1 root root  1278 Apr 17 21:11 _atoi.c
-rw-r--r-- 1 root root  2181 Apr 17 21:12 builtin.c
-rw-r--r-- 1 root root  2119 Apr 17 21:12 builtin1.c
-rw-r--r-- 1 root root  1839 Apr 17 21:13 environ.c
-rw-r--r-- 1 root root  1331 Apr 17 21:13 errors.c
-rw-r--r-- 1 root root  2529 Apr 17 21:14 errors1.c
-rw-r--r-- 1 root root  1154 Apr 17 21:14 exits.c
-rw-r--r-- 1 root root  3431 Apr 17 21:15 getLine.c
-rw-r--r-- 1 root root  1886 Apr 17 21:15 getenv.c
-rw-r--r-- 1 root root  1300 Apr 17 21:16 getinfo.c
-rw-r--r-- 1 root root  2867 Apr 17 21:16 history.c
-rwxr-xr-x 1 root root 41232 Apr 17 22:25 hsh
-rw-r--r-- 1 root root  2677 Apr 17 21:17 lists.c
-rw-r--r-- 1 root root  1997 Apr 17 21:17 lists1.c
-rw-r--r-- 1 root root   685 Apr 17 21:18 main.c
-rw-r--r-- 1 root root  1458 Apr 17 22:04 man_1_simple_shell
-rw-r--r-- 1 root root   262 Apr 17 21:18 memory.c
-rw-r--r-- 1 root root  1481 Apr 17 21:19 parser.c
-rw-r--r-- 1 root root  1149 Apr 17 21:19 realloc.c
-rw-r--r-- 1 root root  5495 Apr 17 21:20 shell.h
-rw-r--r-- 1 root root  3053 Apr 17 21:20 shell_loop.c
-rw-r--r-- 1 root root  1274 Apr 17 21:21 string.c
-rw-r--r-- 1 root root  1301 Apr 17 21:21 string1.c
-rw-r--r-- 1 root root  1916 Apr 17 21:22 tokenizer.c
-rw-r--r-- 1 root root  2797 Apr 17 21:22 vars.c
$ exit
root@0af34759cb774125854d542ce222dc6a-2377118072:/holbertonschool-simple_shell#

````
## 👨‍💻 

- **Saleh Alharbi**🌟  
- **Ahmed Aljuhani**🚀

