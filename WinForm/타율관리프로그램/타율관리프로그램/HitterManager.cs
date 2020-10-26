using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 타율관리프로그램
{
    class HitterManager
    {
        public Dictionary<int, Hitter> HitterList = new Dictionary<int, Hitter>();

        #region 싱글톤
        //1. 생성자 은닉
        private HitterManager()
        {

        }
        //2. 프로퍼티 선언
        static public HitterManager Singleton { get; private set; }
        //3. static 생성자에서 객체 생성(단 한번 호출되는 문장)
        static HitterManager()
        {
            Singleton = new HitterManager();
        }
        #endregion

        #region 생성
        public int MakeID()
        {
            int id = 0;
            Random r = new Random();
            while (true)
            {
                id = r.Next(0, 100);
                if (HitterList.ContainsKey(id) == false)
                    break;
            }
            return id;
        }

        #endregion

        #region 검색
        public Hitter IdToHitter(int id)
        {
            return HitterList[id];
        }
        #endregion

        #region 시뮬레이션
        public void Simu(int simCount,Hitter hitter)
        {
            int result;
            for (int i =0; i< simCount; i++)
            {
               result= RandomSim();

                if (result < 20 && result >= 0)
                    hitter.Hit1count();
                else if (result < 30 && result >= 20)
                    hitter.Hit2count();
                else if (result < 40 && result >= 30)
                    hitter.Hit3count();
                else if (result < 45 && result >= 40)
                    hitter.Homeruncount();
                else if (result < 50 && result >= 45)
                    hitter.Dballcount();
                else if (result < 60 && result >= 50)
                    hitter.Ballscount();
                else if (result < 80 && result >= 60)
                    hitter.Soutcount();
                else if (result < 100 && result >= 80)
                    hitter.HOutcount();
            }
        }

        private int RandomSim()
        {
            Thread.Sleep(10);
            Random r = new Random();
            int result = r.Next(0, 100);
            return result;
        }
        #endregion

    }
}
