# Simple Shell
This is a simple shell project implemented in the C programming language. The shell provides a command-line interface for users to interact with the operating system. It accepts user commands, executes them, and displays the output.
## Learning Objectives
By completing this project, you will gain knowledge and understanding of the following concepts:
- The original Unix operating system and its designer/developer
- The first version of the UNIX shell and its creator
- The B programming language and its relation to C
- Ken Thompson, a prominent computer scientist and co-creator of Unix
- The working principles of a shell
- Process IDs (PID) and parent process IDs (PPID)
- Manipulating the environment of a process
- Difference between a function and a system call
- Process creation and execution
- Three prototypes of the main function
- How a shell uses the PATH variable to locate programs
- Executing another program using the execve system call
- Suspending process execution until a child process terminates
- End-of-file (EOF) concept

## Requirements
- Allowed editors: vi, vim, emacs
- Compiled on Ubuntu 20.04 LTS using gcc with the following flags: -Wall -Werror -Wextra -pedantic -std=gnu89
- All files should end with a new line
- The code should follow the Betty style guidelines
- No memory leaks should be present in the shell implementation
- No more than 5 functions per file
- Header files should be include guarded
- System calls should be used only when necessary
- README.md file at the root of the project folder, providing project description
- AUTHORS file at the root of the repository, listing all contributors
## Authors

- [EL AAMILI HAMZA](https://github.com/Hamzaelaamili)
- [CHAIMAA HASSOUNE](https://github.com/chaimaahassoune)
## Usage
1. Clone the repository:

##### git clone <repository_url> 


2. Compile the shell program:
 
##### gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell

3. Run the shell:

##### ./shell

4. Enter commands and interact with the shell.
