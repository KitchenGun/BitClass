using System;
using System.Collections.Generic;
using System.Text;

namespace _1007
{
    [Serializable]
    class Account
    {
        #region property 와 생성자
        public int Id { get; private set; }                   // 계좌번호
       public int Balance{ get; private set; }           // 잔    액
       public String Name { get;private set; }
        public DateTime MakeTime { get;  set; }

        public Account(int id, String name):this(id,name,0)
        {
        }

        public Account(int id, String name, int balance)
        {
            Id = id;
            Name = name;
            Balance = balance;
            MakeTime = DateTime.Now;
        }
        #endregion

        #region 기능 함수
        public virtual void AddMoney(int val)
        {
            if (val < 0)        // 마이너스 금액에 대한 예외 발생
                throw new Exception("입금액 "+val.ToString()+" 0이상의 값이 입력이 필요합니다");

            Balance += val;
        }
        public void MinMoney(int val)
        {
            if (val < 0)        // 마이너스 금액에 대한 예외 발생
                throw new Exception("출금액 " + val.ToString() + " 0이상의 값이 입력이 필요합니다");

            if (Balance < val)    // 과잉 출금 요구에 대한 예외 발생
            {
                String temp = String.Format("잔액부족[{0},{1}]", Balance, val);
                throw new Exception(temp);
            }

            Balance -= val;
        }

        public virtual void ShowAllData()
        {
            Console.Write("계좌  ID : " + Id);
            Console.Write("고객 이름 : " + Name);
            Console.Write("잔액 : " + Balance);
            Console.Write("개설일 : " + MakeTime.ToLongDateString());
            Console.Write("개설시 : " + MakeTime.ToLongTimeString());
        }

        public override string ToString()
        {
            String temp = String.Format("[{0}]\t{1}\t{2}원\t{3}", Id, Name, Balance, MakeTime.ToString());
            return temp;
        }
        #endregion

    }
}
