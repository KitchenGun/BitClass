//참조 선언
void woo();

//extern
extern int g_num;//전역변수 선언이 아니라 존재를 알려주는 참조선언


void goo()
{
	g_num = 13;
	woo();
}


void woo()
{

}