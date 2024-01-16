/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dup.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:33:41 by marvin            #+#    #+#             */
/*   Updated: 2023/07/11 19:43:34 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	dup(int fd);

#include <stdio.h>
#include <fcntl.h>

int	main(void) {
	int	fd = open("newfile", O_RDWR | O_CREAT, 0644);
	printf("[1] printf before dup\n");
	fd = dup(STDOUT_FILENO);
	close(STDOUT_FILENO);
	printf("[2] printf after dup\n");
	close(fd);
	return (0);
}

/* 
	file descriptor를 복사한다.
	위의 경우 dup 이전에는 printf가 표준출력, 터미널에 메세지를 출력하지만, 
	dup2이후에는 printf가 터미널이 아닌 fd 에 해당하는 newfile에 메세지를 쓰게 된다.
	성공시 새 file descriptor를, 실패시 -1을 반환한다. 
*/
