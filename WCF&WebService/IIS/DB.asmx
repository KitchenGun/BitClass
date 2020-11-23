<%@ WebService Language="C#" Class="DBSaveService" %>

using System;
using System.Collections.Generic;
using System.Web;
using System.Web.Services;
using System.Text;
using System.Data;
using System.Data.SqlClient;

public class DBSaveService : WebService
{
    public Boolean DBLogin { get; set; }
    public string ConMsg { get; private set; }
    private SqlConnection scon;

    public DBSaveService()
    {
        //DB 접근
        DBLogin = false;
        ConMsg = @"Data Source =DESKTOP-4IV1O4J\SQLEXPRESS;Initial Catalog=WbDB; User ID=kangkeon;Password=kang124";
        scon = new SqlConnection(ConMsg);
    }


    public Boolean Connect()
    {
        try
        {
            scon.Open();
            DBLogin = true;
            return true;
        }
        catch (Exception)
        {
            return false;
        }
    }

    public Boolean DisConnect()
    {
        try
        {
            scon.Close();
            DBLogin = false;
            return false;
        }
        catch (Exception)
        {
            return true;
        }
    }


    [WebMethod]     // 웹 메서드 속성을 가진다는 것을 명시
    public void Save(string name, string phone, string addr)
    {
        string comtxt =string.Format("insert into Custom (CNAME, PHONE,ADDR ) values ('{0}', {1}, '{2}')",name, phone, addr);
        Connect();
        SqlCommand scom = new SqlCommand(comtxt, scon);
        scom.ExecuteNonQuery();
        scom.Dispose();
        DisConnect();
    }

    [WebMethod]     // 웹 메서드 속성을 가진다는 것을 명시
    public void SaveByte(byte[] member)
    {
        string str = Encoding.Default.GetString(member);
        string[] Data = str.Split('@');
        string comtxt = string.Format("insert into Custom (CNAME, PHONE,ADDR ) values ('{0}', {1}, '{2}')", Data[0], Data[1], Data[2]);
        Connect();
        SqlCommand scom = new SqlCommand(comtxt, scon);
        scom.ExecuteNonQuery();
        scom.Dispose();
        DisConnect();
    }
}