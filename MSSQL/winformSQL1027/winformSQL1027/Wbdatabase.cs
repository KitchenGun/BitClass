using System;
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
            ConMsg = @"Data Source =DESKTOP-R8F9OUG\SQLEXPRESS;Initial Catalog=WbDB; User ID=ksw;Password=123";
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

        #region 프로시져
        public Boolean InsertProduct1(string name, int price, string des)
        {
            try
            {
                string comtxt = "AddBook";//프로시져 이름

                SqlCommand scom = new SqlCommand(comtxt, scon);//접속 형식 프로시져명으로 변경
                scom.CommandType = System.Data.CommandType.StoredProcedure;
                //파라미터 등록
                SqlParameter param_name = new SqlParameter("@Name", name);
                scom.Parameters.Add(param_name);
                SqlParameter param_price = new SqlParameter();
                param_price.ParameterName = "@Price";
                param_price.SqlDbType = System.Data.SqlDbType.Int;
                param_price.Value = price;
                scom.Parameters.Add(param_price);
                SqlParameter param_des = new SqlParameter("@Description", des);
                scom.Parameters.Add(param_des);
                //
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

        public List<Book> SelectPnameToBook(string pname)
        {
            List<Book> list = new List<Book>();

            string comtext = string.Format("Select * from Product where PNAME ='{0}'", pname);
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

            return list;

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

        public List<Customer> SelectCnameToCustomer(string cname)
        {
            List<Customer> list = new List<Customer>();

            string comtext = string.Format("Select * from Custom where CNAME ='{0}'", cname);
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

            return list;

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

        public Boolean UpdateAddr(int cid, string Addr)
        {
            try
            {
                string comtxt = string.Format("update Custom set ADDR  = '{1}' where CID = {0}", cid, Addr);

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

        #region 구매 기능
        public Boolean InsertSale(int cid, int pid, int count)
        {
            try
            {
                string comtxt = string.Format("insert into SaleDate (CID, PID, COUNT,SaleDate) values ({0}, {1}, {2}, GETDATE())",
                    cid, pid, count);

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

        public List<Sale> SelectAllSaleBooks(string name)
        {
            List<Sale> list = new List<Sale>();
          
            string comtext = string.Format("Select* from SaleDate where PID = (select CID from Custom where CName = '{0}')", name);
            SqlCommand command = new SqlCommand(comtext, scon);

            //select
            SqlDataReader reader = command.ExecuteReader();
            while (reader.Read())
            {
                Sale sale = new Sale(
                                        int.Parse(reader[0].ToString()),
                                        int.Parse(reader[1].ToString()),
                                        int.Parse(reader[2].ToString()),
                                        DateTime.Parse(reader[3].ToString()));
                list.Add(sale);
            }
            reader.Close();         //<=========
            command.Dispose();      //<=========

            return list;

        }

        public List<Sale> SelectAllBuyCustomer(string pname)
        {
            List<Sale> list = new List<Sale>();

            string comtext = string.Format("Select* from SaleDate where PID = (select PID from Product where PName = '{0}')", pname);
            SqlCommand command = new SqlCommand(comtext, scon);

            //select
            SqlDataReader reader = command.ExecuteReader();
            while (reader.Read())
            {
                Sale sale = new Sale(
                                        int.Parse(reader[0].ToString()),
                                        int.Parse(reader[1].ToString()),
                                        int.Parse(reader[2].ToString()),
                                        DateTime.Parse(reader[3].ToString()));
                list.Add(sale);
            }
            reader.Close();         //<=========
            command.Dispose();      //<=========

            return list;

        }
        #endregion
    }
}
