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
    /// WindowDataBinding2.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class WindowDataBinding2 : Window
    {
        private Person per = null;

        public WindowDataBinding2()
        {
            InitializeComponent();
            per = (Person)FindResource("person");
        }

        private void EraseButton_Click(object sender, RoutedEventArgs e)
        {
            per.Name = "";
            per.Phone = "";
            per.Age = null;
        }
    }
}
