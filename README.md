
# Pipex

## Overview
Pipex is a C program that simulates the behavior of the Unix shell's pipeline mechanism. It takes two commands as arguments and executes them in a manner similar to shell command `cmd1 | cmd2`, redirecting the output of `cmd1` to `cmd2`.

## Usage

### Execution
The program is executed with the following syntax:
```bash
./pipex file1 cmd1 cmd2 file2
```
This will take the output of `cmd1` executed on `file1` and use it as input for `cmd2`, with the final output being written to `file2`.

### Function Prototype
Not applicable. The program is executed as a standalone application.

### Parameters
- `file1`: The first file or standard input to be read.
- `cmd1`: The first command to be executed.
- `cmd2`: The second command to be executed.
- `file2`: The file where the output of `cmd2` is written.

## Installation and Compilation
To use Pipex, clone the repository and compile the source files. For example:
```bash
gcc -Wall -Wextra -Werror main.c pipex.c -o pipex
```

## Example
```bash
./pipex infile "ls -l" "wc -l" outfile
```
This example will list the contents of `infile` using `ls -l` and count the number of lines using `wc -l`, with the output written to `outfile`.

## Notes
- Ensure to handle errors and edge cases, such as invalid file descriptors or empty commands.
- Free any dynamically allocated memory to prevent memory leaks.

# Pipex Project

For more details, visit the [PIPEX NOTION PAGE](https://dykim04.notion.site/ecole-42-project-pipex-1955602053eb4e6ea87575bafbe67c46?pvs=4).
