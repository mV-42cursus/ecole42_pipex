/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _wait.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 07:15:26 by marvin            #+#    #+#             */
/*   Updated: 2023/07/09 04:22:02 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

# define CHILD 0

int main(int argc, char *argv[]) {
	(void)argc;
	(void)argv;
	int id = fork();
	int n;
	int i;

	if (id == CHILD) {
		n = 1;
	} else {
		n = 6;
	}
	if (id != CHILD) {
		wait(&id);
	}
	for (i = n; i < n + 5; i++) {
		printf("%d ", i);
		fflush(stdout);
	}
	puts("");
	return (0);
}
