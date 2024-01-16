/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:16:30 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:19:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

// int main()
// {
// 	ft_putstr_fd("hello world!\n", 0);
// 	ft_putstr_fd("hello world!\n", 1);
// 	ft_putstr_fd("hello world!\n", 2);
// }