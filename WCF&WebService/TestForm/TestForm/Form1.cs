using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.ServiceModel;
using TestForm.ServiceReference1;

namespace TestForm
{
    public partial class Form1 : Form
    {
        public StuManagerClient stum = new StuManagerClient();
      
        public Form1()
        {
            InitializeComponent();
        }
        #region MenuStrip
        private void 프로그램정보ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("강건\n2020-12-01", "학생 저장 프로그램");
        }
        private void 프로그램종료ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        #endregion

        #region 폼 로드&클로스
        private void Form1_Load(object sender, EventArgs e)
        {
            PrintStudent();
        }
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
        }
        #endregion

        #region list 관련 함수
        //출력
        private void PrintStudent()
        {
            listView1.Items.Clear();
           Student[] stulist = stum.PrintAll();
            foreach (Student stu in stulist)
            {
                string subject = transSub(stu.stype);
                listView1.Items.Add(new ListViewItem(new string[] {
                    stu.number.ToString(),
                    stu.name,
                    subject,
                    stu.Grade.ToString()
                     }));
            }
            label2.Text = string.Format("총 학생수 : {0}명", listView1.Items.Count);
        }
        //학과 정보 형 변환
        private string transSub(SubjectType stype)
        {
            switch (stype)
            {
                case SubjectType.COM:
                    return "컴퓨터";
                case SubjectType.IT:
                    return "IT";
                case SubjectType.GAME:
                    return "게임";
                case SubjectType.ETC:
                    return "기타";
                default:
                    return null;
            }

        }

        //학과 정보 형 역변환
        private int transSubtoInt(string stype)
        {
            switch (stype)
            {
                case "컴퓨터":
                    return 0;
                case "IT":
                    return 1;
                case "게임":
                    return 2;
                case "기타":
                    return 3;
                default:
                    return 0;
            }

        }
        #endregion

        #region 삽입
        private void 회원정보입력ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Form2를 생성한 목적 : 사용자 입력
            Form2 form2 = new Form2();
            if (form2.ShowDialog() == DialogResult.OK)
            {
                //정보 횓득
                Student stu = form2.GetStudentInfo();
                //Manager전달 
                stum.StuInsert(stu);

                PrintStudent();
            }

        }
        #endregion

        #region 검색
        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listView1.SelectedItems.Count != 0)
            {
                int SelectRow = listView1.SelectedItems[0].Index;

                textBox1.Text = listView1.Items[SelectRow].SubItems[0].Text;

            }

        }
        private void button1_Click(object sender, EventArgs e)
        {
            try
            {

                Student stu = stum.NumberToStudent(int.Parse(textBox1.Text));

                textBox1.Text = stu.number.ToString();
                textBox2.Text = stu.name;
                comboBox1.SelectedIndex = (int)stu.stype - 1;
                comboBox2.SelectedIndex = stu.Grade - 1;
            }
            catch
            {

            }

        }


        #endregion

        #region 삭제
        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                //number 정보 회득
                int number = int.Parse(textBox1.Text);
                //메니저 
                stum.StuDelete(number);

                PrintStudent();
                TextClear();
            }
            catch
            {

            }
        }

        #endregion

        #region 수정
        private void button3_Click(object sender, EventArgs e)
        {
            //정보 획득
            int number = int.Parse(textBox1.Text);
            SubjectType stype = (SubjectType)(comboBox1.SelectedIndex + 1);
            int grade = (comboBox2.SelectedIndex + 1);

            //메니저 전달
            stum.StuUpdate(number, stype, grade);
            PrintStudent();
            TextClear();
        }
        #endregion

        #region 입력창 초기화
        private void TextClear()
        {
            textBox1.Text = "";
            textBox2.Text = "";
            comboBox1.SelectedIndex = 0;
            comboBox2.SelectedIndex = 0;
        }
        #endregion
    }
}
