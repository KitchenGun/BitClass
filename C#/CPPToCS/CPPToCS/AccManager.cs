using System;
using System.Collections.Generic;
using System.Text;

namespace CPPToCS
{
	class AccManager
	{
		//acc를 저장하는 배열 구조 생성
		private List<Account> acclist = new List<Account>();
		private void SearchSameAcc(int id)
		{
			foreach (Account acc in acclist)
			{
				if (acc.Id == id)
				{
					throw new Exception("중복 계좌 발견");
				}
			}
		} // 중복 계좌 검색용

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
				acclist.Add(acc);
				Console.WriteLine("계좌 개설이 완료되었습니다.");
			}
			catch (Exception ex)
			{
				Console.WriteLine("계좌 개설이 실패하었습니다.");
				Console.WriteLine("원인 : " + ex.Message);
			}
		}

		public void SearchAllAccount()                 // 잔액 조회
		{
			//for (int i = 0; i < acclist.Count; i++)
			//{
			//	Account acc = acclist[i];
			//	acc.ShowAllData();
			//}
			foreach (Account acc in acclist)
			{
				acc.ShowAllData1();
			}
		}

		public void Deposit()                  // 입 금
		{
			try
			{
				int id = WbGlobal.InputInteger(" 계 좌 ID ");
				int money = WbGlobal.InputInteger(" 입 금 액 ");

				foreach (Account acc in acclist)
				{
					if (acc.Id == id)
					{
						acc.AddMoney(money);
						Console.WriteLine("입금 완료");
						return;
					}
				}
				throw new Exception("유효하지 않은 ID 입니다.");
			}
			catch (Exception ex)
			{
				Console.WriteLine("입금 에러가 발생했습니다.");
				Console.WriteLine("원인" + ex.Message);
			}
		}

		public void Withdraw()             // 출 금
		{
			try
			{
				int id = WbGlobal.InputInteger(" 계 좌 ID ");
				int money = WbGlobal.InputInteger(" 출 금 액 ");

				foreach (Account acc in acclist)
				{
					if (acc.Id == id)
					{
						acc.MinMoney(money);
						Console.WriteLine("출금 완료");
						return;
					}
				}
				throw new Exception("유효하지 않은 ID 입니다.");

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
				foreach (Account acc in acclist)
				{
					if (acc.Id == id)
					{
						acc.ShowAllData1();
						Console.WriteLine("조회 완료");
						return;
					}
				}
				throw new Exception("유효하지 않은 ID 입니다.");

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
				foreach (Account acc in acclist)
				{
					if (acc.Id == id)
					{
						acclist.Remove(acc);
						Console.WriteLine("삭제 완료");
						return;
					}
				}
				throw new Exception("유효하지 않은 ID 입니다.");
			}
			catch (Exception ex)
			{
				Console.WriteLine("삭제 에러가 발생했습니다.");
				Console.WriteLine("원인" + ex.Message);
			}
		}

	}
}
