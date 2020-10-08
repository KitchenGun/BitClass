﻿using System;
using System.Collections.Generic;
using System.Text;

namespace _1008_델리게이트
{
    class Cal
    {
        public static float Add(int n1, int n2)
        {
            return (float)n1 + n2;
        }

        public static float Sub(int n1, int n2)
        {
            return (float)n1 - n2;
        }

        public static float Mul(int n1, int n2)
        {
            return (float)n1 * n2;
        }

        public static float Div(int n1, int n2)
        {
            if (n2 == 0)
                new Exception("0으로 나눌 수 없습니다.");
            return (float)n1 / n2;
        }


    }
    //delegate 정의[callback]미리 함수를 등록 시키고 호출
    delegate void CalResult(float f);

    class Cal1
    {
        //2.delegate 레퍼런스 변수 선언
        private CalResult calResultDel = null;
        public Cal1(CalResult r)
        {
            //3.전달된 함수를 delegate에 저장
            calResultDel = r;//callback함수 등록
        }
        public void Add(int n1, int n2)
        {
            float fresult = (float)n1 + n2;
            //4.콜백 호출
            calResultDel(fresult);
        }

        public void Sub(int n1, int n2)
        {
            float fresult = (float)n1 - n2;  
            //4.콜백 호출
            calResultDel(fresult);
        }

        public void Mul(int n1, int n2)
        {
            float fresult = (float)n1 * n2;
            //4.콜백 호출
            calResultDel(fresult);
        }

        public void Div(int n1, int n2)
        {
            if (n2 == 0)
                new Exception("0으로 나눌 수 없습니다.");
            float fresult = (float)n1 / n2;
            //4.콜백 호출
            calResultDel(fresult);
        }


    }
}
