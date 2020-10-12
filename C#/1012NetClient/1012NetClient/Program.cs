using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1012NetClient
{
    class Program
    {
        static void Main(string[] args)
        {
            wbClient client = new wbClient();
            client.StartClient(9000);
        }
    }
}
