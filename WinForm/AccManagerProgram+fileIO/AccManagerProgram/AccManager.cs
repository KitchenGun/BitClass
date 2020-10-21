using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AccManagerProgram
{
    class AccManager
    {
        #region 싱글톤
        //1. 생성자 은닉
        private AccManager()
        {
          
        }
        //2. 프로퍼티 선언
        static public AccManager Singleton { get; private set; }
        //3. static 생성자에서 객체 생성(단 한번 호출되는 문장)
        static AccManager()
        {
            Singleton = new AccManager();
        }
        #endregion

        private Dictionary<string, NormalAcc> acclist = new Dictionary<string, NormalAcc>();
        public Dictionary<string, NormalAcc> AccList { get { return acclist; } }

        #region 파일 IO
        public void Read()
        {
            
            FileIO.Read();
        }
        public void Write()
        {
            FileIO.Write();
        }
        #endregion

        #region 생성
        //계좌번호 계좌번호 생성(계좌 타입)
        //계좌번호( 일반계좌 1-XXX-YYY, 월정기적금 2-XXX-YYY, 펀드계좌 3-XXX-YYY)
        public string MakeAccountID(AccountType type)
        {
            string id = string.Empty;
            if (type == AccountType.NON)                             throw new Exception("계좌 타입 선택하세요");
            else if (type == AccountType.NORMALACC)        id += 1 + "-";
            else if (type == AccountType.PERDEPOSIT)          id += 2 + "-";
            else if (type == AccountType.FUNDACC)              id += 3 + "-";

            Random r = new Random();
            id += r.Next(0, 1000) + "-";
            id += r.Next(0, 1000);

            return id;
        }
        //성공 실패 계좌 개설(계좌 타입, 계좌 번호,이름,입금액)
        public bool InsertAccount(AccountType type, string id,string name, int money)
        {
            try
            {
                NormalAcc acc = null;
                if (type == AccountType.NORMALACC)
                    acc=new NormalAcc(type, id, name, money);
                acclist.Add(id, acc);
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }
        #endregion

        #region 검색
        //계좌 계좌번호로검색(계좌번호)

        //계좌 계좌번호로검색(계좌번호)
        public NormalAcc IdToAccount(string id)
        {
            return acclist[id];
        }

        //계좌 이름으로검색(이름)
        public List<NormalAcc> NameToAccount(string name)
        {
            List<NormalAcc> temp = new List<NormalAcc>();

            foreach (KeyValuePair<string, NormalAcc> data in acclist)
            {
                if (data.Value.Name.Equals(name) == true)
                {
                    temp.Add(data.Value);
                }
            }
            return temp;
        }

        #endregion

        #region 입출금
        public void InputMoney(string id,int money)
        {
            IdToAccount(id).InputMoney(money);
        }
        public void OutputMoney(string id,int money)
        {
            IdToAccount(id).OutputMoney(money);
        }

        public void TransMoney(string myid,string transid, int money)
        {
            IdToAccount(myid).OutputMoney(money);
            IdToAccount(transid).InputMoney(money);
        }
        #endregion

        #region 삭제
        public void DeleteAccount(string id)
        {
            acclist.Remove(id);
        }
        #endregion

        #region 시뮬레이션
        //시뮬레이션
        public SimulData SimulRun(string id, int count)
        {
            //랜덤객체 생성          
            //반복문 : 반복문의 횟수는 count
            //1) 0~2의 랜덤값을 생성[0:입금, 1:입금 2:출금]
            //2) 1~10의 렌덤값을 생성
            //3) 생성한 렌덤값에 * 1000을 수행 [ 1 -> 1000원, 10 -> 10000원]
            //4) 1번에서 획득한 값이 0이면 혹은 1이면
            //   InputMoney 호출
            //5) 1번에서 획득한 값이 2명 
            //   OutputMoney호출
            //6) Sleep(500)

            //정보반환처리
            //SimulData클래스를 정의[횟수 : 입금횟수:  출금횟수:최종잔액]
            //   생성자에서는 모든 필드값을 0으로 초기화 
            //void 반환타입을 SimulData타입으로 변경
            //[반복문이 끝난 다음]
            //SimulData 객체를 생성
            //count값을 횟수에 저장
            //입금횟수에 inputcount
            //출금횟수에 outputcount
            //해당 계좌번호의 잔액을 반환받아 최종잔액에 저장
            //객체 반환
            int RSelect;
            int RMoney;
            int inputcount=0;
            int outputcount=0;
            #region 연산
            for (int i=0;i<count;i++)
            {
                Random r = new Random();
                RSelect = r.Next(0, 2);
                switch (RSelect)
                {
                    case 0:
                        RMoney= r.Next(1, 10);
                        InputMoney(id, RMoney * 1000);
                        inputcount++;
                        break;
                    case 1:
                        RMoney = r.Next(1, 10);
                        OutputMoney(id, RMoney * 1000);
                        break;
                    case 2:
                        RMoney = r.Next(1, 10);
                        InputMoney(id, RMoney * 1000);
                        break;
                }
            }
            #endregion
            int resultmoney = acclist[id].Balance;
            SimulData data = new SimulData(count,inputcount,outputcount, resultmoney);
            return data;
        }
        #endregion

    }
}
