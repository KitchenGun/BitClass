using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.ServiceModel;
using System.Runtime.Serialization;

namespace TestService
{
    [ServiceContract]
    interface IStuManager
    {
        [OperationContract]
        List<Student> PrintAll();
        [OperationContract]
        bool StuInsert(Student stu);
        [OperationContract]
        Student NumberToStudent(int number);
        [OperationContract]
        bool StuDelete(int number);
        [OperationContract]
        bool StuUpdate(int number, SubjectType type, int grade);
    }
}
