using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 논리적_DB_1029
{
    class LogicalDB
    {
        //xml 관련 변수
        readonly string schema_fname = "books.xsd";
        readonly string fname = "book.xml";
        //테이블
        public DataTable BookTable { get; set; }
        //테이블 내부 값
        public string BookTableName { get { return BookTable.TableName.ToString(); } }
        public int BookTableColumnCount { get { return BookTable.Columns.Count; } }
        public DataColumnCollection bookColumns { get { return BookTable.Columns; } }
        //데이터 테이블 생성
        public void CreateTable()
        {
            BookTable = new DataTable("Books");
            //4개 컬럼 추가::pid 자동증가,Name,Price,BirthDate
            DataColumn dc_pid = new DataColumn();
            dc_pid.ColumnName = "PID";
            dc_pid.DataType = typeof(int);
            //자동 증가
            dc_pid.AutoIncrement = true;
            dc_pid.AutoIncrementSeed = 1;
            dc_pid.AutoIncrementStep = 1;
            //등록
            BookTable.Columns.Add(dc_pid);

            DataColumn dc_name = new DataColumn("Name",typeof(string));
            dc_name.AllowDBNull = false;
            BookTable.Columns.Add(dc_name);

            DataColumn dc_price= new DataColumn("Price", typeof(int));
            dc_price.AllowDBNull = false;
            BookTable.Columns.Add(dc_price);

            DataColumn dc_birthdate = new DataColumn("BirthDate", typeof(DateTime));
            dc_birthdate.AllowDBNull = false;
            BookTable.Columns.Add(dc_birthdate);
            //primary key 등록
            DataColumn[] pkeys = new DataColumn[1];
            pkeys[0] = dc_pid;

        }

        //데이터 테이블과 동기화
        public void BindingGridView(DataGridView dgv)
        {
            dgv.DataSource = BookTable;
        }

        //생성
        public void InsertBook(string name,int price, DateTime dt)
        {
            try
            {
                DataRow dr = BookTable.NewRow();
                dr["Name"] = name;
                dr["Price"] = price;
                dr["BirthDate"] = dt;
                BookTable.Rows.Add(dr);
            }
            catch(Exception e)
            {
                MessageBox.Show(e.Message);
            }
        }

        //삭제
        public void DeleteBook(int pid)
        {
            try
            {
                DataRow dr = BookTable.Rows.Find(pid);
                BookTable.Rows.Remove(dr);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        #region XML
        public void Save()
        {
            //테이블의 구조(컬럼 정보)
            BookTable.WriteXmlSchema(schema_fname, true);

            //테이블의 데이터(로우데이터)
            BookTable.WriteXml(fname, true);
        }

        public void Load()
        {
            if (File.Exists(schema_fname))
            {
                BookTable = new DataTable("Books");
                //테이블의 컬럼 생성
                BookTable.ReadXmlSchema(schema_fname);
                if (File.Exists(fname))
                {
                    //테이블의 로우데이터 저장
                    BookTable.ReadXml(fname);
                }
            }
        }

        #endregion

    }
}
