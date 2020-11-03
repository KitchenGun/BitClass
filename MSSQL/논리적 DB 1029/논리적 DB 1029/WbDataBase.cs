using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 논리적_DB_1029
{
    class WbDataBase
    {
        private DataSet ds = new DataSet("WbDB");
        private string constr = @"Data Source=DESKTOP-4IV1O4J\SQLEXPRESS;Initial Catalog=WbDB; User ID=kangkeon;Password=kang124";
        //xml 변수
        readonly string fname = "book.xml";
        #region 싱글톤
        //1. 생성자 은닉
        private WbDataBase()
        {

        }
        //2. 프로퍼티 선언
        static public WbDataBase Singleton { get; private set; }
        //3. static 생성자에서 객체 생성(단 한번 호출되는 문장)
        static WbDataBase()
        {
            Singleton = new WbDataBase();
        }
        #endregion

        #region 연결
        public DataSet Connect()
        {
            using (SqlConnection con = new SqlConnection(constr))
            {
                string sql = "select * from Product;";

                SqlDataAdapter adapter = new SqlDataAdapter();
                adapter.SelectCommand = new SqlCommand(sql, con);
                //물 DB -> 논 DB
                adapter.FillSchema(ds, SchemaType.Source, "Product");
                adapter.Fill(ds, "Product");
                return ds;
            }
        }
        #endregion

        #region 동기화
        public void Update()
        {
            try
            {
                using (SqlConnection con = new SqlConnection(constr))
                {
                    SqlDataAdapter adapter = new SqlDataAdapter();
                    adapter.InsertCommand = MakeProductInsertCommand(con);
                    adapter.DeleteCommand = MakeProductDeleteCommand(con);
                    adapter.UpdateCommand = MakeProductUpdateCommand(con);
                    adapter.Update(ds, "Product");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        #endregion

        #region 생성
        public void InsertBook(string name, int price, string info)
        {
            try
            {
                DataRow dr = ds.Tables["Product"].NewRow();
                dr["PNAME"] = name;
                dr["Price"] = price;
                dr["Description"] = info;

                ds.Tables["Product"].Rows.Add(dr);
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
            }
        }
        private SqlCommand MakeProductInsertCommand(SqlConnection con)
        {

            string cmd_text = "insert into Product Values(@PNAME, @Price, @Description)";
            SqlCommand cmd = new SqlCommand(cmd_text, con);
            cmd.Parameters.Add("@PNAME", SqlDbType.VarChar, 50, "PNAME");
            cmd.Parameters.Add("@Price", SqlDbType.Int, 4, "Price");
            cmd.Parameters.Add("@Description", SqlDbType.VarChar, 100, "Description");
            return cmd;
        }
        #endregion

        #region 삭제
        public void DeleteProduct(int pid)
        {
            try
            {
                DataRow dr = ds.Tables["Product"].Rows.Find(pid);
                ds.Tables["Product"].Rows.Remove(dr);
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private SqlCommand MakeProductDeleteCommand(SqlConnection con)
        {
            string cmd_text = "delete from Product where PID=@PID";
            SqlCommand cmd = new SqlCommand(cmd_text, con);
            cmd.Parameters.Add("@PID", SqlDbType.Int, 4, "PID");
            return cmd;
        }
        #endregion

        #region 수정

        public void UpdateProduct(int pid,int price , string des)
        {
            DataRow dr = ds.Tables["Product"].Rows.Find(pid);
            dr["Price"] = price;
            dr["Description"] = des;
        }
        private SqlCommand MakeProductUpdateCommand(SqlConnection con)
        {

            string cmd_text = "Update Product set Price=@Price, Description=@Description where (PID = @PID)";
            SqlCommand cmd = new SqlCommand(cmd_text, con);
            cmd.Parameters.Add("@PID", SqlDbType.Int, 4, "PID");
            cmd.Parameters.Add("@Price", SqlDbType.Int, 4, "Price");
            cmd.Parameters.Add("@Description", SqlDbType.VarChar, 100, "Description");
            return cmd;
        }
        #endregion

        #region XML
        public void Save()
        {
            //테이블의 데이터(로우데이터)
            ds.Tables["Product"].WriteXml(fname, true);
        }

        public void Load()
        {
            ds.Tables["Product"].Rows.Clear();
            if (File.Exists(fname))
                {
                    //테이블의 로우데이터 저장
                    ds.Tables["Product"].ReadXml(fname);
                }
        }

        #endregion
    }
}
