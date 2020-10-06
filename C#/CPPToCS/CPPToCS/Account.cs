using System;
using System.Collections.Generic;
using System.Text;

namespace CPPToCS
{
	class Account
	{

		readonly int id;//생성자에서 초기화 수행
		int balance;
		string name;

		#region Get&Set
		public int Balance
		{
			get { return balance; }
			private set { balance = value; }
		}
		public int Id
		{
			get { return id; }
		}
		public string Name
		{
			get { return name; }
			private set { name = value; }
		}
		#endregion

		#region 생성자
		public Account(int id, string name, int balance)
		{
			this.id = id;
			Balance = balance;
			Name = name;
		}

		public Account(Account acc)
		{
			this.id = acc.Id;
			Balance = acc.Balance;
			Name = acc.Name;
		}
		#endregion

		#region 기능구현
		public void AddMoney(int val)
		{
			if (val <= 0)
				throw new Exception("잘못된 금액 입금" + val + "원");
			Balance += val;
		}

		public void MinMoney(int val)
		{
			if (val <= 0)
				throw new Exception("잘못된 금액이 입금되었습니다." + val + "원");
			if (Balance < val)
			{
				string temp = string.Format("잔액이 부족합니다. [잔액 {0}원/요청액 {1}원]", Balance, val);
				throw new Exception(temp);
			}
			Balance -= val;
		}


		public void ShowAllData()
		{
			Console.WriteLine("[ID] " + Id);
			Console.WriteLine("[이름] " + Name);
			Console.WriteLine("[잔액] " + Balance);
		}
		public void ShowAllData1()
		{
			Console.WriteLine(" [ID] " + Id + "\t [이름] " + Name + " \t[잔액] " + Balance);
		}

		#endregion
	}
}
