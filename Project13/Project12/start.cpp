#include<iostream>
using namespace std;
#include "stumanager.h"
//p87

int main()
{
	stuManager* sm = new stuManager();
	sm->Run();
	delete sm;

	return 0;
}

