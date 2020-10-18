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
    public partial class GDIExam10 : Form
    {
        Point[] point = new Point[3];
        public GDIExam10()
        {
            InitializeComponent();
            this.Text = "FillXXX 계열 메서드";
            point[0] = new Point(100, 10);
            point[1] = new Point(10, 100);
            point[2] = new Point(190, 100);
        }

        protected override void OnPaint(PaintEventArgs pea)
        {
            Graphics g = pea.Graphics;
            g.FillEllipse(Brushes.Brown, 10, 100, 50, 50);// 채워진 타원 그리기
            GraphicsPath graphPath = new GraphicsPath();
            graphPath.AddEllipse(0, 0, 150, 100);// 타원 등록
            g.FillPath(Brushes.Red, graphPath);// FilPath를 사용해 영역을 그림
            g.FillPie(Brushes.Yellow, 200, 10, 100, 100, 90, 180);
            g.FillPolygon(Brushes.Green, point);
            g.FillRectangle(Brushes.Magenta, 50, 150, 100, 100);
           Rectangle fillRect = new Rectangle(150, 150, 100, 100);
            //region테스트
            Region fillRegion = new Region(fillRect);
            g.FillRegion(Brushes.Orange, fillRegion);
            //덮어씌우기
            Region fillRegion1= new Region(graphPath);
            g.FillRegion(Brushes.Orange, fillRegion1);
        }

    }
}
