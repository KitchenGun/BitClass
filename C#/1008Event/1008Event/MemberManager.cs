using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace _1008Event
{
    /// <summary>
    /// 이벤트 게시자 : 이벤트 발생시키는 객체
    /// </summary>
    class MemberManager
    {
        #region 싱글톤
        private MemberManager() { } //1.생성자 은닉
        //2.프로퍼티 선언
        static public MemberManager Singleton { get; private set; }
        //3. static 생성자에서 객체 생성 (단 한번 호출되는 문장)
        static MemberManager()
        {
            Singleton = new MemberManager();//단일체 생성
        }

        #endregion

        //이벤트 변수 선언----------------------------------------------------------
        public event AddMemberEvent AddMemberEventHandler = null;
        //---------------------------------------------------------------------------
        private Dictionary<string, Member> members 
                                                 = new Dictionary<string, Member>();
        public void AddMember()
        {
            //MemberAdder addr = new MemberAdder();
            //Member mem = addr.GetInsertMember();
            try
            {
                Member mem = new MemberAddr().GetInsertMember(members);

                members.Add(mem.Name, mem);
                Console.WriteLine("저장되었습니다\n");
                //이벤트 발생===================================
                if (AddMemberEventHandler != null)
                {
                    AddMemberEventHandler(this, new AddMemberEventArgs(mem, members));
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine("[저장에러]" + ex.Message);
            }
        }

        public void SelectAllMember()
        {
            new MemberSelectAll().SelectAllMember(members);
        }

        public void SelectMember()
        {
            try
            {
                //이름이 없는 객체를 생성(한번만 사용할 경우)
                Member mem = new MemberSelect().GetSelectMember(members);

                mem.Print();
            }
            catch (Exception ex)
            {
                Console.WriteLine("[검색에러] " + ex.Message);
            }
        }

        public void UpdateMember()
        {
            try
            {
                Member mem = new MemberSelect().GetSelectMember(members);
                new MemberUpdate().UpdateAddr(mem);
                Console.WriteLine("주소가 변경되었습니다.");
            }
            catch (Exception ex)
            {
                Console.WriteLine("[수정에러] " + ex.Message);
            }

        }

        public void DeleteMember()
        {
            try
            {
                Member mem = new MemberSelect().GetSelectMember(members);
                new MemberDelete().DeleteMember(members, mem);
                Console.WriteLine("삭제 되었습니다.");
            }
            catch (Exception ex)
            {
                Console.WriteLine("[검색에러] " + ex.Message);
            }
        }

    }
}
