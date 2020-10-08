﻿using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Text;

namespace _1008_상속
{
    class Member:IComparable
    {
        public int Id { get; private set; }
        public String Name { get; private set; }
        public int Jumsu { get; set; }
        
        public Member (int id , string name , int jumsu)
        {
            Id = id;
            Name = name;
            Jumsu = jumsu;
        }

        public override string ToString()
        {
            return String.Format("{0}\t{1}\t{2}\t",Id,Name,Jumsu);
        }

        public int CompareTo(object obj)
        {
            Member member = obj as Member;
            if(member==null)
            {
                throw new Exception("입력정보가 다른 객체입니다.");
            }
            return Id - member.Id; // 비교
        }
    }
    class NameMemberComparer : IComparer<Member>
    {
        public string Msg { get; private set; }
        public NameMemberComparer(string msg)
        {
            Msg = msg;
        }
        public int Compare(Member x, Member y)
        {
            if (x == null || y == null)
            {
                throw new Exception("객체가 전달되지 않았습니다.");
            }

            if (Msg.Equals("UP"))
            {
                return x.Name.CompareTo(y.Name);
            }
            else if (Msg.Equals("DOWN"))
            {
                return y.Name.CompareTo(x.Name);
            }
            else
            {
                return x.Name.CompareTo(y.Name);
            }
        }
    }


    class JumsuMemberComparer : IComparer<Member>
    {
        public int Compare(Member x,Member y)
        {
            if (x == null || y == null)
            {
                throw new Exception("오류");
            }
            return x.Jumsu-y.Jumsu;
        }
    }
}
