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
        //db 연결&해체
        private void button1_Click(object sender, EventArgs e)
        {
            if(Control.Singleton.DBLogin==false)
            {
                Control.Singleton.DBConnect();
                if (Control.Singleton.DBLogin ==  true)
                {
                    //리스트뷰 출력
                    List<Book> booklist = Control.Singleton.SelectAllBooks();
                    BookListPrint(booklist);
                    //리스트뷰 출력
                    List<Customer> customlist = Control.Singleton.SelectAllCustomers();
                    CustomerListPrint(customlist);
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

        // 도서 저장
        private void button2_Click(object sender, EventArgs e)
        {
            string name = textBox1.Text;
            int price = int.Parse(textBox2.Text);
            string des = textBox3.Text;

            Control.Singleton.InsertProduct(name, price, des);
            //리스트뷰 출력
            List<Book> booklist = Control.Singleton.SelectAllBooks();
            BookListPrint(booklist);
            
        }

        //리스트뷰 출력 :서버 접속과 (insert update delete)
        private void BookListPrint(List<Book> booklist)
        {
            listView1.Items.Clear();

            foreach(Book book in booklist)
            {
                listView1.Items.Add(new ListViewItem(new string[] { book.PID.ToString(),book.Name, book.Price.ToString() }));
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
            BookListPrint(booklist);
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
            BookListPrint(booklist);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            string name = textBox8.Text;
            string  phone =textBox7.Text;
            string addr = textBox6.Text;

            Control.Singleton.InsertCustomer(name, phone, addr);
            //리스트뷰 출력
            List<Customer> customlist = Control.Singleton.SelectAllCustomers();
            CustomerListPrint(customlist);
        }

        private void CustomerListPrint(List<Customer> customerlist)
        {
            listView2.Items.Clear();

            foreach (Customer cus in customerlist)
            {
                listView2.Items.Add(new ListViewItem(new string[] { cus.CID.ToString(), cus.Name.ToString(), cus.Phone.ToString() }));
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
            CustomerListPrint(customer);

        }

        private void button5_Click(object sender, EventArgs e)
        {
            //입력
            int cid = int.Parse(textBox5.Text);
            string phone = textBox7.Text;
            //전달
            Control.Singleton.UpdatePhone(cid, phone);
            //리스트뷰 출력
            List<Customer> customer = Control.Singleton.SelectAllCustomers();
            CustomerListPrint(customer);
        }
    }
}
