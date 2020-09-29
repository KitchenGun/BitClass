//std.h
#define WIN32_LEAN_AND_MEAN
//H颇老 面倒 贸府 WINDOWS.H , WINSOCK2.H 郴何利栏肺 悼老茄 虐况靛 沥府
#pragma comment (linker, "/subsystem:windows")

#include <Windows.h>
#include <tchar.h>	
#include <stdio.h>
//家南-------------------------------
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
