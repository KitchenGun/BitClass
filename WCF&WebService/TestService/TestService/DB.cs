using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestService
{
    class DB
    {
        public Boolean DBLogin { get; set; }
        public string ConMsg { get; private set; }
        SqlConnection scon;

        public DB()
        {
            DBLogin = false;
            ConMsg = @"Data Source =DESKTOP-4IV1O4J\SQLEXPRESS;Initial Catalog=WbDB; User ID=kangkeon;Password=kang124";
            scon = new SqlConnection(ConMsg);
        }

        #region 연결&연결해제
        public Boolean Connect()
        {
            try
            {
                scon.Open();
                DBLogin = true;
                return true;
            }
            catch (Exception)
            {
                //MessageBox.Show(ex.Message);
                return false;
            }
        }

        public Boolean DisConnect()
        {
            try
            {
                scon.Close();
                DBLogin = false;
                return false;
            }
            catch (Exception)
            {
                //MessageBox.Show(ex.Message);
                return true;
            }
        }
        #endregion

        #region 학생 추가
        public Boolean InsertStudent(Student stu)
        {
            try
            {
                Connect();
                string comtxt = string.Format("insert into Student (number, name, stype, grade) values ({0}, '{1}', {2}, {3})",
                    stu.number, stu.name, (int)stu.stype, stu.Grade);

                SqlCommand scom = new SqlCommand(comtxt, scon);
                scom.ExecuteNonQuery();
                scom.Dispose();
                DisConnect();
                return true;
            }
            catch (Exception)
            {
                DisConnect();
                return false;
            }
        }

        #endregion

        #region 학생 불러오기
        public List<Student> PrintStudentAll()
        {
            Connect();
            List<Student> list = new List<Student>();

            string comtext = "Select * from Student";
            SqlCommand command = new SqlCommand(comtext, scon);

            //select
            SqlDataReader reader = command.ExecuteReader();
            while (reader.Read())
            {
                Student stu = new Student(int.Parse(reader[0].ToString()), reader[1].ToString(), (SubjectType)(int.Parse(reader[2].ToString())), int.Parse(reader[3].ToString()));
                list.Add(stu);
            }
            reader.Close();             //반드시 닫아야함
            command.Dispose();   //반드시 닫아야함
            DisConnect();
            return list;
        }
        #endregion

        #region 학생 찾기
        public Student SelectStuToNum(int number)
        {
            Connect();
            List<Student> list = new List<Student>();

            string comtext = string.Format("Select * from Student where number ={0}", number);
            SqlCommand command = new SqlCommand(comtext, scon);

            //select
            SqlDataReader reader = command.ExecuteReader();
            while (reader.Read())
            {
                Student stu = new Student(
                                        int.Parse(reader[0].ToString()),
                                        reader[1].ToString(),
                                        (SubjectType)int.Parse(reader[2].ToString()),
                                        int.Parse(reader[3].ToString()));
                list.Add(stu);
            }
            reader.Close();         //<=========
            command.Dispose();      //<=========
            DisConnect();
            return list[0];

        }
        #endregion

        #region 삭제
        public Boolean DeleteStudent(int number)
        {
            try
            {
                Connect();
                string comtxt = string.Format("delete from Student where number = {0}", number);

                SqlCommand scom = new SqlCommand(comtxt, scon);
                scom.ExecuteNonQuery();
                scom.Dispose();
                DisConnect();
                return true;
            }
            catch (Exception)
            {
                DisConnect();
                return false;
            }
        }
        #endregion

        #region 수정
        public Boolean UpdateStudent(int number, SubjectType stype, int grade)
        {
            try
            {
                Connect();

                string comtxt = string.Format("update Student set stype = {1} , grade = {2} where number = {0}", number, (int)stype, grade);

                SqlCommand scom = new SqlCommand(comtxt, scon);
                scom.ExecuteNonQuery();
                scom.Dispose();
                DisConnect();
                return true;
            }
            catch (Exception)
            {
                DisConnect();
                return false;
            }
        }
        #endregion
    }
}
