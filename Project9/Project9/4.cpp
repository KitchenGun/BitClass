#include<iostream>
using namespace std;

class Graphic
{
public:
	virtual void Draw()
	{
		cout << "Graphic\t";
	}
};

class Line : public Graphic
{
public:
	void Draw()
	{
		cout << "Line\t";
	}
};

class Circle : public Graphic
{
public:
	void Draw()
	{
		cout << "Circle\t";
	}
};

class Rect : public Graphic
{
public:
	void Draw()
	{
		cout << "Rect\t";
	}
};



void main()
{
	Graphic* ar[10] = {
		 new Graphic(),new Rect(),new Circle(),new Rect(),new Line(),
		 new Line(),new Rect(),new Line(),new Graphic(),new Circle() };

	int i;

	for (i = 0; i < 10; i++) {
		ar[i]->Draw();	// 해당 도형명을 출력 ex) "Line" or "Circle" or "Rect"
	}

	for (i = 0; i < 10; i++) {
		delete ar[i];
	}
}