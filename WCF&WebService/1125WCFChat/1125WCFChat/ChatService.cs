using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.ServiceModel;


namespace _1125WCFChat
{
    //델리게이트 정의
    public delegate void Chat(string idx, string msg, string type);

    class ChatService : IChat
    {
        //개인용 델리게이트
        private Chat MyChat;

        //클라이언트에 보낼 정보를 담고 있는 델리게이트
        IChatCallback callback = null;
        #region IChat 인터페이스 
        bool IChat.Join(string idx)
        {
            MyChat = new Chat(UserHandler);
            //2. 사용자에게 보내 줄 채널을 설정한다.
            callback = OperationContext.Current.GetCallbackChannel<IChatCallback>();

            //현재 접속자 정보를 모두에게 전달
            BroadcastMessage(idx, "", "UserEnter");
            return true;
        }

        void IChat.Leave(string idx)
        {
            BroadcastMessage(idx, "", "UserLeave");

            Chat d = null;
            MyChat -= d;
        }

        void IChat.Say(string idx, string msg)
        {
            BroadcastMessage(idx, msg, "Receive");
        }
        #endregion

        private void BroadcastMessage(string idx, string msg, string msgType)
        {
            //비동기로 UserHandler 함수 호출
            MyChat.BeginInvoke(idx, msg, msgType, new AsyncCallback(EndAsync), null);
        }
        //클라이언트에 메시지 보내기
        private void UserHandler(string idx, string msg, string msgType)
        {
            try
            {
                //클라이언트에게 보내기
                switch (msgType)
                {
                    //메시지 전송
                    case "Receive": callback.Receive(idx, msg); break;
                    //채팅 참여 알림
                    case "UserEnter": callback.UserEnter(idx); break;
                    //채팅 나감 알림
                    case "UserLeave": callback.UserLeave(idx); break;
                }
            }
            catch//에러가 발생했을 경우
            {
                Console.WriteLine("{0} 에러", idx);
            }
   
        }
        //비동기 결과 호출[기능은 없음]
        private void EndAsync(IAsyncResult ar)
        {
            Chat d = null;
            try
            {
                System.Runtime.Remoting.Messaging.AsyncResult asres = (System.Runtime.Remoting.Messaging.AsyncResult)ar;
                d = ((Chat)asres.AsyncDelegate);
                d.EndInvoke(ar);
            }
            catch
            {
            }
        }
    }
}
