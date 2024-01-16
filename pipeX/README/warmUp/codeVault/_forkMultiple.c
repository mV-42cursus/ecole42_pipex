/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _forkMultiple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 07:39:58 by marvin            #+#    #+#             */
/*   Updated: 2023/07/09 04:22:04 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

# define CHILD 0

/* 
				id1 = x
				id2 = z
					|
					V
			~~~~~~~~~~~~~~~~~~~~~~
			|					|
			V					V
	[x]	 id1 = 0		 [z]  id1 = x
		 id2 = y		      id2 = 0
		 	|
		 	V
	[y]	 id1 = 0
		 id2 = 0
*/

int main(int argc, char *argv[]) {
	(void)argc;
	(void)argv;
	int id1 = fork();
	int id2 = fork();
	// for (int i = 0; i < 10; i++) {
	// 	fork();
	// }
	if (id1 == CHILD) {
		if (id2 == CHILD) {
			printf("We are process y\n");
		} else {
			printf("We are process x\n");
		}
	} else {
		if (id2 == CHILD) {
			printf("We are process z\n");
		} else {
			printf("We are the parent process\n");
		}
	}
	while (wait(NULL) != -1 || errno != ECHILD) {
		printf("Waited for a child to finish\n");
	}
	return (0);
}
