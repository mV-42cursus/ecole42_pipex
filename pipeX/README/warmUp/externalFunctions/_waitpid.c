/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _waitpid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:25:09 by marvin            #+#    #+#             */
/*   Updated: 2023/07/09 09:31:38 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>

#include <stdio.h>
#include <unistd.h>

int main(void) {
	pid_t pid;
								// int state = 0;
								// pid_t ret;

	pid = fork();
	if (pid == 0) {
		sleep (1);
								// ret = waitpid(-1, &state, 0);
								// perror("child");
		printf("this is child\n");
	} else {
								// ret = waitpid(pid, &state, 0);
								// perror("parent");
								// printf("child pip: %d\n", ret);
		printf("this is parent\n");
	}
	return (0);
}

/* 
	원래 fork된 각각의 프로세스는 병렬적으로 실행되고, 순서가 보장되지 않는다. 
	그래서 child에 sleep을 걸어두고 실행하면 
	부모 프로세스가 먼저 실행되고 종료된 후 차일드 프로세스가 나중에 실행되는 것을 확인할 수 있다. 
	
	waitpid를 이용해 첫번째 인자 pid에 해당하는 프로세스가 종료될 때까지 기다리게 할 수 있다.
	
	pid: 양의 정수면 해당 프로세스를 기다리고, -1 이면 아무 자식 프로세스, 0의 경우 같은 프로세스그룹의 자식 프로세스를 기다린다. 
	-1 보다 작은 정수의 경우 “프로세스 그룹 id = |pid|”인 프로세스를 기다린다고 한다...(이렇게 써보진 않았다)
	
	state: 종료된 프로세스의 상태를 int로 받아온다. 
	이후 WIFEXITED, WIFSIGNALED, WEXITSTATUS, WTERMSIG 등의 매크로 함수를 이용해 종료 코드나, 시그널 등을 확인할 수도 있다.
	options는 0, WNOHANG, WUNTRACED 등이 있다.
	
	waitpid는 종료된 프로세스의 pid를 반환하며, 에러나 기다릴 자식 프로세스가 없는 경우 음수를 반환한다.
	
	위의 주석을 제거하고 실행할 경우, 
	자식 프로세스는 기다릴 프로세스가 없으므로 No child processes 에러가 나오며, 
	부모는 정상적으로 자식프로세스가 종료되었으므로 자식 프로세스의 pid를 받아와서 출력한다.
*/