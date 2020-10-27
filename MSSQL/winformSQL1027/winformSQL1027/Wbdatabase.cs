﻿using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace winformSQL1027
{
    class Wbdatabase
    {
       public  Boolean DBLogin { get; set; }
       public  string ConMsg { get; private set; }
        SqlConnection scon;

        public Wbdatabase()
        {
            DBLogin = false;
            ConMsg = @"Data Source =DESKTOP-4IV1O4J\SQLEXPRESS;Initial Catalog=WbDB; User ID=kangkeon;Password=kang124";
            scon = new SqlConnection(ConMsg);
        }
        #region 연결&연결해제
        public Boolean Connect()
        {
            try
            {
                scon.Open();
                DBLogin = true;
                return true;
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
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
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return true;
            }
        }
        #endregion

        #region  상품 기능
        //제품 추가
        public Boolean InsertProduct(string name, int price, string des)
        {
            try
            {
                string comtxt = string.Format("insert into Product (PNAME, Price, Description) values ('{0}', {1}, '{2}')",
                    name, price, des);

                SqlCommand scom = new SqlCommand(comtxt, scon);
                scom.ExecuteNonQuery();
                scom.Dispose();

                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
        }

        //제품 전체 리스트 반환
        public List<Book>SelectAllBooks()
        {
            List<Book> list = new List<Book>();

            string comtext = "Select * from Product";
            SqlCommand command = new SqlCommand(comtext,scon);

            //select
            SqlDataReader reader = command.ExecuteReader();
            while(reader.Read())
            {
                Book book = new Book(int.Parse(reader[0].ToString()), reader[1].ToString(), int.Parse(reader[2].ToString()), reader[3].ToString());
                list.Add(book);
            }
            reader.Close();             //반드시 닫아야함
            command.Dispose();   //반드시 닫아야함
            return list;
        }

        public Book SelectPidToBook(int pid)
        {
            List<Book> list = new List<Book>();

            string comtext = string.Format("Select * from Product where PID ={0}",pid);
            SqlCommand command = new SqlCommand(comtext, scon);

            //select
            SqlDataReader reader = command.ExecuteReader();
            while (reader.Read())
            {
                Book book = new Book(
                                        int.Parse(reader[0].ToString()),
                                        reader[1].ToString(),
                                        int.Parse(reader[2].ToString()),
                                        reader[3].ToString());
                list.Add(book);
            }
            reader.Close();         //<=========
            command.Dispose();      //<=========

            return list[0];

        }

        //삭제
        public Boolean DeleteProduct(int pid)
        {
            try
            {
                string comtxt = string.Format("delete from Product where PID = {0}",pid);

                SqlCommand scom = new SqlCommand(comtxt, scon);
                scom.ExecuteNonQuery();
                scom.Dispose();

                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
        }

        //수정
        public Boolean UpdatePrice(int pid,int price)
        {
            try
            {
                string comtxt = string.Format("update Product set Price = {1} where PID = {0}", pid,price);

                SqlCommand scom = new SqlCommand(comtxt, scon);
                scom.ExecuteNonQuery();
                scom.Dispose();

                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
        }
        #endregion

        #region 고객 기능
        public Boolean InsertCustomer(string name, string phone, string addr)
        {
            try
            {
                string comtxt = string.Format("insert into Custom (CNAME, PHONE,ADDR ) values ('{0}', {1}, '{2}')",
                    name, phone, addr);

                SqlCommand scom = new SqlCommand(comtxt, scon);
                scom.ExecuteNonQuery();
                scom.Dispose();

                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
        }

        public List<Customer> SelectAllCustomers()
        {
            List<Customer> list = new List<Customer>();

            string comtext = "Select * from Custom";
            SqlCommand command = new SqlCommand(comtext, scon);

            //select
            SqlDataReader reader = command.ExecuteReader();
            while (reader.Read())
            {
                Customer customer = new Customer(int.Parse(reader[0].ToString()), reader[1].ToString(), reader[2].ToString(), reader[3].ToString());
                list.Add(customer);
            }
            reader.Close();             //반드시 닫아야함
            command.Dispose();   //반드시 닫아야함
            return list ;
        }
        public Customer SelectCidToCustomer(int cid)
        {
            List<Customer> list = new List<Customer>();

            string comtext = string.Format("Select * from Custom where CID ={0}", cid);
            SqlCommand command = new SqlCommand(comtext, scon);

            //select
            SqlDataReader reader = command.ExecuteReader();
            while (reader.Read())
            {
                Customer customer = new Customer(
                                        int.Parse(reader[0].ToString()),
                                        reader[1].ToString(),
                                       reader[2].ToString(),
                                        reader[3].ToString());
                list.Add(customer);
            }
            reader.Close();         //<=========
            command.Dispose();      //<=========

            return list[0];

        }

        //삭제
        public Boolean DeleteCustomer(int cid)
        {
            try
            {
                string comtxt = string.Format("delete from Custom where CID = {0}", cid);

                SqlCommand scom = new SqlCommand(comtxt, scon);
                scom.ExecuteNonQuery();
                scom.Dispose();

                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
        }

        //수정
        public Boolean UpdatePhone(int cid, string phone)
        {
            try
            {
                string comtxt = string.Format("update Custom set Phone  = {1} where CID = {0}", cid, phone);

                SqlCommand scom = new SqlCommand(comtxt, scon);
                scom.ExecuteNonQuery();
                scom.Dispose();

                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
        }

        #endregion
    }
}
