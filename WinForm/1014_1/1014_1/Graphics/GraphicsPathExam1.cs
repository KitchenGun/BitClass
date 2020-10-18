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
    public partial class GraphicsPathExam1 : Form
    {
        public GraphicsPathExam1()
        {
            InitializeComponent();
            this.Text = "GraphicsPathExam1";
            this.Size = new Size(500, 500);

        }

        protected override void OnPaint(PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Pen pen = new Pen(Brushes.Black, 3);
            // 개체 생성
            GraphicsPath gp = new GraphicsPath();
            // 첫번째 그림
            gp.AddLine(10, 10, 100, 100);
            gp.AddEllipse(50, 50, 100, 100);
            // 현재 그림을 닫음
            gp.CloseFigure();
            // 두번째 그림
            gp.StartFigure();
            gp.AddArc(300, 300, 50, 50, 45, 180);
            gp.AddLine(250, 200, 370, 350);
            // 지금까지 열린 그림을 닫음
            gp.CloseAllFigures();
            // 세번째 그림
            gp.AddPie(30, 300, 70, 70, 90, 270);
            // 실제 도형을 그려주는 부분
            g.DrawPath(pen, gp);
            //색칠
            g.FillPath(Brushes.Black, gp);
            pen.Dispose();
            gp.Dispose();
        }
    }
}
