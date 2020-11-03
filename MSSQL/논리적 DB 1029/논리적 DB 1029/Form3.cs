using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 논리적_DB_1029
{
    public partial class Form3 : Form
    {
       
        public Form3()
        {
            InitializeComponent();
        }
        #region 연결
        private void button1_Click(object sender, EventArgs e)
        {
            DataSet ds = WbDataBase.Singleton.Connect();

            //출력
            DataTableSchemaPrint(listBox1, ds.Tables["Product"]);
            //datagridview를 database 테이블과 바인딩 처리
            BindingGridView(dataGridView1, ds.Tables["Product"]);
        }
        #endregion

        #region 선택
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
                textBox4.Text = dt;
            }
            catch
            {

            }
        }
        #endregion

        #region 생성
        private void button2_Click(object sender, EventArgs e)
        {
            string name = textBox1.Text;
            int price = int.Parse(textBox2.Text);
            string des = textBox4.Text;

            WbDataBase.Singleton.InsertBook(name, price, des);
        }
        #endregion

        #region 삭제
        private void button3_Click(object sender, EventArgs e)
        {
            int pid = int.Parse(textBox3.Text);
            WbDataBase.Singleton.DeleteProduct(pid);
        }
        #endregion

        #region 수정
        private void button6_Click(object sender, EventArgs e)
        {

            int pid = int.Parse(textBox3.Text);
            int price=int.Parse(textBox2.Text);
            string info = textBox4.Text;
            WbDataBase.Singleton.UpdateProduct(pid, price, info);
        }
        #endregion

        #region 기능
        private void DataTableSchemaPrint(ListBox lb, DataTable db)
        {
            //테이블 정보 출력            
            lb.Items.Add("- 테이블명 : " + db.TableName);
            lb.Items.Add("- 컬럼개수 : " + db.Columns.Count + "개");
            lb.Items.Add("----------------------------");
            foreach (DataColumn c in db.Columns)
            {
                lb.Items.Add(string.Format("{0}\t{1}", c.ColumnName, c.DataType));
            }
        }

        public void BindingGridView(DataGridView dgv, DataTable dt)
        {
            dgv.DataSource = dt;
        }

        //동기화
        private void button7_Click(object sender, EventArgs e)
        {
            WbDataBase.Singleton.Update();
        }



        #endregion

        #region Xml
        private void button4_Click(object sender, EventArgs e)
        {
            WbDataBase.Singleton.Save();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            WbDataBase.Singleton.Load();
        }
        #endregion
    }
}
