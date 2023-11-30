# ALX Simple Shell

## Introduction

The ALX Simple shell project is a milestone project in the ALX Africa C code curriculum. It aims to teach students how to implement a basic command-line interpreter (CLI) in C language. The project involves creating a shell that can execute built-in commands like `exit`, `env`, and `cd`, as well as external programs.

## Project Overview

The project is divided into multiple tasks that gradually build upon each other. These tasks cover the core functionalities of a command-line interpreter, including:

* Prompt and input handling
* Command parsing
* Built-in commands
* External program execution
* Error handling
* Input/output redirection
* Background execution
* Signal handling

## Prerequisite Skills

To successfully complete this project, you should have a basic understanding of:

* C programming language
* UNIX system concepts, including processes, fork(), exec(), and signals

## Project Setup

1. Clone the ALX Simple shell project repository to your local machine.

2. Create a directory to store your project files.

3. Move the cloned repository contents into the project directory.

4. Install any necessary dependencies, if required.

## Task 1: Write a UNIX command-line interpreter

The first task is to implement a basic command-line interpreter that can handle the following steps:

1. Display a prompt to the user.

2. Wait for the user to type a command.

3. Parse the user input to identify the command and its arguments.

4. Execute the command if it is a built-in command or an external program.

5. Handle errors gracefully.

## Task-Specific Implementation Guidelines

**Prompt and Input Handling:**

* Use the `printf()` function to display the prompt to the user.
* Use the `fgets()` function to read user input from the standard input.

**Command Parsing:**

* Tokenize the user input into separate words using a delimiter like space or newline.
* Identify the first token as the command and the remaining tokens as arguments.

**Built-in Command Execution:**

* Implement built-in commands like `exit`, `env`, and `cd` using `switch` or `if-else` statements.
* Perform the appropriate actions for each built-in command.

**External Program Execution:**

* Use the `fork()` system call to create a child process.
* Use the `execve()` system call to execute the specified external program in the child process.
* Use the `wait()` system call to wait for the child process to finish execution.

**Error Handling:**

* Check for errors during command parsing and execution.
* Use the `perror()` function to print error messages to the standard error.

## Additional Considerations

* Implement input/output redirection using the `>` and `<` operators.
* Implement background execution using the `&` operator.
* Implement signal handling for `SIGINT` (Ctrl+C) and `SIGTERM` (kill) signals.
* Implement signal handling for zombie processes.

## Testing and Debugging

* Write test cases to verify the correct behavior of your shell.
* Use a debugger to identify and fix bugs in your code.

## Resources

* ALX Simple shell project repository
* ALX Africa C code curriculum
* UNIX system documentation.
