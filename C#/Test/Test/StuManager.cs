using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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

        #region 출력
        public void PrintAll()
        {
            Console.WriteLine("학생 정보 출력");
            Console.WriteLine("---------------------------------------");
            foreach (KeyValuePair<int, Student> stu in stulist)
            {
                Console.WriteLine(stu.ToString());
            }
        }
        #endregion

        #region 저장 기능
        public void InsertStudent()
        {
            try
            {
                int number = InputInteger("학번");
                string name = InputString("이름");
                Console.WriteLine("학과 번호 : COM(1),IT(2),GAME(3),ETC(4)");
                SubjectType stype = (SubjectType)InputInteger("학과 번호 입력");
                int grade = InputInteger("학년(1~4)");
                Student stu = new Student(number, name, stype, grade);

                stulist.Add(number,stu);
                Console.WriteLine("저장되었습니다");
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message+"저장이 실패");
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
            catch(Exception ex)
            {
                Console.WriteLine("없다"+ ex.Message);
                Student stu = null;
                return stu;
            }
        }
        #endregion

        #region 삭제
        public void RemoveStudent()
        {
            try
            {
                int number = InputInteger("학번");
                Student stu = NumberToStudent(number);
                stulist.Remove(stu.number);
                Console.WriteLine("삭제 성공");
            }
            catch(Exception ex)
            {
                Console.WriteLine("삭제 실패"+ex.Message);
            }
        }
        #endregion

        #region 검색 기능
        public void SearchStudent()
        {
            try
            {
                int number = InputInteger("학번");
                Student stu = NumberToStudent(number);
                Console.WriteLine(stu.ToString());
                Console.WriteLine("검색 성공");
            }
            catch (Exception ex)
            {
                Console.WriteLine("검색 실패" + ex.Message);
            }
        }
        #endregion

        #region 수정 기능
        public void EditStudent()
        {
            try
            {
                int number = InputInteger("학번");
                Student stu = NumberToStudent(number);
                if(stu==null)
                {
                    throw new Exception("");
                }
                Console.WriteLine("학과 번호 : COM(1),IT(2),GAME(3),ETC(4)");
                SubjectType stype = (SubjectType)InputInteger(" 학과 번호를 입력하세요 ");
                stu.stype = stype;
                int grade =InputInteger(" 학년을 입력하세요 (1~4) ");
                Console.WriteLine("수정 성공");
                stu.Grade = grade;
            }
            catch (Exception ex)
            {
                Console.WriteLine("수정 실패" + ex.Message);
            }
        }
        #endregion

    }
}
