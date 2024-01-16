/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _environ.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 08:12:50 by marvin            #+#    #+#             */
/*   Updated: 2023/07/09 09:43:30 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern char **environ;
//	int main(int argc, char *argv[], char *envp[])
int	main(int argc, char *argv[])
{
	int	idx = 0;

	(void)argc;
	(void)argv;
	while (environ[idx])
	{
		printf("environ[%d]: %s\n", idx, environ[idx]);
		idx++;
	}
	return (0);
}

/* 
	POSIX.1 does not allow this three-argument form, 
	so to be portable it is best to write main to take two arguments, 
	and use the value of environ. 
*/
