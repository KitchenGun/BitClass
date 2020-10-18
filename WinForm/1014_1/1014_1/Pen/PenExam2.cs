using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1014_1
{
    public partial class PenExam2 : Form
    {
        public PenExam2()
        {
            InitializeComponent();
            this.Text = "파선 그리기";
            this.Size = new Size(450, 200);
        }
        // 모눈 종이 그리기
        void DrawGraphPaper(Graphics g)
        {
            int i;
            // pens사용
            for (i = 0; i < this.Width; i += 10)
                g.DrawLine(Pens.Blue, i, 0, i, this.Height);
            // pens2사용
            for (i = 0; i < this.Width; i += 10)
                g.DrawLine(Pens.Blue, 0, i, this.Width, i);
        }

        protected override void OnPaint(PaintEventArgs pea)
        {
            Graphics g = pea.Graphics;
            DrawGraphPaper(g);
            DashStyle[] dash = {DashStyle.Custom, DashStyle.Dash,DashStyle.DashDot,DashStyle.DashDotDot, DashStyle.Dot, DashStyle.Solid};
            Pen pen = new Pen(Color.Black, 10);
            for (int i = 0; i < dash.Length; i++)
            {
                pen.DashStyle = dash[i];
                g.DrawLine(pen, 10, 15 + (20 * i), 400, 15 + (20 * i));
            }

        }
    }
}
