using System;
using System.Collections.Generic;
using System.Text;

namespace _1012Net
{
    class Packet
    {
        public static byte[] InsertMember(string id, string name)
        {
            string msg = null;
            msg += "ACK_INSERTMEMBER\a";    // 회원 가입 요청 메시지
            msg += id.Trim() + "#";
            msg += name.Trim();
            return Encoding.Default.GetBytes(msg);
        }
    }
}
