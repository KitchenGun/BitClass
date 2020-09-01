//Api 첫번째 프로그램
/*
1.프로젝트 속성 -> 구성 속성  -> 고급 -> 문자 집합  -> 멀티바이트 문자 집합으로 변경
컴파일러 버전이 올라가며 유니코드 문자 집합체계가 기본세팅이 됨
2.환경에 따라 다른 시작 함수를 찾는다
콘솔 main
폼 WinMain
링커  -> 시스템 -> 하위시스템 -> window로 변경

//환경은 코드로 바꿀수도 있다
//#pragma comment (linker, "/subsystem:windows")
//#pragma comment (linker, "/subsystem:console")
*/

#include <Windows.h>
//시작함수가 main(CUI) -> WinMain(GUI)
/*
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmd, int nShow)
{

	return 0;
}
*/

// 유니코드 (기본 키워드 w : wide늘렸다)
/*
int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPWSTR lpCmd, int nShow)
{

	return 0;
}
*/

#include <tchar.h>
//범용타입 : 상황에 따라 유니코드와 멀티바이트 코드를 선택적 사용
//범용타입 (기본 키워드는 t)
int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmd, int nShow)
{//										자신의 인스턴스, win32는 null         , 명령행인자 , 프로그램 실행형태(최소화 최대화 보통)
	//시스템함수를 사용하기위해서는 _stdcall을 사용해야함
	/*
	문자열 표현법 c : const
	멀티바이트 : LPSTR -> LPCSTR		"test"
	유니코드 : LPWSTR - > LPCWSTR	L"test"
	범용타입 : LPTSTR -> LPCTSTR		TEXT("test")
	*/
	MessageBox(0, TEXT("문자열 출력"), TEXT("타이틀바"), MB_YESNO|MB_ICONQUESTION);
	return 0;
}
