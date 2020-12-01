using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    enum SubjectType
    {
        NONE,
        COM,
        IT,
        GAME,
        ETC
    }

    class Student
    {
        #region 필드&프로퍼티
        public readonly int number;
        public string name { get; private set; }
        public SubjectType stype { get; set; }
        private int grade;
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
        public Student()
        {

        }
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
