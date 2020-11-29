using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ServiceModel;
using System.Configuration;

namespace _1125WCFChat
{
    class Program
    {

        static void hosting()
        {
            //System.Configuration 어셈블리 추가
            Uri uri = new Uri(ConfigurationManager.AppSettings["addr"]);

            //1. ServiceHost 객체(호스팅 객체)
            //1) 서비스 객체             
            ServiceHost host = new ServiceHost(typeof(ChatService), uri);
            host.Open();

            Console.WriteLine("Press Any key to stop the service");
            Console.WriteLine("address : " + uri.ToString());
            Console.ReadKey(true);

            //4. 호스트 종료
            host.Abort();
            host.Close();

        }
        static void Main(string[] args)
        {
            hosting();
        }
    }
}
