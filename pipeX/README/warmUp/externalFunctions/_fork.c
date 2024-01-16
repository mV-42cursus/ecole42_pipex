/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _fork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 08:43:17 by marvin            #+#    #+#             */
/*   Updated: 2023/07/11 18:57:47 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(void) {

	printf("process id before fork: %d\n", getpid());
	printf("--------------------------------------------------\n");							

	// PARENT PROCESS																	// CHILD PROCESS
	pid_t new_pid = fork();																// pid_t new_pid = fork();						
	printf("\t\t\t-------->>new pid: %d\n", new_pid);									// printf("\t\t\t-------->>new pid: %d\n", new_pid);
	if (new_pid < 0) {																	// if (new_pid < 0) {
		perror(NULL);																	// 	perror(NULL);	
		return (1);																		// 	return (1);		
	}																					// }				
	if (new_pid == 0) {																	// if (new_pid == 0) {								
		printf("this is child process. child's process id(pid): %d\n", getpid());		// 	printf("this is child process. child's process id(pid): %d\n", getpid());
		printf("new process from child: %d\n", new_pid);								// 	printf("new process from child: %d\n", new_pid);						
	} else {																			// } else {																	
		printf("this is parent process. parent's process id: %d\n", getpid());			// 	printf("this is parent process. parent's process id: %d\n", getpid());	
		printf("new process id from parent: %d\n", new_pid);							// 	printf("new process id from parent: %d\n", new_pid);					
	}																					// }																		
	printf("~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~\n");			// printf("~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~\n");	
}

/* 
	새로운 프로세스를 생성해주는 함수. fork를 호출한 프로세스를 부모 프로세스, 새로 생긴 프로세스를 자식 프로세스라고 한다.
	실패할 경우 자식 프로세스는 생성되지 않고, 부모 프로세스에게 음수를 반환해준다 (newpid < 0) 
	성공할 경우 부모 프로세스에게는 새로 생성된 자식 프로세스의 pid를, 자식프로세스에게는 0을 반환해준다.
	즉 자식 프로세스는 newpid == 0인 조건문을, 부모 프로세스는 else의 경우를 실행하게 된다.
*/

/* 
	기본 개념
	프로세스
	우선 파이프엑스 과제를 하기 위해선 프로세스의 개념을 알아야 한다.

	프로세스란 프로그램이 실행되는 상태를 말한다. 프로그램이 실행된다는 것은 RAM에 프로그램 코드가 적재돼 동작한다는 것이다.
	프로세스'는 운영체제로부터 시스템 자원을 할당 받는 단위 '스레드'는 프로그램 실행 단위다.
	프로세스는 운영체제로부터 메모리, 주소공간 등을 할당 받고 스레드는 할당 받은 자원들을 스레드끼리 공유하며 실행된다.

	IPC
	파이프는 두 프로세스가 통신할 수 있게 하는 정보 전달자다. 정보 생산자와 정보 소비자 프로세스 간 통신을 의미한다.
	IPC 방법에는 공유 메모리, 소켓, 파이프 등이 있다.

	과제에서 진행하는 파이프에서는 파이프의 양끝단에서 파일 디스크립터를 사용하게 되는데 이는 파이프의 데이터 스트림(프로세스를 출입하는 데이터의 흐름) 번호이다. 프로세스의 출력을 리다이렉션 한다는 것은 데이터를 보내는 곳을 변경한다는 것이다.
	프로세스는 fd와 해당 데이터 스트림을 디스크립터 테이블에 저장해 처리한다.

	0~2 (표준 입출력)
	0 : 표준입력
	1 : 표준출력
	2 : 표준에러
	3 : 추가적인 프로세스의 데이터 스트림

	**파일디스크립터가 파일을 의미하는 것은 아님

	예를들어 printf()의 경우 표준출력으로 데이터를 내보내는데, 이는 fd = 1인 경우로 디스크립터 테이블에서 fd = 1인 경우의 데이터 스트림을 찾아 데이터를 해당 스트림에 출력한다.

	참고) 시그널
	프로세스는 OS가 시그널로 관리하는데, 시그널은 보통 프로세스를 종료하기 위해 사용된다.
	프로세스가 시그널을 받으면, 프로세스는 시그널 처리기를 실행한다. 시그널 처리기의 기본 동작은 프로세스를 종료하는 것이다. 다만 sigaction()함수를 사용하면 처리기 동작을 변경할 수 있다.
	raise() 함수를 사용하면 프로세스 자신에게 시그널을 보내는 것도 가능하다.
	또 모든 프로세스는 타이머를 하나씩 갖고 있는데, alram() 또는 sleep()함수중 하나(두개 적용 X)를 적용할 수 있다.
*/
