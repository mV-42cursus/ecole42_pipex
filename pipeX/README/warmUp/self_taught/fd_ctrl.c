/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:31:54 by marvin            #+#    #+#             */
/*   Updated: 2023/07/18 21:31:55 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>

int isFDOpen(int fd) {
    int flags = fcntl(fd, F_GETFL);

    if (flags == -1) {
        // Error occurred while checking the file descriptor
        return 0;
    }

    // File descriptor is open if it doesn't have the O_CLOEXEC flag
    return !(flags & O_CLOEXEC);
}