#pragma once
//db�����Լ�
BOOL wb_DBConnect(TCHAR* ID, TCHAR* PW);
void wb_DBDisConnect();


int wb_InsertAccout(TCHAR* name, int money);

int GetAccid(TCHAR* name);
//ã�� �Լ�
TCHAR* wb_FindAccName(TCHAR* id);
int wb_FindAccBalance(TCHAR* id);

//���� �Լ�
BOOL wb_DeleteAcc(TCHAR* id);
//�����Լ�
BOOL wb_UpdateBalance(TCHAR* id, int value, bool flag);
//����Ʈ�� ���Կ� ����ü
BOOL wb_ListAllReset();