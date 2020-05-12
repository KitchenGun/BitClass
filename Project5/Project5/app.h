//app.h
#pragma once
#include"control.h"

class App
{
private:
	control* con;
public:
	App();
	~App();

public:
	void InitInstance();
	void Run();
	void ExitInstance();
private:
	void Logo();
	char Menuprint();
	void Ending();
};
