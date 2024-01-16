/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _perror.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 08:34:19 by marvin            #+#    #+#             */
/*   Updated: 2023/07/09 10:34:26 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	perror(const char *s);

#include <errno.h>

int main(void) {
	perror("\nbefore error");
	errno = ENOMEM;
	puts("");
	perror("errno = ENOMEM");
	errno = EACCES;
	puts("");
	perror("errno = EACCES");
	errno = ENOENT;
	puts("");
	perror("errno = ENOENT");
	errno = ENOTDIR;
	puts("");
	perror("errno = ENOTDIR");
	errno = EFAULT;
	puts("");
	perror("errno = EFAULT");
	errno = EBADF;
	puts("");
	perror("errno = EBADF");
	return (0);
}

/*
	errno 변수와 각각의 매크로는 <errno.h>에 있다.
	perror는 errno에 해당하는 에러 메세지를 표준에러에 출력해준다. 인자로 문자열을 넣으면 “문자열: 에러메세지” 형태로 출력되고, NULL 포인터를 인자로 넣어주면 에러메세지만 출력된다.
*/
