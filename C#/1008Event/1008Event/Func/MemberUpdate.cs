using System;
using System.Collections.Generic;
using System.Text;

namespace _1008Event
{
    /// <summary>
    ///  검색 정보를 입력 받아 객체를 반환
    /// </summary>
    class MemberUpdate
    {
        public void UpdateAddr(Member mem)
        {
            Console.Write("주소 : ");
            string addr = Console.ReadLine();
            InputDataCheck(addr);
            mem.Addr = addr;
        }
        private void InputDataCheck(string addr)
        {
            if (addr.Length == 0)
                throw new Exception("주소가 입력되지 않았습니다.");
        }
    }
}
