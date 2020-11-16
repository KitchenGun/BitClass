using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace _1116
{
    class Program
    {
        static void Exam1()
        {
            MessageBox.Show("First WPF!!");
        }
        static void Exam2()
        {
            MyApp app = new MyApp();
            app.Startup += app.MyApp_StartingUp;
            app.Run();
        }

        [STAThread]
        static void Main(string[] args)
        {
            MyApp app = new MyApp();
            app.Startup += app.MyApp_StartingUp;
            app.Run();
        }
    }
}
