#pragma once
//db접속함수
BOOL wb_DBConnect(TCHAR* ID, TCHAR* PW);
void wb_DBDisConnect();


int wb_InsertAccout(TCHAR* name, int money);

int GetAccid(TCHAR* name);
//찾는 함수
TCHAR* wb_FindAccName(TCHAR* id);
int wb_FindAccBalance(TCHAR* id);

//삭제 함수
BOOL wb_DeleteAcc(TCHAR* id);
//수정함수
BOOL wb_UpdateBalance(TCHAR* id, int value, bool flag);
//리스트에 삽입용 구조체
BOOL wb_ListAllReset();