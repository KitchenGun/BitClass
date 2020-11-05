using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1105OpenApiSearch
{
    public partial class Form1 : Form
    {
        private WbSearchBook search = new WbSearchBook();

        public Form1()
        {
            InitializeComponent();
        }

        #region 검색

        private void button1_Click(object sender, EventArgs e)
        {
            string xmlstring;
            search.Find(textBox1.Text.Trim(), out xmlstring);
            textBox7.Text = string.Empty;
            textBox7.Text = xmlstring;
            ListBoxPrint(search.BookList, listBox1);
        }
        #endregion

        private void ListBoxPrint(List<Book> booklist, ListBox lb)
        {

            lb.Items.Clear();

            if (booklist.Count == 0)
            {
                lb.Items.Add("검색결과 없음");
            }
            //타이틀만 출력
            foreach (Book book in booklist)
            {
                lb.Items.Add(book.Title.ToString());
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string name = listBox1.SelectedItem.ToString();
            Book book = search.BookNameToBook(name);
            if (book != null)
            {
                textBox2.Text = book.Title;
                textBox3.Text = book.Author;
                textBox4.Text = book.Price.ToString();
                textBox5.Text = book.Publisher;
                textBox6.Text = book.Description;
                textBox8.Text = book.Image;
                pictureBox1.ImageLocation = book.Image;
            }
        }

        #region 번역& 검색

        private void button2_Click(object sender, EventArgs e)
        {
            string koBookName = textBox2.Text;
            string jsonstr = WbTranslate.Translate(koBookName, "ko", "en");

            JObject jobj = JObject.Parse(jsonstr);
            textBox14.Text = jobj["message"]["result"]["translatedText"].ToString();

            string xmlstring;
            search.Find(textBox14.Text.Trim(), out xmlstring);
            textBox7.Text = string.Empty;
            textBox7.Text = xmlstring;
            ListBoxPrint(search.BookList, listBox2);
        }
        #endregion

        private void listBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            string name = listBox2.SelectedItem.ToString();
            Book book = search.BookNameToBook(name);
            if (book != null)
            {
                textBox14.Text = book.Title;
                textBox13.Text = book.Author;
                textBox12.Text = book.Price.ToString();
                textBox11.Text = book.Publisher;
                textBox10.Text = book.Description;
                textBox9.Text = book.Image;
                pictureBox2.ImageLocation = book.Image;
            }
        }
    }
}
