#include<iostream>
//구조체 개선 문법

using namespace std;

struct tagdata
{

};

typedef struct tagdata1
{

}data1;

int main()
{
	//c
	struct tagdata d1;
	data1 d2;

	//c++    이제부터  struct 선언 안해도됨 
	tagdata d3;
	tagdata1 d4;

	return 0;
}
