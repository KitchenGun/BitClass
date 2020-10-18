using System;
using System.Collections.Generic;
using System.Text;

namespace _1012Net
{
    class Member
    {
        public string ID { get; set; }
        public string PW { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }
        public DateTime Dt { get; set; }

        public Member() { }

        public Member(string id, string pw, string name, int age)
        {
            ID = id;
            PW = pw;
            Name = name;
            Age = age;
            Dt = DateTime.Now;
        }

        public override string ToString()
        {
            String temp = String.Format("{0}\t{1}\t{2}\t{3}\t{4}\t{5}",
              ID, PW, Name, Age, Dt.ToLongDateString(), Dt.ToLongTimeString());
            return temp;
        }
    }
}

