#include <stdio.h>
#include "app.h"
#include "sample.h"
//#전치리 키워드 컴파일러보다 먼저 처리
//전처리 과정이 끝나면 해당 문자은 사라진다.

int main()
{
	app_init();
	app_run();
	app_exit();

	return 0;
}

