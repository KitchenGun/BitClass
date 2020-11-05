using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace _0427_검색
{
    public partial class Form1 : Form
    {
        BookSearcher search = new BookSearcher();

        public Form1()
        {
            InitializeComponent();            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            search.Find(textBox1.Text);

            search.TitlePrint(listBox1);
        }

        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyData == Keys.Enter)
            {
                button1.PerformClick();
            }

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            Book book = search.GetBookInfo(listBox1.SelectedIndex);

            //===========================================================
            label7.Text = book.Title;
            label8.Text = book.Author;
            label9.Text = book.Price + "원";
            label10.Text = book.Publisher;
            label11.Text = book.Description;
        }
    }
}
