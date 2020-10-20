using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1019paintTool
{
    /// <summary>
    /// 저장소 관리 클래스
    /// </summary>
    class ShapeControl
    {
        #region 싱글톤
        //1. 생성자 은닉
        private ShapeControl()
        {
            CurShape = new Shape(new Point(0, 0), Color.FromArgb(0, 0, 255), Color.FromArgb(100, 0, 0, 255), ShapeSize.Size2, ShapeType.Rect);
        }

        //2. 프로퍼티 선언
        static public ShapeControl Singleton { get; private set; }
        //3. static 생성자에서 객체 생성(단 한번 호출되는 문장)
        static ShapeControl()
        {
            Singleton = new ShapeControl();
        }
        #endregion

        //영구적 저장 정보
        private WbCollection shapelist = new WbCollection();

        //현재 설정 정보 - 생성자에서 생성및 초기화
        public Shape CurShape { get; set; }

        #region 기능
        public void ShapeInsert(Form1 form, int x, int y)//생성
        {
            //전달된 좌표로 현재 설정 정보를 수정
            CurShape.Pt = new Point(x, y);
            //영구적 저장 정보에 저장
            Shape sh = new Shape(CurShape.Pt,CurShape.PenColor,CurShape.BrushColor,CurShape.Size,CurShape.Type);
            shapelist.Add(sh);
        }
        public void ShapePrintAll(Graphics gp) //출력함수
        {
            foreach(Shape s in shapelist)
            {
                DrawShape(gp, s);
            }
        }
        private void DrawShape(Graphics gp, Shape s)
        {

            // Create location and size of rectangle.
            int x = s.Pt.X;
            int y = s.Pt.Y;
            int width = (int)s.Size;
            int height = (int)s.Size;

            //[FillRectangle]
            SolidBrush br = new SolidBrush(s.BrushColor);
            gp.FillRectangle(br, x, y, width, height);

            //[DrawRectangle]
            // Create pen.
            Pen Pen = new Pen(s.PenColor, 3);
            // Draw rectangle to screen.
            gp.DrawRectangle(Pen, x, y, width, height);

        }
        public void ShapeSizeUpdate(Keys key)
        {
            if (CurShape.Size == ShapeSize.Size1)
            {
                if (key == Keys.Up)
                    CurShape.Size = ShapeSize.Size2;
            }
            else if (CurShape.Size == ShapeSize.Size2)
            {
                if (key == Keys.Up)
                    CurShape.Size = ShapeSize.Size3;
                else if (key == Keys.Down)
                    CurShape.Size = ShapeSize.Size1;
            }
            else if (CurShape.Size == ShapeSize.Size3)
            {
                if (key == Keys.Up)
                    CurShape.Size = ShapeSize.Size4;
                else if (key == Keys.Down)
                    CurShape.Size = ShapeSize.Size2;
            }
            else if (CurShape.Size == ShapeSize.Size4)
            {
                if (key == Keys.Down)
                    CurShape.Size = ShapeSize.Size3;
            }
        }
        public void PenColorUpdate(Color color)
        {
            CurShape.PenColor = color;
            CurShape.BrushColor = Color.FromArgb(100, color);
        }
       
        #endregion
    }
}
