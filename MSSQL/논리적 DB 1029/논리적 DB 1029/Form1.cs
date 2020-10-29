using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 논리적_DB_1029
{
    public partial class Form1 : Form
    {
        LogicalDB db = new LogicalDB();

        public Form1()
        {
            InitializeComponent();
        }

        #region 데이터 테이블 생성
        private void button1_Click(object sender, EventArgs e)
        {
            db.CreateTable();
            //동기화
            db.BindingGridView(dataGridView1);
            
            //테이블 정보 출력
            listBox1.Items.Add("-테이블 명 : " + db.BookTableName);
            listBox1.Items.Add("-컬럼 개수 : " + db.BookTableColumnCount+"개");
            listBox1.Items.Add("---------------------------");
            foreach(DataColumn c in db.bookColumns)
            {
                listBox1.Items.Add(string.Format("{0}\t{1}", c.ColumnName, c.DataType));
            }
           
        }
        #endregion

        #region 데이터 생성
        private void button2_Click(object sender, EventArgs e)
        {
            string name = textBox1.Text;
            int price = int.Parse(textBox2.Text);
            DateTime dt = dateTimePicker1.Value;
            db.InsertBook(name, price, dt);
        }
        #endregion

        #region 데이터 삭제

        #endregion

        #region 데이터 그리드 뷰 클릭
        private void dataGridView1_SelectionChanged(object sender, EventArgs e)
        {
            try
            {
                var pid = dataGridView1.SelectedCells[0].Value.ToString();
                textBox3.Text = pid;
                var name = dataGridView1.SelectedCells[1].Value.ToString();
                textBox1.Text = name;
                var price = dataGridView1.SelectedCells[2].Value.ToString();
                textBox2.Text = price.ToString();
                var dt = dataGridView1.SelectedCells[3].Value.ToString();
                dateTimePicker1.Value = DateTime.Parse(dt);
            }
           catch
            {

            }
        }
        #endregion

        private void button3_Click(object sender, EventArgs e)
        {
            int pid = int.Parse(textBox3.Text);
            db.DeleteBook(pid);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            db.Save();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            db.Load();
            db.BindingGridView(dataGridView1);
        }
    }
}
