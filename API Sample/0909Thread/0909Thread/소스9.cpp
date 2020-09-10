#pragma comment (linker, "/subsystem:console")
//���ؽ�//Ŀ�� ������Ʈ ���μ����� ���μ����� ����ȭ�� ������
#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
	// ���ؽ� ����
	//���� ���� ��ü�� �ٽ� create�ϰ� �Ǹ� open ���� �������ش�
	HANDLE hMutex = CreateMutex(NULL, // ���ȼӼ�
														FALSE, // ������ ���ؽ� ���� ����
														TEXT("mutex")); // �̸�
		// ������ ture�϶� -> Signal �� nonsignal�� �ٲ۴�.
	cout << "���ý��� ��ٸ��� �ִ�." << endl;
	//wait for �� �����ϸ� �ش� ��ü�� ���°��� non_s ����
	DWORD d = WaitForSingleObject(hMutex, INFINITE); // ���
	if (d == WAIT_TIMEOUT)
		MessageBox(NULL, TEXT("WAIT_TIMEOUT"), TEXT(""), MB_OK);
	else if (d == WAIT_OBJECT_0)
		MessageBox(NULL, TEXT("WAIT_OBJECT_0"), TEXT(""), MB_OK);
	else if (d == WAIT_ABANDONED_0)//������ ���ؽ��� ������ ���¿��� ���� ���
		MessageBox(NULL, TEXT("WAIT_ABANDONED_0"), TEXT(""), MB_OK);
	cout << "���ý� ȹ��" << endl;
	MessageBox(NULL, TEXT("���ý��� ���´�."), TEXT(""), MB_OK);
	ReleaseMutex(hMutex);//���ؽ� ����

	return 0;
}