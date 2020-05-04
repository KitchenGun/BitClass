#include<iostream>

using namespace std;

int add(int n1, int n2, int n3 = 0, int n4 = 0)
{
	return n1 + n2 + n3 + n4;
}


int main()
{
	add(10, 20);
	add(10, 20, 30);
	add(10, 20, 30, 40);
	
	return 0;
}