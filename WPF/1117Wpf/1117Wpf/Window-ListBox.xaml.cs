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
    /// Window_ListBox.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window_ListBox : Window
    {
        public Window_ListBox()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string inputname = name.Text;
            string inputphone = phone.Text;

            listbox1.Items.Add(inputname + " " + inputphone);
            combobox1.Items.Add(inputname + " " + inputphone);
        }

        private void Listbox1_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            Title = listbox1.SelectedItem.ToString();
        }
    }
}
