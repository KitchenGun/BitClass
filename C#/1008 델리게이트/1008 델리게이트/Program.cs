using System;

namespace _1008_델리게이트
{
    class Program
    {
        //델리게이트=클래스
        delegate float CalDel(int n1, int n2);
        
        static void Result(float f)
        {
            Console.WriteLine("결과값 : " + f);
        }
        static void Main(string[] args)
        {
            //2.등록
            Cal1 cal = new Cal1(Result);
            cal.Add(10, 20);
            cal.Mul(20, 30);
        }

        private static void NewMethod()
        {
            CalDel caldel = Cal.Div;
            Console.WriteLine(caldel(10, 20));
            Console.WriteLine(caldel.Invoke(10, 20));
        }
    }
}
