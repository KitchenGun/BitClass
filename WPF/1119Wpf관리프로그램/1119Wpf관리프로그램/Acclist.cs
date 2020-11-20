using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1119Wpf관리프로그램
{
    class Acclist:List<Account>
    {
        //유일한 계좌번호[5자리]를 반환하는 함수
        public int GetAccNumber()
        {
            Random r = new Random();
            int temp = r.Next(10000, 100000);
            while (true)
            {
                if (isCheckNumber(temp))
                    return temp;
            }
        }

        private bool isCheckNumber(int number)
        {
            foreach (Account acc in this)
            {
                if (acc.accId == number)
                    return false;
            }
            return true;
        }
    }
}
