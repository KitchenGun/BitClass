using System;
using System.Collections.Generic;
using System.Text;

namespace _1008Event
{
    /// <summary>
    /// 이벤트 전달 인자 객체 델리게이트
    /// </summary>
    #region 회원가입
    class AddMemberEventArgs
    {
        public Member Member { get; private set; }
        public Dictionary<string, Member> MemberList { get; private set; }

        public AddMemberEventArgs(Member mem, Dictionary<string, Member> memberlist)
        {
            Member = mem;
            MemberList = memberlist;
        }
    }
    delegate void AddMemberEvent(Object obj, AddMemberEventArgs e);
    #endregion

}
