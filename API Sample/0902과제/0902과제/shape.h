#pragma once
//도형 관리 프로그램
/*
[구현 순서]
1. 도형 타입 정의
2. 전역 변수 선언
   저장변수, 현재 설정 정보 관리 변수
3. 전역 변수의 초기하
4. 현재 설정 정보 변수의 수정 기능
   수정된 결과를 눈으로 확인하기 위해 타이틀바에 출력
5. 도형을 출력하는 기능
   현재 설정 정보를 이용해서
*/
#include <Windows.h>
#include<tchar.h>
#include<vector>
using namespace std;

typedef struct tagSHAPE
{
	POINT pt;//좌표
	int size; //크기(25,50,75,100)
	COLORREF b_color;
	COLORREF p_color;	//펜 색상
	int type;			//타입(사각형, 타원, 삼각형)
}SHAPE;


