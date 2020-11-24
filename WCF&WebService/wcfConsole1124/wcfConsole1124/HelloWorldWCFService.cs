using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace wcfConsole1124
{
    //서비스 객체 : 반드시 계약 인터페이스 상속
    class HelloWorldWCFService : IHelloWorld
    {
        public void foo()
        {
            throw new NotImplementedException();
        }

        public string SayHello()
        {
            return "Hello WCF World!"; 
        }
    }
}
