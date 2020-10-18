using System;

namespace _1013NetClient
{
    class Program
    {
        public bool StartClient(string ip, int port)
        {
            return Control.Singleton.StartClient(ip, port);
        }
        public void Run()
        {
            while(true)
            {
                Console.Clear();
                MenuPrint();
                switch(Console.ReadKey().Key)
                {
                    case ConsoleKey.Escape: return;
                    case ConsoleKey.F1: Control.Singleton.InsertMember();              break;
                    case ConsoleKey.F2:Control.Singleton.LoginMember();                  break;
                    case ConsoleKey.F3: Control.Singleton.LogOutMember();               break;
                    case ConsoleKey.F4: Control.Singleton.DelMember();                      break;
                }
                Console.WriteLine("\n\n아무키나 누르세요.....");
                Console.ReadKey();
            }
              //string buf = string.Empty;
            //while (true)
            //{
            //    if (InputData(ref buf) == false)
            //        break;
            //
            //    if (server.SendData(buf) == false)
            //        break;
            //}
            //
            //server.EndClient();
        }

        private bool InputData(ref string buf)
        {
            Console.WriteLine("[문자열입력]");
            buf = Console.ReadLine();
            if (buf == string.Empty)
                return false;

            if (buf.Length > 1024)
                throw new Exception("문자열의 크기가 너무 큽니다.");

            return true;
        }

        private void MenuPrint()
        {
            Console.WriteLine("========================================================================================");
            Console.WriteLine("[ESC]  종료 [F1] 회원가입  [F2] 로그인    [F3] 로그아웃    [F4] 회원탈퇴");
            Console.WriteLine("========================================================================================");
        }


        static void Main(string[] args)
        {
            Program pr = new Program();  
            if(pr.StartClient("61.81.98.100", 9000) == true)
                pr.Run();
        }
    }
}
