using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using _1124BookSearch.localhost;

namespace _1124BookSearch
{
    public partial class Form1 : Form
    {
        private SearchBook searchBook=new SearchBook();

        private Book[] books;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //전달
            books = searchBook.Find(textBox1.Text.Trim());

            //출력
            ListBoxPrint();
        }

        private void ListBoxPrint()
        {
            listBox1.Items.Clear();
            foreach (Book book in books)
            {
                listBox1.Items.Add(book.Title);
            }
        }

        Book BookNameToBook(string bkname)
        {
            foreach (Book b in books)
            {
                if (b.Title.Equals(bkname) == true)
                    return b;
            }
            return null;
        }

        private void listBox1_DoubleClick(object sender, EventArgs e)
        {
            Book selectbook = BookNameToBook(listBox1.SelectedItem.ToString());
            textBox2.Text = selectbook.Title;
            textBox3.Text = selectbook.Author;
            textBox4.Text = selectbook.Publisher;
            textBox5.Text = selectbook.Description;
            pictureBox1.ImageLocation = selectbook.Image;
        }
    }
}
