//std.h
#define WIN32_LEAN_AND_MEAN
//H���� �浹 ó�� WINDOWS.H , WINSOCK2.H ���������� ������ Ű���� ����
#pragma comment (linker, "/subsystem:windows")

#include <Windows.h>
#include <tchar.h>	
#include <stdio.h>
//����-------------------------------
#include <WinSock2.h>	
#pragma comment(lib, "ws2_32.lib")  
#include <ws2tcpip.h>
#include <process.h>
//---------------------
#include "account.h"
#include "packet.h"
#include "UI.h"
#include "resource.h"
#include "handler.h"
#include "control.h"
#include "wbclient.h"
