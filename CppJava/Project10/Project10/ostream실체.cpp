#include<stdio.h>

namespace mystd
{
	class myostream
	{
	public:
		myostream& operator<<(int value)
		{
			printf("%d", value);
			return *this;
		}
		myostream& operator<<(const char*value)
		{
			printf("%s", value);
			return *this;
		}
		myostream& operator<<(double value)
		{
			printf("%.1f", value);
			return *this;
		}
	};

	myostream mycout;
}

using namespace mystd;

int main()
{
	mycout << 10<<","<<10.1f;
	return 0;
}