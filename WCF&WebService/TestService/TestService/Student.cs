using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ServiceModel;
using System.Runtime.Serialization;

namespace TestService
{
    [DataContract(Name = "SubjectType")]
    public enum SubjectType
    {
        [EnumMember(Value = "NONE")]
        NONE,
        [EnumMember(Value = "COM")]
        COM,
        [EnumMember(Value = "IT")]
        IT,
        [EnumMember(Value = "GAME")]
        GAME,
        [EnumMember(Value = "ETC")]
        ETC
    }

    [DataContract(Name = "Student")]
    public class Student
    {
        #region 필드&프로퍼티
        [DataMember(Name = "number", Order = 1, IsRequired = true)]
        public readonly int number;
        [DataMember(Name = "name", Order = 2, IsRequired = true)]
        public string name { get; private set; }
        [DataMember(Name = "stype", Order = 3, IsRequired = true)]
        public SubjectType stype { get; set; }

        private int grade;
        [DataMember(Name = "Grade", Order = 4, IsRequired = true)]
        public int Grade
        {
            get { return grade; }
            set
            {
                if (value < 0 || value > 4)
                    throw new Exception("해당 학년은 존재하지 않습니다");
                grade = value;
            }
        }
        #endregion

        #region 생성자
        public Student(int number, string name, SubjectType stype, int grade)//회원가입을 진행하는 경우
        {
            this.number = number;
            this.name = name;
            this.stype = stype;
            this.Grade = grade;
        }
        #endregion

        #region 기능 메서드
        public override string ToString()
        {
            return String.Format("{0},{1},{2},{3}", number, name, stype, grade);
        }
        #endregion

    }
}
