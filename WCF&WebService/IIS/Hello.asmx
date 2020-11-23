
   // 프로그래밍 언어와 클래스 이름에 대한 선언
   <%@ WebService Language="C#" Class="CalService" %>
using System;
using System.Web.Services;

// WebService 클래스에서 파생시켜 사용자 클래스 정의
public class CalService : WebService
{
    [WebMethod]     // 웹 메서드 속성을 가진다는 것을 명시
    public string ShowHello()
    {
        return "Hello WebService!!";
    }
   
}

