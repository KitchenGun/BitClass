/************************************************************
main 함수에 에러가 없도록 코드를 완료하시오.
*************************************************************/
//캡슐화
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
		cout << "국어 : " << kor << endl;
		cout << "영어 : " << eng << endl;
		cout << "합    : " << sum << endl;
		printf("평균 : %.1f", average);
	}
};


int main()
{
	Jumsu j1;
	j1.setKor(100);    //kor 점수에 대입
	j1.setEng(95);     //eng  점수에 대입
	j1.setSum();       //저장된 eng점수와 kor점수의 합의 결과를 sum에 저장
	j1.setAverage();  // sum에 저장된 점수를 2로 나눈 결과값을 average에 저장
	cout << "총합 : " << j1.getSum() << endl;  //sum에 저장된 값을 반환
	j1.Print();        //아래와 같이 출력
					  //국어 : 100
					  //영어 : 95
					  //합    : 195
					  //평균 : 92.5 


	return 0;
}
