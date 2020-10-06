using System;

namespace _1005
{
    /// <summary>
    /// 첫번째 만드는 실습코드
    /// </summary>
    class Program
    {
        #region 기본문법 이해
        //출력
        static void exam1()
        {
            Console.WriteLine("Hello World!");
        }
        //입력기능 Console.Read();
        static void exam2()
        {
            Console.WriteLine("input : ");
            int number = Console.Read();//문자를 입력받는 전용함수
            //문자를 받는다
            Console.WriteLine("result : {0}={1}", (char)number,number);
            // string + int = string + string
            Console.WriteLine("result : "+ number);
        }
        //입력기능 Console.ReadLine(); string 전용 함수 모든 타입 입력 처리
        static void exam3()
        {
            Console.Write("이름 : ");
            string name = Console.ReadLine();
            Console.Write("나이 : ");
            string tempage = Console.ReadLine();
            int age = int.Parse(tempage);
            Console.Write("몸무게 : ");
            float weight = float.Parse(Console.ReadLine());
            Console.Write("성별 : ");
            string tempgender = Console.ReadLine();
            char gender = tempgender[0];
            Console.ReadLine();
            Console.Write("성별 : ");
            char gender1 = Console.ReadLine()[0];
            Console.WriteLine(">>  이름  {0}", name);
            Console.WriteLine(">>  나이  {0}", age);
            Console.WriteLine(">>  몸무게  {0}", weight);
            Console.WriteLine(">>  성별(한) {0}", gender);
            Console.WriteLine(">>  성별(영) {0}", gender1);
        }
        //입력기능 Console.ReadKey(); 특수키를 입력 받을때
        static void exam4()
        {
            ConsoleKeyInfo info = Console.ReadKey();
            if(info.Key== ConsoleKey.F1)
            {
                Console.WriteLine("F1눌러짐");
            }
            else if(info.KeyChar == 'c')
            {
                Console.WriteLine("c눌러짐");
            }
        }
        //변수 값형식과 참조 형식  = =====================================
        //값형식
        static void exam5()
        {
            int num; //저장공간 생성  : 스택 메모리
            num = 10;
            Console.WriteLine("num : "+num);
        }
        //참조 형식 : 클래스 배열 ,,, string(참조 형식이지만 값 형식 처럼)
        static void exam6()
        {
            Program pr; //program을  저장할 공간 생성 (x)//program의 주소를 저장한 공간 생성(0)
            pr = new Program();//new 연산자를 통해서 program저장공간 생성 //생성된 공간 주소를 pr이 저장

            //delete pr;    //delete 연산자 없다 가비지가 알아서 제거

        }
        //string 
        static void exam7()
        {
            char[] chars = { 'a', 'b', 'c' };
            string str1 = "aaa";
            String str2 = new String(chars);

            Console.WriteLine(str1 + str2);
        }
        //objcet 참조 타입 (클래스) 반드시 주소값을 가지고 있어야함
        static void exam8()
        {
            int num = 10;
            Object obj1 = num;
            
            Program pro = new Program();
            Object obj2 = pro;
        }
        //모든 타입은 문자열과 변환연산이 가능하다
        //int -> string : toString()
        //string -> int : parse()
        static void exam9()
        {
            string temp = "12.123";
            float f = float.Parse(temp);

            string temp1 = f.ToString();
        }
        //nullable
        static void exam10()
        {
            int? num1 = 10;
            num1 = 20;
            num1 = 30;
            Console.WriteLine("NUM1의 값 : " + num1);
            num1 = null;
            Console.WriteLine("NUM1의 값 : " + num1);
        }
        //object 와 var 
        static void exam11()
        {
            var ar = 10;
            int arvalue = ar;
            Console.WriteLine(ar);
            //var 이 char타입됨
            var ar1 = 'A';
            char ch = ar1;
            //boxing
            Object obj1 = 10;
            int value = (int)obj1; // int = (int)object
            //var test
            var i = 1;
            var f = 1.1;
            Console.WriteLine(i + f);
        }
        //-------------------------------------------------------------------------
        static void exam12_fun1(int number)//값 불러오기
        {
            number = 20;
        }
        static void exam12_fun2(ref int number)//ref    함수 호출 과정에서 값을 변경할수도 있고 변경하지 않아도 된다.
        {
            number = 20;
        }
        static void exam12_fun3(out int number)//out    함수 호출과정에서 반드시 값을 변경해야한다.
        {
            number = 30;
        }
        static void exam12()
        {
            int num = 10;
            exam12_fun1(num);
            Console.WriteLine(num);
            exam12_fun2(ref num);
            Console.WriteLine(num);
            exam12_fun3(out num);
            Console.WriteLine(num);
        }
        static void exam13_fun1(int n1, ref int n2, out int n3)
        {
            Console.WriteLine(n2);
            n3 = 0;
        }
        //값 전달  : 반드시 초기화된 변수를 전달
        //ref 전달 : 반드시 초기화 된 변수를 전달
        //out전달 : 초기화 안한 변수를 전달할 수 있다.
        static void exam13()
        {
            int num1=0;
            int num2=0;
            int num3;
            exam13_fun1(num1, ref num2, out num3);
        }

        static void examTest()
        {
        }
        #endregion

        #region member 클래스 사용
        static void exam14()
        {
            Member mem1 = new Member("홍길동");
            Member mem2 = new Member("김길동","010-0000-0000");
            mem1.Print();
            mem2.Print();
            Console.WriteLine("================================");
            mem1.setPhone("010-1234-5896");
            mem1.Print();
            Console.WriteLine("홍길동의 전화번호" + mem1.getPhone());
        }
        static void exam15()
        {
            Member2 mem1 = new Member2("홍길동",MemberType.STUDENT);
            Member2 mem2 = new Member2("김길동", MemberType.EMP,"010-0000-0000");
            mem1.Print();
            mem2.Print();
            Console.WriteLine("================================");
            mem1.Phone="010-1234-5896";
            mem1.Print();
            Console.WriteLine("홍길동의 전화번호" + mem1.Phone);
        }
        #endregion
        static void Main(string[] args)
        {
            exam14();
        }
    }
}
