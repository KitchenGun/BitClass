using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace _1013NetClient
{
    class Control
    {
        #region 싱글톤
        //1. 생성자 은닉
        private Control() { }
        //2. 프로퍼티 선언
        static public Control Singleton { get; private set; }
        //3. static 생성자에서 객체 생성(단 한번 호출되는 문장)
        static Control()
        {
            Singleton = new Control();
        }
        #endregion

        Wb_client server = new Wb_client();

        public bool StartClient(string ip, int port)
        {
            return server.StartClient(ip, port);
        }

        #region 회원가입기능

        public void InsertMember()
        {
            Member mem = InputMember();

            //전송
            string packet = Packet.InsertMember(mem);
            server.SendData(packet);
        }

        //사용자 입력
        private Member InputMember()
        {
            Console.Write("ID : ");
            string id = Console.ReadLine();

            Console.Write("PW : ");
            string pw = Console.ReadLine();

            Console.Write("Name : ");
            string name = Console.ReadLine();

            Console.Write("Age : ");
            int age = int.Parse(Console.ReadLine());

            return new Member(id, pw, name, age);
        }

        #endregion

        #region 로그인
        public void LoginMember()
        {
            string id, pw;
            LoginMember(out id, out pw);

            //전송
            string packet = Packet.LoginMember(id, pw);
            server.SendData(packet);
        }

        private void LoginMember(out string id, out string pw)
        {
            Console.Write("ID : ");
            id = Console.ReadLine();

            Console.Write("PW : ");
            pw = Console.ReadLine();
        }

        #endregion

        #region 로그아웃
        public void LogOutMember()
        {
            string id;
            LogOutMember(out id);

            //전송
            string packet = Packet.LogOutMember(id);
            server.SendData(packet);
        }

        private void LogOutMember(out string id)
        {
            Console.Write("ID : ");
            id = Console.ReadLine();
        }
        #endregion

        #region 회원탈퇴
        public void DelMember()
        {
            string id;
            DelMember(out id);

            //전송
            string packet = Packet.DelMember(id);
            server.SendData(packet);
        }

        private void DelMember(out string id)
        {
            Console.Write("ID : ");
            id = Console.ReadLine();
        }
        #endregion

        #region 수신 데이터
        public void RecvData(byte[] data)
        {
            string msg = Encoding.Default.GetString(data);

            string[] filter = msg.Split('\a');
            if (filter[0].Equals("ACK_INSERTMEMBER") == true)
            {
                Ack_InsertMember(filter[1]);
            }
            else if (filter[0].Equals("ACK_LOGINMEMBER") == true)
            {
                Ack_LoginMember(filter[1]);
            }
            else if (filter[0].Equals("ACK_LOGOUTMEMBER") == true)
            {
                Ack_LogOutMember(filter[1]);
            }
        }

        private void Ack_InsertMember(string msg)
        {
            string[] filter = msg.Split('#');

            if (filter[0].Equals("F"))
            {
                Console.WriteLine("회원가입 실패");
                return;
            }

            Console.WriteLine("회원가입결과 : ID:{0}, NAME:{1}",
                filter[1], filter[2]);
        }

        private void Ack_LoginMember(string msg)
        {
            string[] filter = msg.Split('#');

            if (filter[0].Equals("F"))
            {
                Console.WriteLine("로그인 실패");
                return;
            }

            Member mem = new Member()
            {
                Id = filter[1],
                Pw = filter[2],
                Name = filter[3],
                Age = int.Parse(filter[4]),
                Dt = DateTime.Parse(filter[5])
            };
            Console.WriteLine("로그인 성공 : " + mem);
           
        }

        private void Ack_LogOutMember(string msg)
        {
            if (msg.Equals("F"))
            {
                Console.WriteLine("로그아웃 실패");
            }
            else
            {
                Console.WriteLine("로그아웃 성공");
            }
        }
        #endregion
    }
}