
   // ���α׷��� ���� Ŭ���� �̸��� ���� ����
   <%@ WebService Language="C#" Class="CalService" %>
using System;
using System.Web.Services;

// WebService Ŭ�������� �Ļ����� ����� Ŭ���� ����
public class CalService : WebService
{
    [WebMethod]     // �� �޼��� �Ӽ��� �����ٴ� ���� ���
    public float Add(int a, int b)
    {
        return a+b;
    }

    [WebMethod]     // �� �޼��� �Ӽ��� �����ٴ� ���� ���
    public float Sub(int a, int b)
    {
        return a-b;
    }
    [WebMethod]     // �� �޼��� �Ӽ��� �����ٴ� ���� ���
    public float Mul(int a, int b)
    {
        return a*b;
    }
    [WebMethod]     // �� �޼��� �Ӽ��� �����ٴ� ���� ���
    public float Div(int a, int b)
    {
        return (float)a / b;
    }
}