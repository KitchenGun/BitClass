#pragma comment (linker, "/subsystem:console")
//���� ���� //Ŀ�� ������Ʈ ���μ����� ���μ����� ����ȭ�� ������
#include<Windows.h>
#include<stdio.h>


void main()
{
	//ī��Ʈ�� 0���� ũ�� ���	0�̸� nonsignal 0 ���� ũ�� signal
	HANDLE hSemaphore = CreateSemaphore(0, // ����
		3, // count �ʱⰪ
		3, // �ִ� count
		TEXT("s")); // �̸�

	printf("������� ����մϴ�.\n");
	WaitForSingleObject(hSemaphore, INFINITE); //--count
	printf("���� ��� ȹ��\n");
	MessageBox(0, TEXT("Release??"), TEXT(""), MB_OK);
	LONG old;
	ReleaseSemaphore(hSemaphore, 1, &old); // ++count 
	CloseHandle(hSemaphore);
}
// �޼��� Box �� OK�� ������ ����.. 4�� �̻� ������ ������..