using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace _1012NETclient
{
    class WbClient
    {
        private Socket client;

        public void StartClient(int port)
        {
            try
            {
                //1. 소켓 생성 및 연결 
                CreateSocket(port);

                //2. Thread생성
                Thread thread = new Thread(new ThreadStart(RecvThread));
                thread.Start();// 스레드 실행

                //2. 통신 
                Run();
            }
            catch (Exception ex)
            {
                Console.WriteLine("[에러] " + ex.Message);
            }
        }

        private void CreateSocket(int port)
        {
            client = new Socket(AddressFamily.InterNetwork,
                                     SocketType.Stream, ProtocolType.Tcp);

            IPEndPoint ipep = new IPEndPoint(IPAddress.Parse("127.0.0.1"), port);
            client.Connect(ipep);  // 127.0.0.1 서버 7000번 포트에 접속시도
            Console.WriteLine("서버에 접속...");  // 만약 서버 접속이 실패하면 예외 발생
        }

        private void RecvThread()
        {
            byte[] recvbyte = null;

            while (true)
            {
                if (ReceiveData(ref recvbyte) == false)
                    break;
                Console.WriteLine("수신 데이터: " + Encoding.Default.GetString(recvbyte));
            }

            client.Close();
        }

        private void Run()
        {
            byte[] recvbyte = null;

            while (true)
            {
                if (Input(ref recvbyte) == false)
                    break;

                if (SendData(recvbyte) == false)
                    break;
            }

            client.Close();
        }

        private bool Input(ref byte[] data)
        {
            string msg = Console.ReadLine();
            if (msg == "")       //소켓 종료
                return false;
            else
            {
                data = Encoding.Default.GetBytes(msg);
                return true;
            }
        }

        private bool ReceiveData(ref byte[] data)
        {
            try
            {
                int total = 0;
                int size = 0;
                int left_data = 0;
                int recv_data = 0;

                // 수신할 데이터 크기 알아내기 
                byte[] data_size = new byte[4];
                recv_data = client.Receive(data_size, 0, 4, SocketFlags.None);
                size = BitConverter.ToInt32(data_size, 0);
                left_data = size;

                data = new byte[size];

                // 실제 데이터 수신
                while (total < size)
                {
                    recv_data = client.Receive(data, total, left_data, 0);
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

        private bool SendData(byte[] data)
        {
            try
            {
                int total = 0;
                int size = data.Length;
                int left_data = size;
                int send_data = 0;

                // 전송할 데이터의 크기 전달
                byte[] data_size = new byte[4];
                data_size = BitConverter.GetBytes(size);
                send_data = client.Send(data_size);

                // 실제 데이터 전송
                while (total < size)
                {
                    send_data = client.Send(data, total, left_data, SocketFlags.None);
                    total += send_data;
                    left_data -= send_data;
                }
                return true;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                return false;
            }
        }
    }
}