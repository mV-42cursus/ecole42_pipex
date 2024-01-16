/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dup2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:33:41 by marvin            #+#    #+#             */
/*   Updated: 2023/07/11 19:43:09 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	dup2(int fildes, int fildes2);

#include <stdio.h>
#include <fcntl.h>

int	main(void) {
	int	fd = open("newfile", O_RDWR | O_CREAT, 0644);
	printf("[1] printf before dup2\n");
	dup2(fd, STDOUT_FILENO);
	printf("[2] printf after dup2\n");
	close(fd);
	return (0);
}

/* 
	file descriptor를 복사한다.
	위의 경우 dup2 이전에는 printf가 표준출력, 터미널에 메세지를 출력하지만, 
	dup2이후에는 printf가 터미널이 아닌 fd 에 해당하는 newfile에 메세지를 쓰게 된다.
	성공시 새 file descriptor를, 실패시 -1을 반환한다. 
*/