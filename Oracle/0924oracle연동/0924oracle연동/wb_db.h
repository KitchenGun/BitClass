#pragma once
//mydb.h

//db�����Լ�
BOOL wb_DBConnect(TCHAR *ID,TCHAR *PW);
void wb_DBDisConnect();

//������ ����
void wb_DBSendSelectData(TCHAR *msg);

void wb_DBSendOtherData(TCHAR* msg);
