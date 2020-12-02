using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Test
{
    interface IStuManager
    {
        List<Student> PrintAll();
        bool StuInsert(Student stu);
        Student NumberToStudent(int number);
        bool StuDelete(int number);
        bool StuUpdate(int number, SubjectType type, int grade);
    }
}
