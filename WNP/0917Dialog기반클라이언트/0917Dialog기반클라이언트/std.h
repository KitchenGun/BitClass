//std.h
#define WIN32_LEAN_AND_MEAN
//H파일 충돌 처리 WINDOWS.H , WINSOCK2.H 내부적으로 동일한 키워드 정리
#pragma comment (linker, "/subsystem:windows")
#include <Windows.h>
#include <tchar.h>		//범용타입 사용을 위한 h 
#include <atlstr.h>
//---------------------- Winsock관련 h ------------------------
#include <WinSock2.h>	
#pragma comment(lib, "ws2_32.lib")  
#include <ws2tcpip.h>
#include <process.h>
#include<wtypes.h>
#include "packet.h"
#include "wbclient.h"
#include "wbchatclient.h"
//-------------------------------------------------------------
#include<stdio.h>
#include "resource.h"
#include "handler.h"
#include "control.h"
#include "newmemberdlg.h"

