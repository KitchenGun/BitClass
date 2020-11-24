using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ServiceModel;

namespace wcfConsole1124
{
    //서비스 계약 처리
    [ServiceContract]
    interface IHelloWorld
    {
        [OperationContract]
        string SayHello(); //인터페이스기 때문에 자동으로 Public Virtual

        void foo();// 외부 공개 안됨
    }
}
