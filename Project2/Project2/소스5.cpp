/************************************************************
main �Լ��� ������ ������ �ڵ带 �Ϸ��Ͻÿ�.
*************************************************************/
//ĸ��ȭ
#include <iostream>
using namespace std;

struct Jumsu
{
	int kor;
	int eng;
	int sum;
	float average;
	void setKor(int score)
	{
		kor = score;
	}
	void setEng(int score)
	{
		eng = score;
	}
	void setSum()
	{
		sum = kor + eng;
	}

	void setAverage()
	{
		average = sum / 2.0f;
	}

	int getSum()
	{
		return sum;
	}

	void Print()
	{
		cout << "���� : " << kor << endl;
		cout << "���� : " << eng << endl;
		cout << "��    : " << sum << endl;
		printf("��� : %.1f", average);
	}
};


int main()
{
	Jumsu j1;
	j1.setKor(100);    //kor ������ ����
	j1.setEng(95);     //eng  ������ ����
	j1.setSum();       //����� eng������ kor������ ���� ����� sum�� ����
	j1.setAverage();  // sum�� ����� ������ 2�� ���� ������� average�� ����
	cout << "���� : " << j1.getSum() << endl;  //sum�� ����� ���� ��ȯ
	j1.Print();        //�Ʒ��� ���� ���
					  //���� : 100
					  //���� : 95
					  //��    : 195
					  //��� : 92.5 


	return 0;
}
