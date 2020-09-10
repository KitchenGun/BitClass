#pragma comment (linker, "/subsystem:console")
//뮤텍스//커널 오브젝트 프로세스와 프로세스의 동기화를 보여줌
#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
	// 뮤텍스 생성
	//만약 생성 객체를 다시 create하게 되면 open 으로 변경해준다
	HANDLE hMutex = CreateMutex(NULL, // 보안속성
														FALSE, // 생성시 뮤텍스 소유 여부
														TEXT("mutex")); // 이름
		// 소유가 ture일때 -> Signal 을 nonsignal로 바꾼다.
	cout << "뮤택스를 기다리고 있다." << endl;
	//wait for 가 리턴하면 해당 객체의 상태값을 non_s 변경
	DWORD d = WaitForSingleObject(hMutex, INFINITE); // 대기
	if (d == WAIT_TIMEOUT)
		MessageBox(NULL, TEXT("WAIT_TIMEOUT"), TEXT(""), MB_OK);
	else if (d == WAIT_OBJECT_0)
		MessageBox(NULL, TEXT("WAIT_OBJECT_0"), TEXT(""), MB_OK);
	else if (d == WAIT_ABANDONED_0)//누군가 뮤텍스를 소유한 상태에서 죽은 경우
		MessageBox(NULL, TEXT("WAIT_ABANDONED_0"), TEXT(""), MB_OK);
	cout << "뮤택스 획득" << endl;
	MessageBox(NULL, TEXT("뮤택스를 놓는다."), TEXT(""), MB_OK);
	ReleaseMutex(hMutex);//뮤텍스 끄기

	return 0;
}