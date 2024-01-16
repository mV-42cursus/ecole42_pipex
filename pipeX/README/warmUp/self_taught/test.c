/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:20:31 by marvin            #+#    #+#             */
/*   Updated: 2023/07/22 00:24:03 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

extern char **environ;

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>

# define CHILD 0
# define PIPIN_FILENO 0 // read
# define PIPOUT_FILENO 1 // write

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int temp_fd = open("infile", O_RDONLY);
	printf("%d\n", temp_fd);
	dup2(temp_fd, STDIN_FILENO);
	printf("%d\n", temp_fd);
	write(0, "aaaaa", 5);
	return (0);
}
