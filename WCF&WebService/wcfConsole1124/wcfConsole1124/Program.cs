﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ServiceModel;
using System.ServiceModel.Description;

/*[wcf] 서비스 구축
 * 1. c# 콘솔 프로젝트 생성
 * 2. wcf 서비스  프레임 워크를 사용하려면 참조 추가 및 using 처리가 필요하다
 * 참조추가 System.Service Model 어셈블리 추가
 * --------------------------------------------------------------------------------------------
 * 3. 인터페이스를 정의하기 위해서 IHelloWorld 인터페이스 생성 새항목에서  인터페이스 추가 - 계약 정의
 * 4. 계약을 이용해서 서비스 객체를 구현
 * HelloWorldWCFService 클래스 생성
 * ---------------------------------------------------------------------------------------------------
 * 5. exe 기반의 호스팅 코드 작성 
 * 
 */

namespace wcfConsole1124
{
    class Program
    {
        //hosting 코드(http 기반 endpoint)
        static void Hosting1()
        {
            //Service Host 객체 (호스팅 객체
            //1.서비스 객체
            //2.주소 (접두어 : http,tcp)
            ServiceHost host = new ServiceHost(typeof(HelloWorldWCFService), new Uri("http://localhost:8080/wcf/example/helloworldservice"));
            //호스트에 EndPoint(종점을 추가한다)
            host.AddServiceEndpoint(
                 typeof(IHelloWorld),             //Contract(계약) <-서비스 객체 부모였던 인터페이스
                 new BasicHttpBinding(),       //Binding(바인딩) <- xmlwebservice 와 100% 동일
                 "");                                        //Address(주소) <- 공백일때는 서비스 객체의 생성시 사용주소
            //==========================WSDL 문서 제공하는 코드 추가===============================
            ServiceMetadataBehavior behavior =
                host.Description.Behaviors.Find<ServiceMetadataBehavior>();
            if (behavior == null)
            {
                behavior = new ServiceMetadataBehavior();
                host.Description.Behaviors.Add(behavior);
            }
            behavior.HttpGetEnabled = true;
            //=================================================================================

            //호스팅 시작
            host.Open();
            Console.WriteLine("Press Any Key to stop the service");
            Console.WriteLine("address : " + "http://localhost:8080/wcf/example/helloworldservice");
            Console.ReadKey(true);
            //host 종료
            host.Close();
        }

        //hosting 코드()
        static void Hosting2()
        {
            //Service Host 객체 (호스팅 객체
            //1.서비스 객체
            //2.주소 (접두어 : http,tcp) 주소를 2개
            ServiceHost host = new ServiceHost(typeof(HelloWorldWCFService), 
                new Uri("http://localhost:8080/wcf/example/helloworldservice"), 
                new Uri("net.tcp://localhost:8080/wcf/example/helloworldservice"));
            //호스트에 EndPoint(종점을 추가한다)
            host.AddServiceEndpoint(
                 typeof(IHelloWorld),             //Contract(계약) <-서비스 객체 부모였던 인터페이스
                 new BasicHttpBinding(),       //Binding(바인딩) <- xmlwebservice 와 100% 동일
                 "");                                        //Address(주소) <- 공백일때는 서비스 객체의 생성시 사용주소

            host.AddServiceEndpoint(
                typeof(IHelloWorld),             //Contract(계약) <-서비스 객체 부모였던 인터페이스
                new NetTcpBinding(),       //Binding(바인딩) <- xmlwebservice 와 100% 동일
                "");                                        //Address(주소) <- 공백일때는 서비스 객체의 생성시 사용주소
            //==========================WSDL 문서 제공하는 코드 추가===============================
            ServiceMetadataBehavior behavior =
                host.Description.Behaviors.Find<ServiceMetadataBehavior>();
            if (behavior == null)
            {
                behavior = new ServiceMetadataBehavior();
                host.Description.Behaviors.Add(behavior);
            }
            behavior.HttpGetEnabled = true;
            //=================================================================================

            //호스팅 시작
            host.Open();
            Console.WriteLine("Press Any Key to stop the service");
            Console.WriteLine("address : " + "http://localhost:8080/wcf/example/helloworldservice");
            Console.ReadKey(true);
            //host 종료
            host.Close();
        }

        //Config파일을 이용하여 Hosting1코드 수정
        static void Hosting3()
        {
            //1. ServiceHost 객체(호스팅 객체)
            //1) 서비스 객체             
            ServiceHost host = new ServiceHost(typeof(HelloWorldWCFService));

            //============= WSDL 문서 제공하는 코드 추가 ======================
            //config 파일로 이동

            //3. 호스트 시작
            //   서비스 객체를 정의할 때 전달한 서비스 객체명을 config파일에서 검색 후 설정
            host.Open();

            Console.WriteLine("Press Any key to stop the service");
            Console.WriteLine("address : " + "http://localhost:8080/wcf/example/helloworldservice");
            Console.ReadKey(true);

            //4. 호스트 종료
            host.Close();
        }

        static void Main(string[] args)
        {
            Hosting3();
        }
    }
}
