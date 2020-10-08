using System;
using System.Collections.Generic;
using System.Text;

namespace _1008Event
{
    class MemberSelect
    {
        public Member GetSelectMember(Dictionary<string, Member> members)
        {
            Console.WriteLine("===회원검색===");
            Console.Write("이름을 입력해주세요 : ");
            string name = Console.ReadLine();
            NameCheck(members, name);

            return members[name];
        }

        private void NameCheck(Dictionary<string, Member> members, string name) //동일 이름 체크
        {
            if (name.Length == 0)
                throw new Exception("이름이 입력되지 않았습니다.");
            if (members.ContainsKey(name) != true)
                throw new Exception("동일 이름이 없습니다");
        }

    }
}
