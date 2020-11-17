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
    /// Window1.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window1 : Window
    {
        public Window1()
        {
            InitializeComponent();
        }
        private void CheckBox_Checked(object sender, RoutedEventArgs e)
        {
            string msg = "";
            if ((bool)check1.IsChecked)
                msg += "Check1 ";
            if ((bool)check2.IsChecked)
                msg += "Check2 ";
            if ((bool)check3.IsChecked)
                msg += "Check3 ";
            Title = msg;
        }

        private void Check1_Unchecked(object sender, RoutedEventArgs e)
        {
            string msg = "";
            if ((bool)check1.IsChecked)
                msg += "Check1 ";
            if ((bool)check2.IsChecked)
                msg += "Check2 ";
            if ((bool)check3.IsChecked)
                msg += "Check3 ";
            Title = msg;
        }
    }
}
