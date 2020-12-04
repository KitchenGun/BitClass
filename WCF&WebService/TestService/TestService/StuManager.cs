using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TestService
{
    public class StuManager : IStuManager
    {
        //List<Student> stulist = new List<Student>();
        DB db = new DB();

        #region 검색
        public Student NumberToStudent(int number)
        {
            try
            {
                return db.SelectStuToNum(number);
            }
            catch (Exception ex)
            {
                MessageBox.Show("없다 "+ex.Message);
                Student stu = null;
                return stu;
            }
        }
        #endregion
        #region 출력
        public List<Student> PrintAll()
        {
            try
            {
                return db.PrintStudentAll();
            }
            catch (Exception ex)
            {
                MessageBox.Show("불러오기 실패" + ex.Message);
                return null;
            }
        }
        #endregion
        #region 삭제
        public bool StuDelete(int number)
        {
            try
            {
                db.DeleteStudent(number);
                MessageBox.Show("삭제 성공");
                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show("삭제 실패 " + ex.Message);
                return false;
            }
        }
        #endregion
        #region 삽입
        public bool StuInsert(Student stu)
        {
            try
            {
                db.InsertStudent(stu);

                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show("저장 실패 " + ex.Message);
                return false;
            }
        }
        #endregion
        #region 수정
        public bool StuUpdate(int number, SubjectType type, int grade)
        {
            try
            {
                db.UpdateStudent(number, type, grade);
                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show("수정 실패 " + ex.Message);
                return false;
            }
        }
        #endregion
    }
}
