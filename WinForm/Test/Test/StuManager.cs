using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test
{
    class StuManager
    {
        private Dictionary<int, Student> stulist = new Dictionary<int, Student>();


        #region 싱글톤
        private StuManager() { } //1.생성자 은닉
        //2.프로퍼티 선언
        static public StuManager Singleton { get; private set; }
        //3. static 생성자에서 객체 생성 (단 한번 호출되는 문장)
        static StuManager()
        {
            Singleton = new StuManager();//단일체 생성
        }
        #endregion

        #region 입력
        public static string InputString(string msg)
        {
            Console.Write(msg + " : ");
            return Console.ReadLine();
        }
        public static int InputInteger(string msg)
        {
            Console.Write(msg + " : ");
            return int.Parse(Console.ReadLine());
        }
        #endregion

        #region 출력(전달)
        public Dictionary<int,Student>PrintAll()
        {
            return stulist;
        }
        #endregion

        #region 저장 기능
        public bool InsertStudent(Student stu)
        {
            try
            {
                stulist.Add(stu.number, stu);
                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message + "저장이 실패");
                return false;
            }
        }
        #endregion

        #region 검색 함수
        public Student NumberToStudent(int number)
        {
            try
            {
                return stulist[number];
            }
            catch (Exception ex)
            {
                MessageBox.Show("없다 " + ex.Message);
                Student stu = null;
                return stu;
            }
        }
        #endregion

        #region 삭제
        public bool RemoveStudent(int number)
        {
            try
            {
                Student stu = NumberToStudent(number);
                stulist.Remove(stu.number);
                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show("삭제 실패" + ex.Message);
                return false;
            }
        }
        #endregion

        //#region 검색 기능
        //public void SearchStudent()
        //{
        //    try
        //    {
        //        int number = InputInteger("학번");
        //        Student stu = NumberToStudent(number);
        //        Console.WriteLine(stu.ToString());
        //        Console.WriteLine("검색 성공");
        //    }
        //    catch (Exception ex)
        //    {
        //        Console.WriteLine("검색 실패" + ex.Message);
        //    }
        //}
        //#endregion

        #region 수정 기능
        public bool EditStudent(int number,SubjectType stype, int grade)
        {
            try
            {
                Student stu = NumberToStudent(number);
                if (stu == null)
                {
                    throw new Exception("");
                }
                stu.stype = stype;
                stu.Grade = grade;
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }
        #endregion

    }
}
