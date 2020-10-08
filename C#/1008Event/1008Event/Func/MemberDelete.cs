using System;
using System.Collections.Generic;
using System.Text;

namespace _1008Event
{
    class MemberDelete
    {
        public void DeleteMember(Dictionary<string, Member> members,Member mem)
        {
            members.Remove(mem.Name);
        }
    }
}
