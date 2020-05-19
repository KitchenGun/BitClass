#include <iostream>

using namespace std;

class Sample
{
public:
	void Test()
	{
		cout << this << endl;
	}
};

int main()
{
	Sample sam;
	cout << &sam << endl;
	sam.Test();
	return 0;
}