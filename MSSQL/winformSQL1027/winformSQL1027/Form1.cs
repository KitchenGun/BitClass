using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace winformSQL1027
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        #region db 연결&해체
        private void button1_Click(object sender, EventArgs e)
        {
            if(Control.Singleton.DBLogin==false)
            {
                Control.Singleton.DBConnect();
                if (Control.Singleton.DBLogin ==  true)
                {
                    //리스트뷰 출력
                    List<Book> booklist = Control.Singleton.SelectAllBooks();
                    BookListPrint(listView1,booklist);
                    //리스트뷰 출력
                    List<Customer> customlist = Control.Singleton.SelectAllCustomers();
                    CustomerListPrint(listView2,customlist);
                    button1.Text = "DB 연결해제";
                }
            }
            else
            {
                Control.Singleton.DBDisConnect();
                if (Control.Singleton.DBLogin == false)
                    button1.Text = "DB 연결";
            }
        }

        #endregion

        #region 상품 탭
        // 도서 저장
        private void button2_Click(object sender, EventArgs e)
        {
            string name = textBox1.Text;
            int price = int.Parse(textBox2.Text);
            string des = textBox3.Text;

            Control.Singleton.InsertProduct(name, price, des);
            //리스트뷰 출력
            List<Book> booklist = Control.Singleton.SelectAllBooks();
            BookListPrint(listView1,booklist);
            
        }

        //리스트뷰 출력 :서버 접속과 (insert update delete)
        private void BookListPrint(ListView lv,List<Book> booklist)
        {
            lv.Items.Clear();

            foreach(Book book in booklist)
            {
                lv.Items.Add(new ListViewItem(new string[] { book.PID.ToString(),book.Name, book.Price.ToString() }));
            }
        }

        //리스트뷰에서 선택 -> PID 얻어오겠다.
        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                int PID = int.Parse(listView1.SelectedItems[0].Text);
                Book book = Control.Singleton.SelectPidToBook(PID);

                //컨트롤에 출력
                textBox1.Text = book.Name;
                textBox2.Text = book.Price.ToString();
                textBox3.Text = book.Description;
                textBox4.Text = book.PID.ToString();
            }
            catch
            {

            }
        }

        //삭제
        private void button3_Click(object sender, EventArgs e)
        {
            //삭제
            Control.Singleton.DeleteProduct(int.Parse(textBox4.Text));
            //텍스트 삭제
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
            //리스트뷰 출력
            List<Book> booklist = Control.Singleton.SelectAllBooks();
            BookListPrint(listView1,booklist);
        }

        
        private void button4_Click(object sender, EventArgs e)
        {
            //입력
            int pid = int.Parse(textBox4.Text);
            int price = int.Parse(textBox2.Text);
            //전달
            Control.Singleton.UpdatePrice(pid, price);
            //리스트뷰 출력
            List<Book> booklist = Control.Singleton.SelectAllBooks();
            BookListPrint(listView1,booklist);
        }
        #endregion

        #region 고객 탭
        private void button7_Click(object sender, EventArgs e)
        {
            string name = textBox8.Text;
            string  phone =textBox7.Text;
            string addr = textBox6.Text;

            Control.Singleton.InsertCustomer(name, phone, addr);
            //리스트뷰 출력
            List<Customer> customlist = Control.Singleton.SelectAllCustomers();
            CustomerListPrint(listView2,customlist);
        }

        private void CustomerListPrint(ListView lv,List<Customer> customerlist)
        {
            lv.Items.Clear();

            foreach (Customer cus in customerlist)
            {
                lv.Items.Add(new ListViewItem(new string[] { cus.CID.ToString(), cus.Name.ToString(), cus.Phone.ToString() }));
            }
        }

        private void listView2_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                int CID = int.Parse(listView2.SelectedItems[0].Text);
                Customer customer = Control.Singleton.SelectCidToCustomer(CID);

                //컨트롤에 출력
                textBox8.Text = customer.Name;
                textBox7.Text = customer.Phone;
                textBox6.Text = customer.Addr;
                textBox5.Text = customer.CID.ToString();
            }
            catch
            {

            }
        }

        private void button6_Click(object sender, EventArgs e)
        {   
            //삭제
            Control.Singleton.DeleteCustomer(int.Parse(textBox5.Text));
            //텍스트 삭제
            textBox5.Text = "";
            textBox6.Text = "";
            textBox7.Text = "";
            textBox8.Text = "";
            //리스트뷰 출력
            List<Customer> customer = Control.Singleton.SelectAllCustomers();
            CustomerListPrint(listView2,customer);

        }

        private void button5_Click(object sender, EventArgs e)
        {
            //입력
            int cid = int.Parse(textBox5.Text);
            string phone = textBox7.Text;
            string addr = textBox6.Text;
            //전달
            Control.Singleton.UpdatePhone(cid, phone);
            Control.Singleton.UpdateAddr(cid, addr);
            //리스트뷰 출력
            List<Customer> customer = Control.Singleton.SelectAllCustomers();
            CustomerListPrint(listView2,customer);
        }

        #endregion

        #region 구매 탭
        private void button8_Click(object sender, EventArgs e)
        {
            //입력
            string cname = textBox9.Text;
            //전달
            List<Customer> customer = Control.Singleton.SelectCnameToCustomer(cname);
            //출력
            CustomerListPrint(listView3,customer);
        }

        private void listView3_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                int CID = int.Parse(listView3.SelectedItems[0].Text);
                Customer customer = Control.Singleton.SelectCidToCustomer(CID);

                //컨트롤에 출력
                textBox12.Text = customer.Name;
                textBox11.Text = customer.CID.ToString();
            }
            catch
            {

            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            //입력
            string pname = textBox10.Text;
            //전달
            List<Book> books = Control.Singleton.SelectPnameToBook(pname);
            //출력
            BookListPrint(listView4, books);
        }
      
        private void listView4_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                int PID = int.Parse(listView4.SelectedItems[0].Text);
                Book book = Control.Singleton.SelectPidToBook(PID);

                //컨트롤에 출력
                textBox14.Text = book.Name;
                textBox13.Text = book.PID.ToString();
            }
            catch
            {

            }
        }
       
        private void button10_Click(object sender, EventArgs e)
        {
            int pid = int.Parse(textBox13.Text);
            int cid = int.Parse(textBox11.Text);
            int count = int.Parse(textBox15.Text);
            Control.Singleton.InsertSale(pid, cid, count);
            //리스트뷰 출력
            List<Book> booklist = Control.Singleton.SelectAllBooks();
            BookListPrint(listView1, booklist);

        }
        #endregion

        #region 검색 탭
        private void button11_Click(object sender, EventArgs e)
        {
            //입력
            string name = textBox16.Text;
            //리스트뷰 출력
            List<Sale> salebooklist = Control.Singleton.SelectAllSaleBooks(name);
            SaleBookListPrint(salebooklist);
        }
        
        private void button12_Click(object sender, EventArgs e)
        {
            //입력
            string pname = textBox17.Text;
            //리스트뷰 출력
            List<Sale> buycustomerlist = Control.Singleton.SelectAllBuyCustomer(pname);
            BuyCustomerListPrint(buycustomerlist);
        }

        //출력
        private void SaleBookListPrint(List<Sale> salebooklist)
        {
            listView5.Items.Clear();

            foreach (Sale salebook in salebooklist)
            {
                listView5.Items.Add(new ListViewItem(new string[]
                {
                    salebook.PID.ToString(),
                    Control.Singleton.SelectPidToBook(salebook.PID).Name.ToString(),
                    Control.Singleton.SelectPidToBook(salebook.PID).Price.ToString(),
                    salebook.Count.ToString(),
                    salebook.Datetime.ToString()
                }));
            }
        }
        private void BuyCustomerListPrint(List<Sale> buycustomerlist)
        {
            listView6.Items.Clear();

            foreach (Sale buycustomer in buycustomerlist)
            {
                listView6.Items.Add(new ListViewItem(new string[]
                {   
                    buycustomer.CID.ToString(),
                    Control.Singleton.SelectCidToCustomer(buycustomer.PID).Name.ToString(),
                    Control.Singleton.SelectCidToCustomer(buycustomer.PID).Phone.ToString(),
                    buycustomer.Datetime.ToString()
                }));
            }
        }
        #endregion

    }
}
