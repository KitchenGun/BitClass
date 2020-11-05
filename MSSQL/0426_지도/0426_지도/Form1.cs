using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Xml;

namespace _0426_지도
{
    public partial class Form1 : Form
    {
        List<LocationData> ld_list = new List<LocationData>();

        public Form1()
        {
            InitializeComponent();
        }

        //검색 버튼
        private void button1_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            ld_list.Clear();

            XmlDocument xdoc = new XmlDocument();
            string url = "https://apis.daum.net/local/v1/search/keyword.xml?apikey=dc2c847f7274a266a71f7a4decdc69d5&query=" + textBox1.Text;
            xdoc.Load(url);

            XmlNode cn = xdoc.SelectSingleNode("channel");
            XmlNodeList ins = cn.SelectNodes("item");

            foreach (XmlNode bn in ins)
            {
                ViewLocation(bn);
            }

        }

        public void ViewLocation(XmlNode bn)
        {
            string title = bn.SelectSingleNode("title").InnerText;
            double lat = double.Parse(bn.SelectSingleNode("latitude").InnerText);
            double lng = double.Parse(bn.SelectSingleNode("longitude").InnerText);

            listBox1.Items.Add(title);

            ld_list.Add(new LocationData(title, lat, lng));
        }

        //리스트박스 선택
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            foreach (LocationData ld in ld_list)
            {
                if (ld.Title == listBox1.Items[listBox1.SelectedIndex].ToString())
                {
                    HtmlDocument hdoc = this.webBrowser1.Document;

                    object[] obj = new object[2] { ld.Latitude, ld.Longitude };
                    hdoc.InvokeScript("setCenter", obj);
                }
            }
        }

        //텍스트박스 keyDown
        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyData == Keys.Enter)
            {
                button1.PerformClick();
            }
        }

        //htmp 연동
        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                string url = Environment.CurrentDirectory + "\\daumMapAPI1.html";
                //string url = "daumMapAPI1.html";
                this.webBrowser1.Navigate(url);
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

    }
}
