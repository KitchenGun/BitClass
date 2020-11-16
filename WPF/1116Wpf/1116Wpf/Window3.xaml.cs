using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace _1116Wpf
{
    /// <summary>
    /// Window3.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window3 : Window
    {
        public Window3()
        {
            InitializeComponent();
        }

        private void Canvas_MouseUp(object sender, MouseButtonEventArgs e)
        {
            Point pos = e.GetPosition(canvas);
            mainwin.Title = pos.ToString();
            //사각형 그리기
            Rectangle rt = new Rectangle();
            rt.MouseUp += Rt_MouseUp;
            rt.Width = 50;
            rt.Height = 50;
            rt.Stroke = new SolidColorBrush(Colors.Yellow);
            rt.Fill = new SolidColorBrush(Colors.White);
            //사각형을 Canvas 어디에 배치할 것인지 지정한다.
            Canvas.SetLeft(rt, e.GetPosition(canvas).X);
            Canvas.SetTop(rt, e.GetPosition(canvas).Y);
            // 사각형을 위치시킨다.(그린다.)
            canvas.Children.Add(rt);

        }

        private void Rt_MouseUp(object sender, MouseButtonEventArgs e)
        {//도형도 객체라 이벤트를 받을수있다.
            ModifierKeys key = Keyboard.Modifiers;
            //Ctrl + mouseUP 
            if (key==ModifierKeys.Control)
            {
                Rectangle r = (Rectangle)sender;
                r.Height = 100;
                r.Width = 100;
            } 
        }
    }
}
