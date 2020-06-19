import woosongbit.sample.*;

public class Start 
{
	
		private AccountManager acc = new AccountManager();
		
		private String[] InputPaser() 
		{
			String msg = Input.InputString(">> ");
			return msg.split(" ");  //split : 문자열을 (" ")공백 쪼갠다.
		}
		
		private void Init() 
		{
			System.out.println("-------------------------------------------------");
			System.out.println(" Java 언어로 만든 계좌 관리 프로그램");
			System.out.println("-------------------------------------------------");
			System.out.println(" 사용방법");
			System.out.println(" 입력 : insert1 이름");
			System.out.println(" 입력 : insert2 이름 입금액 개설일자");
			System.out.println(" 검색 : select  계좌번호");
			System.out.println(" 삭제 : delete 계좌번호");
			System.out.println(" 수정 : updateinput 계좌번호 입금액");
			System.out.println(" 수정 :  계좌번호 출금액");
			System.out.println(" 프로그램 종료 : exit");
			System.out.println("-------------------------------------------------\n");
			Input.InputString("엔터키를 누르세요");
		}
		
		
		//배열에 저장된 정보를 전체 출력
		public void Run() {		
			//실행부
			while(true) {
				String[] msg = InputPaser();
				if(msg[0].equals("insert1")) 
				{			
					String name = msg[1];
					acc.Insert(name);				
				}
				else if(msg[0].equals("insert2")) 
				{			
					String name = msg[1];
					int balance = Integer.parseInt(msg[2]);
					String date = msg[3];
					acc.Insert(name,balance,date);				
				}
				else if(msg[0].equals("select"))
				{		 
					int accnum = Integer.parseInt(msg[1]);
					acc.Select(accnum);				
				}
				else if(msg[0].equals("delete")) 
				{		
					int accnum = Integer.parseInt(msg[1]);
					acc.Delete(accnum);				
				}
				else if(msg[0].equals("updateinput"))
				{
					int accnum = Integer.parseInt(msg[1]);
					int inputMoney = Integer.parseInt(msg[2]);
					acc.UpdateInput(accnum, inputMoney);
				}
				else if(msg[0].equals("updateoutput"))
				{
					int accnum = Integer.parseInt(msg[1]);
					int outputMoney = Integer.parseInt(msg[2]);
					acc.UpdateOutput(accnum, outputMoney);
				}
				else if(msg[0].equals("exit"))
					break;
			}
		}
		
		
		public static void main(String[] args)
		{
			Start s= new Start();
			s.Init();
			s.Run();
			
		}
}
