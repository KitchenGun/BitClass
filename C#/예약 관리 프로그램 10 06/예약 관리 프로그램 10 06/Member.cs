using System;
using System.Collections.Generic;
using System.Text;

namespace 예약_관리_프로그램_10_06
{
    class Member
    {

		readonly int id;//생성자에서 초기화 수행
		string name;
		string phone;
		//좌석
		int seatx;
		int seaty;

		#region Get&Set
		//버스 좌석
		public int SeatX
		{
			get { return seatx; }
			set { seatx = value; }
		}
		public int SeatY
		{
			get { return seaty; }
			set { seaty = value; }
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
		public string Phone
		{
			get { return phone; }
		    set { phone = value; }
		}
		#endregion

		#region 생성자
		public Member(int id, string name, string phone)//회원가입을 진행하는 경우
		{
			this.id = id;
			Name = name;
			Phone = phone;
		}

		public Member(Member mem,int x, int y)// 클래스와 좌석이 넘어온 경우
		{
			this.id = mem.Id;
			Phone = mem.Phone;
			Name = mem.Name;
			SeatX = x;
			SeatY = y;
		}
		#endregion

		#region 기능구현
		public void ShowAllData()			//회원정보 출력
		{
			Console.WriteLine(" [ID] " + Id + "\t [이름] " + Name + " \t[전화번호] " + Phone);
		}

		#endregion
	}
}
