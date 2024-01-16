/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 07:26:58 by marvin            #+#    #+#             */
/*   Updated: 2023/07/08 07:35:25 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

# define CHILD 0

int main(int argc, char *argv[]) {
	(void)argc;
	(void)argv;
	int id = fork();
	if (id == CHILD)
		sleep(1);
	printf("current id: %d VS ", getpid());
	printf("parent id: %d\n", getppid());
	int res = wait(NULL);
	if (res == -1) {
		printf("No children to wait for\n");
	} else {
		printf("%d finished execution\n", res);
	}
	return (0);
}