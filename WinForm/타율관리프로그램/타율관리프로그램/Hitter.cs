using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 타율관리프로그램
{
    public enum Position
    {
        NON,
        FIRSTBASEMAN,
        SECONDBASEMAN,
        THIRDBASEMAN,
        SHORTSTOP,
        LEFTFIELD,
        CENTERFIELDER,
        RIGHTFIELDER,
        CATCHER
    }
    public enum BatType
    { 
        NON,
        LEFT,
        RIGHT,
        SWITCH
    }


    class Hitter
    {
        #region 프로퍼티 
        //생성자에 사용
        private readonly int id;
        public int Id { get { return id; } }

        private readonly string name;
        public string Name { get { return name; } }

        private readonly Position hitterPosition;
        public Position HitterPosition { get { return hitterPosition; } }

        private readonly BatType battype;
        public BatType Battype { get { return battype; } }
        //기능변수
        private int playCount;
        public int PlayCount { get { return playCount; } }

        private int count;
        public int Count { get { return count; } }

        private float average;
        public float Average { get { return average; } }

        private int hit1;
        public int Hit1 { get { return hit1; } }
        private int hit2;
        public int Hit2 { get { return hit2; } }
        private int hit3;
        public int Hit3 { get { return hit3; } }
        private int homerun;
        public int Homerun { get { return homerun; } }
        private int balls;
        public int Balls { get { return balls; } }
        private int dball;
        public int Dball { get { return dball; } }
        private int sout;
        public int Sout { get { return sout; } }
        private int hout;
        public int Hout { get { return hout; } }
        #endregion

        #region 생성자
        public Hitter(int _id,string _name, Position _hitterposition, BatType _battype)
        {
            id = _id;
            name = _name;
            hitterPosition = _hitterposition;
            battype = _battype;
            hit1 = hit2 = hit3 = homerun = balls = dball = sout = hout = 0;
        }
        #endregion

        #region 시뮬레이션 수행 함수
        public void Hit1count()
        {
            hit1++;
            CalUpdate();
        }

        public void Hit2count()
        {
            hit2++;
            CalUpdate();
        }

        public void Hit3count()
        {
            hit3++;
            CalUpdate();
        }

        public void Homeruncount()
        {
            homerun++;
            CalUpdate();
        }

        public void Ballscount()
        {
            balls++;
            CalUpdate();
        }

        public void Dballcount()
        {
            dball++;
            CalUpdate();
        }
        public void Soutcount()
        {
            sout++;
            CalUpdate();
        }
        public void HOutcount()
        {
            hout++;
            CalUpdate();
        }
        #endregion

        #region 계산 함수
        private void CalUpdate()
        {
            playCount = CalPlayCount();
            count = CalCount();
            average = BattingAverage();
        }
        private int CalPlayCount()
        {
            return (Hit1+Hit2+Hit3+Homerun+ Balls+ Dball+ Sout+ Hout)/ 5;
        }
        private int CalCount()
        {
            return (Hit1 + Hit2 + Hit3 + Homerun+ Sout + Hout) / 5;
        }
        private float BattingAverage()
        {
            if (CalCount() == 0)
                return 0;
            else
                return (float)(Hit1 + Hit2 + Hit3 + Homerun) / CalCount();
        }
        #endregion
    }
}
