
#include<iostream>
using namespace std;
#include "accmanager.h"


int main()
{
	accManager* sm = new accManager();
	sm->Run();
	delete sm;

	return 0;
}