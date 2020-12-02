using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test
{
    public class StuManager : IStuManager
    {
        DB db = new DB();

        #region 검색
        Student IStuManager.NumberToStudent(int number)
        {
            try
            {
                return db.SelectStuToNum(number);
            }
            catch (Exception ex)
            {
                MessageBox.Show("없다 " + ex.Message);
                Student stu = null;
                return stu;
            }
        }
        #endregion
        #region 출력
        List<Student> IStuManager.PrintAll()
        {
            try
            {
               return db.PrintStudentAll();
            }
            catch(Exception ex)
            {
                MessageBox.Show("불러오기 실패" + ex.Message);
                return null;
            }
        }
        #endregion
        #region 삭제
        bool IStuManager.StuDelete(int number)
        {
            try
            {
                db.DeleteStudent(number);
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
        bool IStuManager.StuInsert(Student stu)
        {
            try
            {
                db.InsertStudent(stu);
              
                return true;
            }
            catch(Exception ex)
            {
                MessageBox.Show("저장 실패 " + ex.Message);
                return false;
            }
         }
        #endregion
        #region 수정
        bool IStuManager.StuUpdate(int number, SubjectType type, int grade)
        {
            try
            {
                db.UpdateStudent(number,type,grade);
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
