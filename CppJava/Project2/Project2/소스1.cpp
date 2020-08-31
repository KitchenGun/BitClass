//힌트 : sam::goo() 코드를 참고할 것
************************************************************* /
//네임스페이스
#include <iostream>
using namespace std;

namespace sam
{
	void goo() {
		cout << " sam::goo()" << endl;
	}
}
void foo()
{
	cout << " foo()" << endl;
}
namespace one
{
	void foo() {
		cout << " one::foo()" << endl;
	}
}
namespace two
{
	void foo() {
		cout << " two::foo()" << endl;
	}
}
int main()
{
	foo();			// global foo()
	sam::goo();		//sam::goo()
	one::foo();		// one::foo()
	two::foo();		// two::foo()

	return 0;
}
