using System;
using System.Collections.Generic;
using System.Text;

namespace _1007
{
	class AccManager
	{
		//acc를 저장하는 배열 구조 생성
		private Dictionary<int, Account> accounts = new Dictionary<int, Account>();
		//거래리스트
		private List<AccList> acclists = new List<AccList>();
		#region 거래리스트 기능
		private void InsertAccList(int id, int input, int output, int balance)
        {
			AccList acc = new AccList(id, input, output, balance);
			acclists.Add(acc);
        }

		private void SelectAccList(int id, ref List<AccList> list)
		{
			foreach (AccList acc in acclists)
			{
				if (acc.Id == id)
				{
					list.Add(acc);  //<==============
				}
			}
		}


		private void DeleteAccList(int id)
        {
			foreach(AccList ac in acclists)
            {
				if (ac.Id == id)
				{
					acclists.Remove(ac);
				}
            }
        }
        #endregion

        #region 계좌 기능
        private void SearchSameAcc(int id)
		{
			if (accounts.ContainsKey(id) == true)
				throw new Exception("중복 계좌 발견");
	
		} // 중복 계좌 검색용

		public void MakeAccount()              // 계좌 개설을 위한 함수
		{
			try
			{
				Console.WriteLine("계좌 개설 -----------------");
				Console.WriteLine("[1]일반 계좌  [2]신용 계좌 [3]기부계좌");
				int select = WbGlobal.InputInteger(" 계좌 선택 ");
				//===========================
				int id = WbGlobal.InputInteger(" 계좌 ID ");
				SearchSameAcc(id);
				string name = WbGlobal.InputString("이름");
                int balance = WbGlobal.InputInteger(" 입 금 액 ");
				//==============================
				Account acc = null;
				switch (select)
				{
					case 1: acc = new Account(id, name, balance); break;
					case 2: acc = new FaithAccount(id, name, balance); break;
					case 3: acc = new ContriAccount(id, name, balance); break;
					default: throw new Exception("잘못된 계좌를 선택");
				}
				accounts.Add(acc.Id,acc);
				Console.WriteLine("계좌 개설이 완료되었습니다.");
				//거래 리스트를 저장
				InsertAccList(id, balance, 0, balance);

			}
			catch (Exception ex)
			{
				Console.WriteLine("계좌 개설이 실패하었습니다.");
				Console.WriteLine("원인 : " + ex.Message);
			}
		}

		public void SearchAllAccount()                 // 잔액 조회
		{
			Console.WriteLine("저장개수 : " + accounts.Count);
			Console.WriteLine("---------------------------------------");
			foreach (KeyValuePair<int, Account> kvp in accounts)
			{
				//Console.WriteLine("Key = {0}, Value = {1}",kvp.Key, kvp.Value);
				Account acc = kvp.Value;
				Console.WriteLine(acc); // acc.tostring()
			}
		}

		public void Deposit()                  // 입 금
		{
			try
			{
				int id = WbGlobal.InputInteger("계좌ID");
				int money = WbGlobal.InputInteger("입금액");

				Account acc = accounts[id];  
				acc.AddMoney(money);
				Console.WriteLine("입금 완료");
				//거래리스트 저장
				InsertAccList(id, money, 0, acc.Balance);
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
				Account acc = accounts[id];  //????
				acc.MinMoney(money);
				Console.WriteLine("출금 완료");
				//거래리스트 저장
				InsertAccList(id, money, 0, acc.Balance);
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
				Account acc = accounts[id];  //????
				acc.ShowAllData();
				Console.WriteLine("조회 완료");
				//거래리스트
				List<AccList> alist = new List<AccList>();
				SelectAccList(id, ref alist);
				Console.WriteLine("\n거래 내역");
				foreach(AccList ac in alist)
                {
					Console.WriteLine(ac);//ac.tostring();
                }

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
				if (accounts.Remove(id) == false)
				{
					throw new Exception(" 계좌가 없습니다");
				}
				Console.WriteLine("삭제 완료");
				//거래내역도 삭제
				DeleteAccList(id);
			}
			catch (Exception ex)
			{
				Console.WriteLine("삭제 에러가 발생했습니다.");
				Console.WriteLine("원인" + ex.Message);
			}
		}

        #endregion

        #region 파일 IO 기능
        public void Init()
		{
			FileExample.Read2(ref accounts);
		}
		public void Exit()
        {
			FileExample.Write2(accounts);
        }
        #endregion
    }
}
