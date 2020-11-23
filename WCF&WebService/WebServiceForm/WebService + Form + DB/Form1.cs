using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WebService___Form___DB.localhost;

namespace WebService___Form___DB
{
    public partial class Form1 : Form
    {
        private DBSaveService dbsv = new DBSaveService();

        public Form1()
        {
            InitializeComponent();
            
        }

        #region 저장
        private void button1_Click(object sender, EventArgs e)
        {
            //전달
            dbsv.Save(textBox2.Text, textBox3.Text, textBox4.Text);
            //textbox초기화
            textBox2.Text = string.Empty;
            textBox3.Text = string.Empty;
            textBox4.Text = string.Empty;
     
        }
        #endregion

        #region byte 저장
        private void button2_Click(object sender, EventArgs e)
        {
            //형변환
            string str = textBox2.Text + "@" + textBox3.Text + "@" + textBox4.Text;
            byte[] member = Encoding.UTF8.GetBytes(str);
            //전달
            dbsv.SaveByte(member);
            //textbox초기화
            textBox2.Text = string.Empty;
            textBox3.Text = string.Empty;
            textBox4.Text = string.Empty;
        }
        #endregion

    }
}
