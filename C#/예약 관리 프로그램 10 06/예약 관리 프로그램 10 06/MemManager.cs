using System;
using System.Collections.Generic;
using System.Text;

namespace 예약_관리_프로그램_10_06
{
    class MemManager
    {
        //key 계좌의 id value account
        private Dictionary<int, Member> memlist = new Dictionary<int, Member>();
		private Bus bus = new Bus();

        #region 중복 회원검색
        private void SearchSameMem(int id)      //중복 회원검색
        {
			if(id==0)
				throw new Exception("ID '0'은 불가능 합니다.");
			if (memlist.ContainsKey(id) == true)
                throw new Exception("중복된 ID가 있습니다.");
        }
		#endregion

		#region 회원가입
		public void MakeMember()              // 계좌 개설을 위한 함수
		{
			try
			{
				Console.WriteLine("회원 가입-----------------");
				int id = WbGlobal.InputInteger(" 회원 ID ");
				SearchSameMem(id);
				string name = WbGlobal.InputString("이름");
				string phone = WbGlobal.InputString(" 전화번호 ");
				Member mem = new Member(id, name, phone);
				memlist.Add(id, mem);
				Console.WriteLine("회원 가입이 완료되었습니다.");
			}
			catch (Exception ex)
			{
				Console.WriteLine("회원 가입이 실패하었습니다.");
				Console.WriteLine("원인 : " + ex.Message);
			}
		}
		#endregion

		#region 회원 탈퇴
		public void DeleteMember()
		{
			try
			{
				int id = WbGlobal.InputInteger(" 회원  ID ");
				if (memlist.Remove(id) == false)
				{
					throw new Exception(" 해당 회원이 없습니다");
				}
				Console.WriteLine("삭제 완료");
				return;

			}
			catch (Exception ex)
			{
				Console.WriteLine("회원 탈퇴 에러가 발생했습니다.");
				Console.WriteLine("원인" + ex.Message);
			}
		}
		#endregion

		#region 전화번호 수정
		public void EditMemberPhone()     //조회
		{
			try
			{
				int id = WbGlobal.InputInteger(" 회원  ID ");
				Member mem = memlist[id];
				string phone = WbGlobal.InputString(" 수정할 전화번호 입력 ");
				mem.Phone = phone;
				Console.WriteLine("수정 완료");
				return;
			}
			catch (Exception ex)
			{
				Console.WriteLine("조회 에러가 발생했습니다.");
				Console.WriteLine("원인" + ex.Message);
			}
		}
		#endregion

		#region 회원 검색
		public void SelectMember()     //조회
		{
			try
			{
				int id = WbGlobal.InputInteger(" 회원  ID ");
				Member mem = memlist[id]; 
				mem.ShowAllData();
				Console.WriteLine("조회 완료");
				return;
			}
			catch (Exception ex)
			{
				Console.WriteLine("조회 에러가 발생했습니다.");
				Console.WriteLine("원인" + ex.Message);
			}
		}
		#endregion

		#region 전체 회원 출력
		public void SearchAllMember()       // 전체 저장정보 출력.순회
		{
			Console.WriteLine("저장개수 : " + memlist.Count);
			Console.WriteLine("---------------------------------------");
			foreach (KeyValuePair<int, Member> kvp in memlist)
			{
				//Console.WriteLine("Key = {0}, Value = {1}",kvp.Key, kvp.Value);
				Member mem = kvp.Value;
				mem.ShowAllData();
			}
		}
        #endregion

        #region 회원 좌석 예약
		public void ReserveBusSeat()
        {
			try
			{
				int id = WbGlobal.InputInteger(" 회원  ID ");
				Member mem = memlist[id];
				Console.WriteLine("조회 완료");
				bus.ReserveBusSeat(id,ref mem);//버스 클래스의 좌석 예약으로 이동
				Console.WriteLine("예약 완료");
				return;
			}
			catch (Exception ex)
			{
				Console.WriteLine("좌석 예약 중 에러가 발생했습니다.");
				Console.WriteLine("원인" + ex.Message);
			}
		}
		#endregion

		#region 회원 좌석 예약 취소
		public void CancelReserveBusSeat()
		{
			try
			{
				int id = WbGlobal.InputInteger(" 회원  ID ");
				Member mem = memlist[id];
				Console.WriteLine("조회 완료");
				bus.CancelReserveBusSeat(id,ref mem);//버스 클래스의 좌석 예약으로 이동
				Console.WriteLine("예약 취소 완료");
				return;
			}
			catch (Exception ex)
			{
				Console.WriteLine("좌석 예약 취소 중 에러가 발생했습니다.");
				Console.WriteLine("원인" + ex.Message);
			}
		}
		#endregion

		#region 좌석 검색
		public void SearchBusSeat()
		{
			try
			{
				int x = WbGlobal.InputInteger(" 좌석 행 ");
				int y = WbGlobal.InputInteger(" 좌석 열 ");
				Console.WriteLine("조회 완료");
				if (bus.SeatCheck(x, y) != 0)
				{
					Console.WriteLine("좌석" + "(" + x + "," + y + ")" + "는 회원번호" + bus.SeatCheck(x, y) + "예약 좌석입니다.");
				}
				return;
			}
			catch (Exception ex)
			{
				Console.WriteLine("좌석 예약 조회 중 에러가 발생했습니다.");
				Console.WriteLine("원인" + ex.Message);
			}
		}
		#endregion

		#region 버스 출력
		public void BusSeatPrint()
        {
			bus.BusSeatPrint();
        }
        #endregion
    }
}
