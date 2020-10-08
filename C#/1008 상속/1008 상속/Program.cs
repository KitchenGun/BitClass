using System;
using System.Collections.Generic;
using System.Text;

namespace _1008_상속
{
    class Program
    {
        private List<Member> memlist = new List<Member>();

        public void SampleDataInput()
        {
            memlist.Add(new Member(10, "홍길동", 80));
            memlist.Add(new Member(5, "김길동", 90));
            memlist.Add(new Member(30, "최길동", 100));
            memlist.Add(new Member(7, "이길동", 75));
            memlist.Add(new Member(18, "박길동", 98));
            memlist.Add(new Member(2, "허길동", 69));
        }
        public void SortTest()
        {
            
            memlist.Sort(new NameMemberComparer("Down"));
        }

        public void PrintData()
        {
            foreach(Member mem in memlist)
            {
                Console.WriteLine(mem);
            }
        }
        static void Main(string[] args)
        {
            Program p = new Program();
            p.SampleDataInput();
            p.SortTest();
            p.PrintData();
        }
    }
}
