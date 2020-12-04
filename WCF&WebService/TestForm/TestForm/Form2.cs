using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TestForm.ServiceReference1;

namespace TestForm
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        #region 저장 버튼처리
        private void button1_Click_1(object sender, EventArgs e)
        {
            DialogResult = DialogResult.OK;
            this.Close();
        }

        private void TextClear()
        {
            textBox1.Text = "";
            textBox2.Text = "";
            comboBox1.SelectedIndex = 0;
            comboBox2.SelectedIndex = 0;
        }

        public Student GetStudentInfo()
        {
            int number = int.Parse(textBox1.Text);
            string name = textBox2.Text;
            int subject = comboBox1.SelectedIndex + 1;
            SubjectType stype = (SubjectType)subject;
            int grade = int.Parse(comboBox2.SelectedItem.ToString());
            
            Student stu = new Student(number, name, stype, grade);
            return stu;
        }
        #endregion


    }
}
