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
    public partial class GDIExam15 : Form
    {
        public GDIExam15()
        {
            InitializeComponent();
            this.Text = "Font 예제";
            this.Size = new Size(400, 150);
        }
        protected override void OnPaint(PaintEventArgs pea)
        {
            Graphics g = pea.Graphics;
            // 글꼴 생성 객체
            Font font = new Font("Timesroman", 20); // 글꼴 지정,글꼴 크기
            SolidBrush brush = new SolidBrush(Color.Blue);//브러쉬 생성
            RectangleF rect = new RectangleF(50, 10, 200, 30);// 문자열 영역 설정
                                                  // 화면에 문자를 출력할 떄 사용하는 메서드
            g.DrawString("안녕하세요", font, brush, rect);// 출력
            font = new Font("돋움", 10); // 글꼴을 돋움10으로 변경
            g.DrawString("폰트 예제입니다.", font, brush, 50, 50);//바뀐 글꼴로 문자열 출력
            font = new Font("궁서", 15);
            brush = new SolidBrush(Color.Red);
            PointF point = new PointF(10, 10);
            StringFormat sf = new StringFormat();
            sf.FormatFlags = StringFormatFlags.DirectionVertical;// 글꼴 출력을 세로로 지정
            g.DrawString("C# Font 다루기", font, brush, point, sf);
  
            // 글꼴 생성
            Font font1 = new Font("Timesroman", 30, FontStyle.Italic);
            string str = "빨주노초파남보";
            Color[] color = {Color.Red, Color.Orange, Color.Yellow,Color.Green, Color.Blue,Color.Magenta,Color.Violet};
            for (int i = 0; i < 7; i++)
            {
                // 출력 : 색상을 바꾸어 가면서 겹쳐서 출력
                g.DrawString(str, font1, new SolidBrush(color[6 - i]), (20 + i), 30 + (i * 2));
                System.Console.WriteLine("{0},{1}", 20 + i, 30 + 2 * i);
            }
            Rectangle rec1t = new Rectangle(20, 20, 400, font.Height);
            g.DrawRectangle(Pens.Red, rec1t);
            g.DrawString(str, font, Brushes.Black, rec1t);
            font.Dispose(); 
        }

    }
}
