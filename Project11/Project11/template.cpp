#include<iostream>
using namespace std;
/*
���ø� : ���� (�Լ� Ŭ����)�� ����� Ʋ
*/
//�����ε�
//int mycompare(int n1, int n2)
//{
//	return n1 - n2;
//}
//
//int mycompare(char ch1, char ch2)
//{
//	return ch1 - ch2;
//}
//
//int mycompare(double d1, double d2)
//{
//	return d1 - d2;
//}
//

//�Լ� ���ø�: �Լ��� ������ִ� Ʋ
//�����Ϸ��� �����Ǵ� Ʋ�� �̿��ؼ� �Լ��� �������
 template<typename T1>
 int mycompare(T1 n1, T1 n2)
 {
	 return n1 - n2;
 }

 template<typename T>
 T max(T n1, T n2)
 {
	 return (n1 > n2 ? n1 : n2);
 }


int main()
{
	cout << mycompare(10, 20) << endl;// ��� , 0 , ����
	cout << mycompare('a','C') << endl;
	cout << mycompare(10.2, 20.1) << endl;

	//�Ͻ���
	cout << max(10, 20) << endl;

	//�����
	cout << max<char>('A', 'a') << endl;
	return 0;
}
