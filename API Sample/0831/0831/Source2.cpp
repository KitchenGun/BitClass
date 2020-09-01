//윈도우 생성하기
#include <Windows.h>
#include<tchar.h>//범용타입용


int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmd, int nShow)
{
	//1.윈도우 클래스 만들기
	WNDCLASS wc;
	wc.cbWndExtra = 0;																					//지금은 안쓰지만 나중에 확장을 위해서
	wc.cbClsExtra = 0;																					//지금은 안쓰지만 나중에 확장을 위해서
	//GetStockObject 미리만들어진 객체를 얻어오는 함수
	//가져올수 있는 오브젝트 팬 브러쉬 폰트
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);			//배경색상을 어떻게 할것인가(형변환)하여 오브젝트를 불러옴
	//첫번째 인자에서 갖고 있는 두번째 인자로 전달된 ID 리소스를 가져오겠다.
	//1인자 : HINSTANCE 0? OS가 전달하는 값
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	//내 인스턴스 등록
	wc.hInstance = hInst;
	//내 윈도우에 이벤트가 발생하면 그 이벤트를 처리할 함수
	//제공되는 이벤트 처리 함수 : 모든 윈도우가 공통적으로 처리하는 기능을 갖고 있다.
	wc.lpfnWndProc = DefWindowProc;
	//지금 만들어지는 클래스 이름 - > key로 사용된다(대소문자 구분없음)
	wc.lpszClassName = _TEXT("First");
	//기타
	wc.lpszMenuName = 0;
	wc.style = 0;

	// 2. 등록(레지스트리에)
	RegisterClass(&wc);

	// 3. 윈도우 창 만들기 
	HWND hwnd = CreateWindowEx(0,					// WS_EX_TOPMOST
		_TEXT("first"),				// 클래스 명(키값)
		_TEXT("Hello"),				// 캡션바 내용
		WS_OVERLAPPEDWINDOW &~WS_MAXIMIZEBOX,//일반적인 윈도우가 가지고 있는 스타일들의 패키지
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,	// 초기 위치  시작x, 시작y, 폭, 높이(초기위치)
		0, 0,			// 부모 윈도우 핸들, 메뉴 핸들
		hInst,		// WinMain의 1번째 파라미터 (exe 주소)
		0);			// 생성 인자



	// 4. 윈도우 보여주기
	ShowWindow(hwnd, SW_MAXIMIZE);		//객체를 제어하는 첫번째 함수를 보게됨
	UpdateWindow(hwnd);


	// 5. Message 

	MessageBox(0, TEXT("윈도우 생성"), TEXT("타이틀바"), MB_YESNO | MB_ICONQUESTION);
	MoveWindow(hwnd, 0, 0, 200, 200, FALSE);
	MessageBox(0, TEXT("제어"), TEXT("타이틀바"), MB_YESNO | MB_ICONQUESTION);
	return 0;
}