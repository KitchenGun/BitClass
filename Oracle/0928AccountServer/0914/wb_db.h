//wb_db.h
#pragma once

//DB ���� �� ���� ����-���۰� ������� ȣ��
BOOL wb_DBConnect(TCHAR *id, TCHAR* pw);
void wb_DBDisConnect();

BOOL wb_dbInsertAccount(ACCOUNT *pacc);
BOOL wb_dbSelectNameToId(PACK_GETNAME* pdata);
BOOL wb_dbSelectAccount(PACK_ACCOUNTINFO *pacc);
