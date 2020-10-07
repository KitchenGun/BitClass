using System;
using System.Collections.Generic;
using System.Text;

namespace _1007
{
    [Serializable]
    class ContriAccount:Account
    {
        public int Contribution { get; private set; }

        #region 생성자
        public ContriAccount(int id, string name) : base(id, name)
        {

        }

        public ContriAccount(int id, string name, int balance) : base(id, name, (int)(balance - balance* 0.01))
        {
            Contribution = (int)(balance * 0.01);
        }
        #endregion
        #region 기능함수
        public override void AddMoney(int val)
        {
            base.AddMoney((int)(val-val*0.01));
            Contribution += (int)(val * 0.01);
        }
        public override void ShowAllData()
        {
            base.ShowAllData();
            Console.WriteLine("총기부액 : " + Contribution);
        }

        public override string ToString()
        {
            String temp = String.Format("\t{0}원", Contribution);
            return base.ToString() + temp;
        }
        #endregion
    }
}
