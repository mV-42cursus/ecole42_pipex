/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 03:55:07 by marvin            #+#    #+#             */
/*   Updated: 2023/07/17 01:19:01 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

extern char **environ;

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>

# define CHILD 0
# define PIPIN_FILENO 0 // read

int main()
{
	int fd = open("infile", O_RDONLY);
	dup2(fd, 0);
	close(fd);
	char *cmd1[10] = {"cat", NULL};
	execv("/bin/cat", cmd1);
	return (0);
}