using System;
using System.Collections.Generic;
using System.Text;

namespace _1007
{
    [Serializable]
    class FaithAccount:  Account
    {
        public FaithAccount(int id, string name, int balance):base(id,name, (int)(balance + balance * 0.01))
        {

        }
        public FaithAccount(int id,string name):base(id,name)
        {

        }
        public override void AddMoney(int val)
        {
            base.AddMoney((int)(val + val * 0.01));
        }
    }
}
