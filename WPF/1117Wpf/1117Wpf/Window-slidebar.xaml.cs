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
    /// Window_slidebar.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window_slidebar : Window
    {
        public Window_slidebar()
        {
            InitializeComponent();
        }

        private void Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            //Title = ((System.Windows.Controls.Primitives.RangeBase)e.Source).Value.ToString();
            Title = ((int)slider.Value).ToString();
            prog.Value = slider.Value;
        }
    }
}
