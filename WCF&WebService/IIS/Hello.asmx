
   // ���α׷��� ���� Ŭ���� �̸��� ���� ����
   <%@ WebService Language="C#" Class="CalService" %>
using System;
using System.Web.Services;

// WebService Ŭ�������� �Ļ����� ����� Ŭ���� ����
public class CalService : WebService
{
    [WebMethod]     // �� �޼��� �Ӽ��� �����ٴ� ���� ���
    public string ShowHello()
    {
        return "Hello WebService!!";
    }
   
}

