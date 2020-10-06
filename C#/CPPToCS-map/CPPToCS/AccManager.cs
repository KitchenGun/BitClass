using System;
using System.Collections.Generic;
using System.Text;

namespace CPPToCS
{
	class AccManager
	{
		//key 계좌의 id value account
		private Dictionary<int,Account> acclist = new Dictionary<int, Account>();
		private void SearchSameAcc(int id)		//중복 계좌검색
		{
			if (acclist.ContainsKey(id) == true)
				throw new Exception("중복된 ID가 있습니다.");
		}


		public void MakeAccount()              // 계좌 개설을 위한 함수
		{
			try
			{
				Console.WriteLine("계좌 개설 -----------------");
				int id = WbGlobal.InputInteger(" 계좌 ID ");
				SearchSameAcc(id);
				string name = WbGlobal.InputString("이름");
				int balance = WbGlobal.InputInteger(" 입 금 액 ");
				Account acc = new Account(id, name, balance);
				acclist.Add(id,acc);
				Console.WriteLine("계좌 개설이 완료되었습니다.");
			}
			catch (Exception ex)
			{
				Console.WriteLine("계좌 개설이 실패하었습니다.");
				Console.WriteLine("원인 : " + ex.Message);
			}
		}

		public void SearchAllAccount()       // 전체 저장정보 출력.순회
		{
			Console.WriteLine("저장개수 : " + acclist.Count);
			Console.WriteLine("---------------------------------------");
			foreach (KeyValuePair<int, Account> kvp in acclist)
			{
				//Console.WriteLine("Key = {0}, Value = {1}",kvp.Key, kvp.Value);
				Account acc = kvp.Value;
				acc.ShowAllData1();
			}
		}


		public void Deposit()                  // 입 금
		{
			try
			{
				int id = WbGlobal.InputInteger("계좌ID");
				int money = WbGlobal.InputInteger("입금액");

				Account acc = acclist[id];  //????
				acc.AddMoney(money);
				Console.WriteLine("입금 완료");
			}
			catch (Exception ex)
			{
				Console.WriteLine("입금 에러가 발생했습니다.");
				Console.WriteLine("원인 : " + ex.Message);
			}
		}


		public void Withdraw()             // 출 금
		{
			try
			{
				int id = WbGlobal.InputInteger(" 계 좌 ID ");
				int money = WbGlobal.InputInteger(" 출 금 액 ");
				Account acc = acclist[id];  //????
				acc.MinMoney(money);
				Console.WriteLine("출금 완료");
				return;
			}
			catch (Exception ex)
			{
				Console.WriteLine("출금 에러가 발생했습니다.");
				Console.WriteLine("원인" + ex.Message);
			}
		}


		public void SelectAccount()     //조회
		{
			try
			{
				int id = WbGlobal.InputInteger(" 계 좌 ID ");
				Account acc = acclist[id];  //????
				acc.ShowAllData1();
						Console.WriteLine("조회 완료");
						return;
			}
			catch (Exception ex)
			{
				Console.WriteLine("조회 에러가 발생했습니다.");
				Console.WriteLine("원인" + ex.Message);
			}
		}

		public void DeleteAccount()
        {
			try
			{
				int id = WbGlobal.InputInteger(" 계 좌 ID ");
				if(acclist.Remove(id)==false)
                {
					throw new Exception(" 계좌가 없습니다");
                }
				Console.WriteLine("삭제 완료");
				return;
				
			}
			catch (Exception ex)
			{
				Console.WriteLine("삭제 에러가 발생했습니다.");
				Console.WriteLine("원인" + ex.Message);
			}
		}

	}
}
