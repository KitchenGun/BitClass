using System;
using System.Collections.Generic;
using System.Text;

namespace _1008Event
{
    class MemberSelectAll
    {
        public void SelectAllMember(Dictionary<string,Member> members)
        {
            Console.WriteLine("저장개수 : " + members.Count);
            foreach(KeyValuePair<string,Member> pair in members)
            {
                Console.WriteLine("[{0}] {1}", pair.Key, pair.Value);
            }
        }
    }
}
