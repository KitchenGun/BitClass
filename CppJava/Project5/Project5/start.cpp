//start.c

#include <iostream>
using namespace std;
#include"app.h"

int main()
{
	App app;
	app.InitInstance();
	app.Run();
	app.ExitInstance();

	return 0;
}
