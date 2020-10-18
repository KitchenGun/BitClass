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
    public partial class GDIExam13 : Form
    {
        public GDIExam13()
        {
            InitializeComponent();
            this.Text = "Invalidate 예제";
        }
        private void DrawGraphics()
        {
            // Graphics 개체 얻기
            Graphics g = this.CreateGraphics();
            // 사각형 테두리 그리기
            g.DrawRectangle(Pens.Black, 10, 10, 200, 200);
            // 사각형 안쪽을 노란색으로 채움
            g.FillRectangle(Brushes.Yellow, 20, 20, 180, 180);
            // 문자열 출력
            g.DrawString("사라지는 색상", this.Font, Brushes.Black, 30, 100);
        }

        // 마우스 왼쪽 버튼 클릭시 호출
        public void GDIExam_Click(object sender, System.EventArgs e)
        {
            this.DrawGraphics();
        }
        protected override void OnPaint(PaintEventArgs pea)
        {
            // 자동으로 화면 갱신
             //this.DrawGraphics();
        }
    }
}
