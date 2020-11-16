using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace _1116
{
    class MyApp:Application
    {
        public void MyApp_StartingUp(object sender, StartupEventArgs e)
        {
            MyWindow window = new MyWindow();
            window.Show();
        }

    }
    class MyWindow : Window
    {
        public MyWindow()
        {
            //버튼 생성
            Button btn = new Button();
            btn.Click += btn_Click;
            btn.Width = 100;
            btn.Height = 25;
            //컨텐츠는 하나의 자식 컨텐츠를 가질 수 있다.
            //버튼이 자식 컨텐츠로 '문자열' 
            btn.Content = "클릭";
            //window가 자식 컨텐츠로 버튼
            AddChild(btn);
            Title = "WPF Window";
        }
        void btn_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("버튼 클릭!");
        }
    }
}
