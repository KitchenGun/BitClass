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
        static void Main(string[] args)
        {
            wbServer server = new wbServer();
            server.StartServer(9000);
        }
    }
}
