/************************************************************
 class
 -> 아래 코드를 객체 중심의 코드로 변경하시오.
*************************************************************/
#include <stdio.h>


typedef struct Rect
{
	int left;
	int top;
	int right;
	int bottom;


	int GetArea()
	{
		return (right - left) * (bottom - top);
	}

	bool PtInRect(int x, int y)
	{
		if (left < x && right > x &&
			top  < y && bottom > y)
			return true;
		return false;
	}

	void print()
	{
		printf("(%d, %d)~(%d, %d)\n", left, top, right, bottom);
	}

	void InflateRect(int dx, int dy)
	{
		right += dx;
		bottom += dy;
	}
}Rect;

void main()
{
	Rect r = { 10, 10,20,20 };

	r.InflateRect(10, 10);
	r.print();
	 
	int s = r.GetArea();

	if (r.PtInRect(15, 15))
		printf("(15,15) is In r\n");
}
