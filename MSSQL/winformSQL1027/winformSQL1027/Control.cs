using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace winformSQL1027
{
    class Control
    {

        public Boolean DBLogin 
        { 
            get { return db.DBLogin; }
        }

        Wbdatabase db = new Wbdatabase();

        #region 싱글톤
        //1. 생성자 은닉
        private Control()
        {
        }
        //2. 프로퍼티 선언
        static public Control Singleton { get; private set; }
        //3. static 생성자에서 객체 생성(단 한번 호출되는 문장)
        static Control()
        {
            Singleton = new Control();
        }
        #endregion

        #region 상품 테이블 기능

        public void DBConnect()
        {
            db.Connect();
        }
        public void DBDisConnect()
        {
            db.DisConnect();
        }

        public void InsertProduct(string name, int price, string des)
        {
            db.InsertProduct(name, price, des);
        }

        public List<Book> SelectAllBooks()
        {
            return db.SelectAllBooks();
        }
        public Book  SelectPidToBook(int pid)
        {
            return db.SelectPidToBook(pid);
        }

        public void DeleteProduct(int pid)
        {
            db.DeleteProduct(pid);
        }


        public void UpdatePrice(int pid, int price)
        {
            db.UpdatePrice(pid, price);
        }
        #endregion

        #region 고객 테이블 기능
        public void InsertCustomer(string name, string phone, string addr)
        {
            db.InsertCustomer(name, phone, addr);
        }

        public List<Customer> SelectAllCustomers()
        {
            return db.SelectAllCustomers();
        }

        public Customer SelectCidToCustomer(int cid)
        {
            return db.SelectCidToCustomer(cid);
        }
        public void DeleteCustomer(int cid)
        {
            db.DeleteCustomer(cid);
        }
        public void UpdatePhone(int cid,string phone)
        {
            db.UpdatePhone(cid, phone);
        }

        #endregion
    }
}
