#include<iostream>
#include<time.h>
//동적 메모리

using namespace std;

/*
malloc & free
*/


// 정수값을 1개 저장할 공간을 힙에 만들고 싶다

void exam1()
{
	int* pnum = (int*)malloc(sizeof(int));

	*pnum = 10;

	free(pnum);
}

//동적 배열 생성
void exam2()
{
	srand((unsigned int)time(0));

	int max;
	cout << "문자저장할 최대 크기";
	cin >> max;
	 
	char* parr = (char*)malloc(sizeof(char) * max);

	for (int i = 0; i < max; i++)
	{
		char ch = rand() % 26 + 'A';
		parr[i] = ch;
	}

	for (int i = 0; i < max; i++)
	{
		cout << parr[i];
	}
	cout << endl;

	free(parr);
}

void exam3()
{
	int* pnum = new int;//정수값 저장공간 1개 생성

	*pnum = 10;

	delete pnum;
	//
	char* pch1 = new char('A');//문자를 저장할수있는 공간 1개 생성 'A'로 초기화
	cout << *pch1 << endl;
	delete pch1;
	//
	cout << "몇개";
	int max;
	cin >> max;
	char* pch2 = new char[max];//sizeof(char)*max

	for (int i = 0; i < max; i++)
	{
		char ch = rand() % 26 + 'A';
		pch2[i] = ch;
	}

	for (int i = 0; i < max; i++)
	{
		cout << pch2[i];
	}
	cout << endl;

	delete[] pch2;
}

int main()
{
	exam3();
	return 0;
}
