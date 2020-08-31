#include<iostream>

//참조자 == 별명

using namespace std;

void exam1()
{
	int num = 10;
	int& rnum = num;//rnum 레퍼런스:=>:num 변수의 별명

	//=========================
	cout << rnum << endl;

	rnum = 20;
	cout << num << endl;

	cout << &rnum << endl;
	cout << &num << endl;
}

void exam2_1(int n1 ,int* n2, int& n3)//값, 주소값, 참조자
{
	n1 = 20;
	//매개변수 수정
	*n2 = 30;//스텍 메모리에 있는 num1변수를 수정
	n3 = //n3는 스택메모리에 있는 num1의 별칭
}

void exam2()
{//참조자 사용예
	//매개변수 전달
	/*
	값전달 call by value
	주소값 전달 call by address//원본 값 변경목적
	참조자 전달 call by reference// 원본 전달과 동일한 결과 얻음
	*/

	int num1 = 10;
	exam2_1(num1, &num1, num1);
	cout << num1 << endl;
}

int arr[3] = { 1,2,3 };//전역변수 함수밖 전역변수 ->전역 정적메모리에 생성

int exam3_1(int idx)
{
	return arr[idx];
}

int& exam3_2(int idx)
{
	return arr[idx];
}
void exam3()
{
	int n1 = exam3_1(2); //int n1 =30
	cout << n1 << endl;

	int n1 = exam3_2(2);//int n1 =arr[2]
	cout << n1 << endl;
	//======================================
	//exam3_1(2) = 200;//30=200//함수의 호출은 대입연산 Rvalue에서 이뤄진다
	exam3_2(2) = 200;//arr[2]=200

	cout << arr[0] << "," << arr[1] << "," << arr[2] << endl;
}

int main()
{
	exam3();

	return 0;
}