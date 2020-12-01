using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        #region 삽입
        private void button1_Click(object sender, EventArgs e)
        {
            Student stu = GetStudentInfo();
            StuManager.Singleton.InsertStudent(stu);
            this.Close();
        }
        private void TextClear()
        {
            textBox1.Text = "";
            textBox2.Text = "";
            comboBox1.SelectedIndex = 0;
            comboBox2.SelectedIndex = 0;
        }

        private Student GetStudentInfo()
        {
            int number=int.Parse(textBox1.Text);
            string name = textBox2.Text;
            int subject = comboBox1.SelectedIndex+1;
            int grade = int.Parse(comboBox2.SelectedItem.ToString());
            Student stu = new Student(number, name, (SubjectType)subject, grade);
            return stu;
        }
        #endregion
    
    }
}
