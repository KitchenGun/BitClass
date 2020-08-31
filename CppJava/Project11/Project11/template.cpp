#include<iostream>
using namespace std;
/*
템플릿 : 무언가 (함수 클래스)를 만드는 틀
*/
//오버로딩
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

//함수 탬플릿: 함수를 만들수있는 틀
//컴파일러가 제공되는 틀을 이용해서 함수를 만들어줌
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
	cout << mycompare(10, 20) << endl;// 양수 , 0 , 음수
	cout << mycompare('a','C') << endl;
	cout << mycompare(10.2, 20.1) << endl;

	//암시적
	cout << max(10, 20) << endl;

	//명시적
	cout << max<char>('A', 'a') << endl;
	return 0;
}
