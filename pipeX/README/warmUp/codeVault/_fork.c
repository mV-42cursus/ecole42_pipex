/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _fork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 06:36:32 by marvin            #+#    #+#             */
/*   Updated: 2023/07/13 17:07:45 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
# define CHILD 0
/* BASIC FUNCTION */
// int main (int argc, char *argv[]) {
// 	(void)argc;
// 	(void)argv;
// 	int id = fork();
// 	if (id == 0) {
// 		printf("child process id: %d\n", id);
// 	} else {
// 		printf("parent process id: %d\n", id);
// 	}
// 	return (0);
// }

int main (int argc, char *argv[]) {
	(void)argc;
	(void)argv;
	int id = fork();
	int i = 0;
	while (id != CHILD) {
		if (i == 100)
			break ;
		i++;
		id = fork();
	}
	printf("Hello from [process id]: %d \t\t\ti = %d\n", id, i);
	return (0);
}
