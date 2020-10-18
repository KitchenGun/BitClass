using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//c# thread는 생성된 모든 thread가 종료되어야만 main thread가 죽는다.
//만약 main이 죽으면 모든 thread를 죽이기 위해서는 thread의 속성값을 변경해야한다.
//thread.IsBackground = true;
namespace _1012Net
{
    class Program
    {
        public bool Init()
        {
            Logo();
            return Control.Singleton.Init();//run 관련 코드가 여기 안에 있음
        }
     
        public void Exit()
        {
            Control.Singleton.Exit();
            Ending();
        }

        public void Logo()
        {
            Console.WriteLine("***************************************************");
            Console.WriteLine(" 서버 시작");
            Console.WriteLine(" 서버 IP   : 61.81.98.100");
            Console.WriteLine(" 서버 PORT : 9000");
            Console.WriteLine("***************************************************\n");
        }

        public void Ending()
        {
            Console.WriteLine("***************************************************");
            Console.WriteLine("서버를 종료합니다.");
            Console.WriteLine("***************************************************");
        }

        static void Main(string[] args)
        {
            Program pr = new Program();
            if (pr.Init() == false)
                pr.Exit();
        }
    }
}
