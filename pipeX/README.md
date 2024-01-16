# Process and Thread Explanation

This repository provides an explanation of processes and threads in computing, highlighting their key characteristics and differences.

## Table of Contents

- [Introduction](#introduction)
- [Processes](#processes)
    - [Key Characteristics of a Process](#key-characteristics-of-a-process)
- [Threads](#threads)
    - [Key Differences Between Processes and Threads](#key-differences-between-processes-and-threads)
- [Conclusion](#conclusion)

## Introduction

In computing, the concepts of processes and threads are fundamental to understanding concurrent execution and resource management. This document aims to clarify the concepts and differences between processes and threads.

## Processes

A process can be understood as an executing instance of a program. It is an independent entity that contains the code, data, and system resources necessary to execute the program's instructions. When you run a program on your computer, the operating system creates a process for that program, allowing it to be executed in a controlled and isolated environment. Each process has its own memory space, file descriptors, and other resources.

### Key Characteristics of a Process

1. Isolation: Processes are isolated from each other, meaning the memory and resources of one process are not directly accessible by another process. This isolation enhances stability and security.

2. Resource ownership: Each process has its own set of system resources, such as memory, file handles, and network connections. These resources are released when the process terminates.

3. Interprocess communication (IPC): Processes can communicate with each other through various mechanisms provided by the operating system, like pipes, sockets, and shared memory.

## Threads

Threads are smaller units of execution within a process. A process can have multiple threads, and these threads share the same memory space and resources of the parent process. While they are lighter weight than processes (as they share resources), they are also less isolated from one another.

### Key Differences Between Processes and Threads

1. Resource sharing and overhead: Threads within the same process share resources, like memory, file handles, and other process-level resources, which reduces the overhead of creating and managing individual processes. Creating a new thread is generally faster than creating a new process.

2. Communication: Threads can communicate with each other more easily since they share the same memory space. However, this shared memory also brings challenges, such as the need for synchronization to avoid data corruption.

3. Isolation: Processes are fully isolated from each other, which means a problem in one process is less likely to affect others. Threads share the same memory space, so an issue in one thread can potentially crash the entire process.

4. Robustness: Due to isolation, processes are generally more robust against failures and errors. In contrast, an error in one thread can impact other threads within the same process.

## Conclusion

In summary, processes and threads are both used for concurrent execution in a computer system, but processes offer more isolation and robustness, while threads provide better resource sharing and communication capabilities. The choice between using processes or threads depends on the specific requirements of the application and the desired balance between isolation and resource efficiency.

---

# pipex

## Basic Concept

Processes

To work on the pipex project, it is important to understand the concept of processes.

A process refers to the state in which a program is executed. When a program is executed, it means that the program code is loaded into the RAM and operates.

'Processes' are units that receive system resources from the operating system, while 'threads' are units of program execution.

Processes receive allocations of resources such as memory and address space from the operating system, while threads share the allocated resources among themselves and execute.

## Redirection in Unix

In Unix, redirection refers to the ability to change the input source or output destination of a command or program. It allows you to control where the input comes from and where the output goes, providing flexibility and enabling powerful data manipulation.

Here are some common redirection operators in Unix:

- Input Redirection (`<`): Redirects the standard input of a command or program from a file.
- Output Redirection (`>`): Redirects the standard output of a command or program to a file, overwriting it if it exists.
- Appending Output Redirection (`>>`): Appends the standard output of a command or program to a file.
- Error Redirection (`2>` or `2>>`): Redirects the standard error output of a command or program to a file.
- Input/Output Redirection (`<>`): Redirects both input and output simultaneously, typically used with special files.

These redirection operators provide powerful capabilities for manipulating input and output streams, enabling efficient automation and scripting.

## Heredoc

Heredoc, short for "here document," is a feature in Unix-based shells (such as Bash) that allows you to include multiple lines of input within a script or command without the need for external files. It is particularly useful when you want to provide a block of text as input to a command or when you need to embed multiline strings within a script.

The heredoc syntax typically follows this format:

command << DELIMITER
...
text
...
DELIMITER


For example:

```bash
cat << END
This is line 1.
This is line 2.
This is line 3.
END
