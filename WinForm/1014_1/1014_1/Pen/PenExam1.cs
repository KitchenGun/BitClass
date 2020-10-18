using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1014_1
{
    public partial class PenExam1 : Form
    {
        public PenExam1()
        {
            InitializeComponent();
            this.Text = "X자 그리기";
            this.Size = new Size(300, 300);
        }
        protected override void OnPaint(PaintEventArgs pea)
        {
            Graphics g = pea.Graphics;
            // 파랑색, 두께 10
            Pen pen1 = new Pen(Color.Blue, 10);
            // 빨강색, 두께 5
            Pen pen2 = new Pen(Color.Red, 5);
            g.DrawLine(pen1, 50, 50, 250, 250);
            g.DrawLine(pen2, 250, 50, 50, 250);
        }
    }
}
