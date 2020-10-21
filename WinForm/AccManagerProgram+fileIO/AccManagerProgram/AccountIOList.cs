using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AccManagerProgram
{
    /// <summary>
    /// 계좌 거래 리스트
    /// </summary>
    class AccountIOList
    {
        #region 프로퍼티
        private readonly string id;
        public string Id { get { return id; } }

        private readonly int input;
        public int Input { get { return input; } }

        private readonly int output;
        public int Output { get { return output; } }

        public int Balance { get; private set; }

        private readonly DateTime stime;
        public DateTime Stime { get { return stime; } }
        public string StimeDay { get { return stime.ToShortDateString(); } }
        public string StimeTime { get { return stime.ToShortTimeString(); } }
        //계좌 거래 저장 리스트
        private List<AccountIOList> acclist = new List<AccountIOList>();
        public List<AccountIOList> AccList { get { return acclist; } }
        #endregion
        #region 생성자
        public AccountIOList(string _id, int _input, int _output, int _balance)
        {
            id = _id;
            input = _input;
            output = _output;
            Balance = _balance;
            stime = DateTime.Now;

        }
        #endregion
        #region 메서드
        public void InputMoney(int money)
        {
            if (money <= 0)
                throw new Exception("[입금오류] 잘못된 입금요청 : " + money + "원");
            Balance += money;
            InputAccList(Id, money, 0, Balance);
        }

        public void OutputMoney(int money)
        {
            if (money <= 0)
                throw new Exception("[출금오류] 잘못된 출금요청 : " + money + "원");
            if (Balance < money)
                throw new Exception("[출금오류] 잔액부족 : " + money + "원");
            Balance -= money;
        }
        private void InputAccList(string _id, int _input, int _output, int _balance)
        {
            AccList.Add(new AccountIOList(_id, _input, _output, _balance));
        }
        //계좌 객체 삭제 의미
        public void Dispose()
        {
            //계좌 거래 리스트 제거
            AccList.Clear();
        }

        #endregion
    }
}
