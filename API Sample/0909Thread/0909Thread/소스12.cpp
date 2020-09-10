#pragma comment (linker, "/subsystem:console")
//세마 포어 //커널 오브젝트 프로세스와 프로세스의 동기화를 보여줌
#include<Windows.h>
#include<stdio.h>


void main()
{
	//카운트가 0보다 크면 통과	0이면 nonsignal 0 보다 크면 signal
	HANDLE hSemaphore = CreateSemaphore(0, // 보안
		3, // count 초기값
		3, // 최대 count
		TEXT("s")); // 이름

	printf("세마포어를 대기합니다.\n");
	WaitForSingleObject(hSemaphore, INFINITE); //--count
	printf("세마 포어를 획득\n");
	MessageBox(0, TEXT("Release??"), TEXT(""), MB_OK);
	LONG old;
	ReleaseSemaphore(hSemaphore, 1, &old); // ++count 
	CloseHandle(hSemaphore);
}
// 메세지 Box 의 OK를 누르지 말고.. 4번 이상 실행해 보세요..