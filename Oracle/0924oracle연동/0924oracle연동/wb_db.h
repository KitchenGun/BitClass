#pragma once
//mydb.h

//db접속함수
BOOL wb_DBConnect(TCHAR *ID,TCHAR *PW);
void wb_DBDisConnect();

//쿼리문 수신
void wb_DBSendSelectData(TCHAR *msg);

void wb_DBSendOtherData(TCHAR* msg);
