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

namespace _1117Wpf
{
    /// <summary>
    /// Window_Radio.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window_Radio : Window
    {
        public Window_Radio()
        {
            InitializeComponent();
        }

        private void RadioButton_Checked(object sender, RoutedEventArgs e)
        {
            string msg = "";
            if ((bool)r1.IsChecked)
                msg += "Check1 ";
            if ((bool)r2.IsChecked)
                msg += "Check2 ";
            if ((bool)r3.IsChecked)
                msg += "Check3 ";
            Title = msg;
        }
    }
}
