using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AccManagerProgram
{
    /// <summary>
    /// 계좌 타입
    /// </summary>
    public enum AccountType
    {
        NON,//선택안함
        NORMALACC, //일반
        PERDEPOSIT, //월정기 적금
        FUNDACC //펀드 계좌
    }
    /// <summary>
    /// 일반 계좌 클래스
    /// </summary>
    [Serializable()]
    class NormalAcc
    {
        #region 프로퍼티 

        //계좌 정보 
        private readonly AccountType type;
        public AccountType Type { get { return type; } }

        private readonly string id;
        public string Id { get { return id; } }

        private readonly string name;
        public string Name { get { return name; } }

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
        public NormalAcc(AccountType _type, string _id, string _name)
            : this(_type, _id, _name, 0)
        {

        }

        public NormalAcc(AccountType _type, string _id, string _name, int balance)
        {
            type = _type;
            id = _id;
            name = _name;
            Balance = balance;
            stime = DateTime.Now;
            InputAccList(Id, Balance, 0, Balance);
        }

        public NormalAcc(AccountType _type, string _id, string _name, int balance,DateTime _stime)
        {
            type = _type;
            id = _id;
            name = _name;
            Balance = balance;
            stime = _stime;
            InputAccList(Id, Balance, 0, Balance);
        }
        #endregion

        #region 메서드 
        //입금
        public void InputMoney(int money)
        {
            if (money <= 0)
                throw new Exception("[입금오류] 잘못된 입금요청 : " + money + "원");

            Balance += money;
            InputAccList(Id, money, 0, Balance);
        }

        //출금
        public void OutputMoney(int money)
        {
            if (money <= 0)
                throw new Exception("[출금오류] 잘못된 출금요청 : " + money + "원");
            if (Balance < money)
                throw new Exception("[출금오류] 잔액부족 : " + money + "원");

            Balance -= money;
            InputAccList(Id, 0, money, Balance);
        }

        //거래 등록 
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
