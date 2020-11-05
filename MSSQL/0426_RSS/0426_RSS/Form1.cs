using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace _0426_RSS
{
    public partial class Form1 : Form
    {
        MyRSS rss = new MyRSS();
        List<Data> datalist = new List<Data>();

        public Form1()
        {
            InitializeComponent();
            textBox1.Text = "http://www.chosun.com/site/data/rss/rss.xml";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            datalist.Clear();

            rss.RecvRss(textBox1.Text);
            List<string> list = rss.RecvElement("item");
            foreach(string str in list)
            {
              //  listBox1.Items.Add(str);
                Parsing(str);
            }
            //=========================================
            foreach(Data date in datalist )
            {
                listBox1.Items.Add(date.Title);
            }
        }

        public void Parsing(string str)
        {
            string strimage = str;

            //=========================================
            int s_title = str.IndexOf("<title>");
            int e_title = str.IndexOf("</title>");
            string title = str.Substring(s_title + 15, e_title - (s_title + 15) - 2);
            //=====================================================

            str = str.Substring(e_title + 8);
            int s_link = str.IndexOf("<link>");
            int e_link = str.IndexOf("</link>");
            string link = str.Substring(s_link + 6, e_link - (s_link + 6));
            //=====================================================

            str = str.Substring(e_link + 7);
            int s_description = str.IndexOf("<description>");
            int e_description = str.IndexOf("</description>");
            string description = str.Substring(s_description + 21, e_description - (s_description + 21) - 2);
            //=======================================================

            str = str.Substring(e_description + 14);
            int s_date = str.IndexOf("<dc:date>");
            int e_date = str.IndexOf("</dc:date>");
            string date = str.Substring(s_date + 9, e_date - (s_date + 9));
            //=======================================================

            str = str.Substring(e_date + 10);
            int s_author = str.IndexOf("<author>");
            int e_author = str.IndexOf("</author>");
            string author = str.Substring(s_author + 17, e_author - (s_author + 17) - 3);
            //=======================================================

            str = str.Substring(e_author + 9);
            int s_category = str.IndexOf("<category>");
            int e_category = str.IndexOf("</category>");
            string category = str.Substring(s_category + 18, e_category - (s_category + 18) - 2);
            //=======================================================

            str = str.Substring(e_category + 11);
            int s_pubDate = str.IndexOf("<pubDate>");
            int e_pubDate = str.IndexOf("</pubDate>");
            string pubDate = str.Substring(s_pubDate + 9, e_pubDate - (s_pubDate + 9));

            //=====================================================
            int start = strimage.IndexOf("img");
            strimage = strimage.Substring(start, 120);
            int end = strimage.IndexOf(" border=0");
            string image = strimage.Substring(9, end - 10);
            datalist.Add(new Data(title, link, description, date, author, category, pubDate, image));
        }
    

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            Data date = datalist[listBox1.SelectedIndex];
            linkLabel1.Text = date.Link;
            //================================================
            textBox2.Text = date.Description;
            GetImage(date.Image);
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            webBrowser1.Navigate(linkLabel1.Text);
        }

        private void GetImage(string url)
        {
            try
            {
                byte[] data = new System.Net.WebClient().DownloadData(url);
                System.IO.MemoryStream ms = new System.IO.MemoryStream(data);
                Image img = Image.FromStream(ms);
                pictureBox1.Image = img;
                Size size = new Size(img.Width, img.Height);

            }
            catch (Exception ex)
            {
            }

        }
    }
}
