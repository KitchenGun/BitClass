using System;
using System.Collections.Generic;
using System.Text;

namespace _1012Net
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

        private Dictionary<string, Member> memlist = new Dictionary<string, Member>();
        wbServer server = new wbServer();
        #region wbserver에서 수신된 데이터 처리
        public byte[] RecvData(byte[] recvbyte)
        {
            string msg = Encoding.Default.GetString(recvbyte);

            string[] filter = msg.Split('\a');
            if (filter[0].Equals("PACKET_INSERTMEMBER") == true)
            {
                return InsertMember(filter[1]);
            }
            return Encoding.Default.GetBytes("NON");
        }

        private byte[] InsertMember(string msg)
        {
            string[] filter = msg.Split('#');
            Member mem = new Member()
            { 
                ID = filter[0],
                PW=filter[1],
                Name = filter[2],
                Age=int.Parse(filter[3]),
                Dt = DateTime.Parse(filter[4])
            };
            //저장
            memlist.Add(filter[0], mem);

            //리턴 패킷 생성 반환(ID, NAME)
            return Packet.InsertMember(mem.ID, mem.Name);
        }
        #endregion

        public bool Init()
        {
            return server.StartServer(9000);
        }

        public void Exit()
        {

        }
    }
}
