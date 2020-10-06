using System;
using System.Collections.Generic;
using System.Text;

namespace 예약_관리_프로그램_10_06
{
    class Bus
    {
        int[,] Seat =new int[4, 10];
        #region 생성자
        public  Bus() //배열 초기화
        {
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 10; ++j)
                {
                    Seat[i, j] = 0;
                }
            }
        }
        #endregion

        #region 예약
        public void ReserveBusSeat(int id, ref Member mem)
        {
            try
            {
                int x = WbGlobal.InputInteger("좌석 행 입력");
                int y = WbGlobal.InputInteger("좌석 열 입력");
                //중복체크
                if(!SearchSameSeat(x, y))
                {
                    Seat[x, y] = id;//예약
                    mem.SeatX = x;
                    mem.SeatY = y;
                }
                else
                {
                    throw new Exception("중복된 자리 입니다.");
                }
            }
            catch(Exception ex)
            {
                Console.WriteLine("좌석 예매가 실패하었습니다.");
                Console.WriteLine("원인 : " + ex.Message);
            }
        }
        #endregion

        #region 예약 취소
        public void CancelReserveBusSeat(int id, ref Member mem)
        {
            try
            {
               int x= SearchBusSeatX(id);
                int y = SearchBusSeatY(id);
                Seat[x, y] = 0;//예약
                mem.SeatX = 0;
                mem.SeatY = 0;
            }
            catch (Exception ex)
            {
                Console.WriteLine("좌석 예매가 실패하었습니다.");
                Console.WriteLine("원인 : " + ex.Message);
            }
        }
        #endregion

        #region 예약 좌석 검색


        #endregion

        #region 중복 자리검색
        private bool SearchSameSeat(int x , int y)      //중복 회원검색
        {
            if (Seat[x, y] != 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        #endregion

        #region 자리 검색

        public int SeatCheck(int x,int y) //좌석으로 id 검색
        {
            if (Seat[x, y] == 0)
               Console.WriteLine("해당좌석은 비어 있습니다.");
            return Seat[x, y];
        }
        public int SearchBusSeatX(int id)//삭제용
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                   if( Seat[i, j] == id)
                   {
                       return i;
                   }
                }
            }
            throw new Exception("해당하는 예약 회원이 없습니다.");
        }

        public int SearchBusSeatY(int id)//삭제용
        {
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 10; ++j)
                {
                    if (Seat[i, j] == id)
                    {
                        return j;
                    }
                }
            }
            return 0;
        }
        #endregion

        #region 출력
        public void BusSeatPrint()
        {
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 10; ++j)
                {
                    if (Seat[i, j] == 0)
                    {
                        Console.Write("X");
                    }
                    else
                    {
                        Console.Write("O");
                    }
                }
                Console.WriteLine("");
            }
        }

        #endregion
    }
}
