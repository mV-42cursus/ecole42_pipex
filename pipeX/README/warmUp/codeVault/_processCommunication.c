/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _processCommunication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 07:58:39 by marvin            #+#    #+#             */
/*   Updated: 2023/07/09 04:22:21 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

# define CHILD 0

int main(int argc, char *argv[]) {
	(void)argc;
	(void)argv;
	int fd[2];
	// fd[0] - read
	// fd[1] - write
	if (pipe(fd) == -1) {
		printf("An error occurred when opening the pipe\n");
		return (1);
	}
	int id = fork();
	if (id == -1) {
		printf("An error occurred during fork\n");
		return (4);
	}
	if (id == CHILD) {
		close(fd[0]);
		int x;
		printf("Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1) {
			puts("An error occurred when writing to the pipe");
			return (2);
		}
		close(fd[1]);
	} else {
		close(fd[1]);
		int y;
		if (read(fd[0], &y, sizeof(int)) == -1) {
			puts("An error occurred when reading to the pipe");
			return (3);
		}
		close(fd[0]);
		printf("Got from child process %d\n", y);
	}
	return (0);
}
