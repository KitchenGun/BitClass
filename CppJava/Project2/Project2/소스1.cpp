//��Ʈ : sam::goo() �ڵ带 ������ ��
************************************************************* /
//���ӽ����̽�
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
