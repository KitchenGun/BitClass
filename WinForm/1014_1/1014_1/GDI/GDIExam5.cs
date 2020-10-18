using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Printing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1014_1
{
    public partial class GDIExam5 : Form
    {
        Button btn = null;
        public GDIExam5()
        {
            InitializeComponent();
            btn = new Button();
            btn.Text = "문서를 프린트합니다.";
            btn.SetBounds(10, 10, 200, 100);
            btn.Click += new EventHandler(btn_Click);
            this.Controls.Add(btn);
        }

        public void btn_Click(object sender, EventArgs e)
        {
            try
            {
                PrintDocument pd = new PrintDocument(); // 1)
                pd.PrintPage += new PrintPageEventHandler(this.pd_PrintPage);//2)
                pd.Print(); // 3)
            }
            catch (Exception ex)
            {
                MessageBox.Show("프린터 도중 예외 발생 :" + ex.ToString());
            }
        }
        private void pd_PrintPage(object sender, PrintPageEventArgs ppe)//4)
        {
            string strText = DateTime.Today + " : 문서 작성자 [CJK] ";
            ppe.HasMorePages = false; //HasMorePages--> true 라면 무한반복
            Graphics g = ppe.Graphics; // 5)
            Pen pen = new Pen(Color.Black, 2);
            for (int i = 0; i < this.ClientSize.Width; i += 20)
                g.DrawLine(pen, i, 0, i, this.ClientSize.Height);
            for (int j = 0; j < this.ClientSize.Height; j += 20)
                g.DrawLine(pen, 0, j, this.ClientSize.Width, j);
            g.DrawString(strText, this.Font, Brushes.Black, 10,
            this.ClientSize.Height + 20);
        }
    }
}
