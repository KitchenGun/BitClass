using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Threading;
using System.Net;

namespace _1012NetClient
{
    class wbClient
    {
        private Socket client;
        public bool StartClient(int port)
        {
            try
            {
                //생성
                CreateSocket(port);
                Thread thread = new Thread(new ThreadStart(RecvThread));
                thread.Start();//스레드 실행
                //통신
                Send();
                return true;
            }
            catch (Exception ex)
            {
                Console.WriteLine("[에러]" + ex.Message);
                return false;
            }
        }

        #region client 내부적으로 호출하는 함수
        private void CreateSocket(int port)
        {
            try
            {
                //1.소켓 생성
                client = new Socket(AddressFamily.InterNetwork,
                                         SocketType.Stream, ProtocolType.Tcp);

                //2.연결
                IPEndPoint ipep = new IPEndPoint(IPAddress.Parse("127.0.0.1"), port);
                client.Connect(ipep);

                Console.WriteLine("서버에 접속...");  // 만약 서버 접속이 실패하면 예외 발생
                Console.Write("[전송] : ");
            }
            catch (Exception ex)
            {
                Console.WriteLine("서버연결 실패 : " + ex);
            }
        }

        private void RecvThread()
        {
            
                byte[] recvbyte = null;
                try
                {
                     while (true)
                     {
                         if (ReceiveData(client, ref recvbyte) == false)
                         {
                             break;
                         }

                         string msg = Encoding.Default.GetString(recvbyte);
                    Console.WriteLine("");
                         Console.WriteLine("[수신]" + msg);
                         Console.Write("[전송] : ");
                     }
                }
                catch (Exception ex)
                {
                    Console.WriteLine("[RecvThread에러]" + ex.Message);
                }
        }
        public void Send()
        {
            string msg =null;
            while (true)
            {
                //수신
                if (MsgInput(ref msg) == false)
                {
                    break;
                }
                else
                {
                    SendData(client, Encoding.Default.GetBytes(msg));
                }
            }
        }

        public bool MsgInput(ref string msg)
        {
            msg = Console.ReadLine();
            if (msg == null)
                return false;
            else
                return true;
        }
        #endregion

        #region 수신&송신
        //크기 + 데이터  전송
        private bool ReceiveData(Socket sock, ref byte[] data)
        {
            try
            {
                int total = 0;
                int size = 0;
                int left_data = 0;
                int recv_data = 0;

                // 수신할 데이터 크기 알아내기 
                byte[] data_size = new byte[4];
                recv_data = sock.Receive(data_size, 0, 4, SocketFlags.None);
                size = BitConverter.ToInt32(data_size, 0);
                left_data = size;

                data = new byte[size];

                // 실제 데이터 수신
                while (total < size)
                {
                    recv_data = sock.Receive(data, total, left_data, 0);
                    if (recv_data == 0) break;
                    total += recv_data;
                    left_data -= recv_data;
                }
                return true;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                return false;
            }
        }

        private void SendData(Socket sock, byte[] data)
        {
            try
            {
                int total = 0;
                int size = data.Length;
                int left_data = size;
                int send_data = 0;

                // 전송할 데이터의 크기 전달
                byte[] data_size = new byte[256];
                data_size = BitConverter.GetBytes(size);
                send_data = sock.Send(data_size);

                // 실제 데이터 전송
                while (total < size)
                {
                    send_data = sock.Send(data, total, left_data, SocketFlags.None);
                    total += send_data;
                    left_data -= send_data;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        #endregion
    }
}