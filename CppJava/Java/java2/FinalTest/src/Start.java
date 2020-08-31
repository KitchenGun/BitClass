import woosongbit.sample.Input;
import woosongbit.sample.StuManager;

public class Start 
{
private StuManager SM = new StuManager();
	
	private String[] InputPaser() 
	{
		String msg = Input.InputString(">> ");
		return msg.split(" ");  //split : 문자열을 (" ")공백 쪼갠다.
	}
	
	private void Init() {
		 System.out.println("-------------------------------------------------");
		 System.out.println(" 사용방법");
		 System.out.println(" 입력 : insert 이름 학과 학년"); 
		 System.out.println(" 검색 : select  학번");
		 System.out.println(" 삭제 : delete 학번");
		 System.out.println(" 수정 : update 학번 학년");  // 학번으로 검색하여 학년을 수정할 것 System.out.println(" 프로그램 종료 : exit"); 
		 System.out.println("-------------------------------------------------\n");
		Input.InputString("엔터키를 누르세요");
	}
	
	
	//배열에 저장된 정보를 전체 출력
	public void Run() {		
		//실행부
		while(true) {
			String[] msg = InputPaser();
			if(msg[0].equals("insert")) 
			{			//insert 이름 가격
				String name = msg[1];
				String subject = msg[2];
				int grade =Integer.parseInt(msg[3]);
				if(grade>=1&&grade<=4)
				{
					SM.Insert(name,subject,grade);	
				}
				else
				{
					System.out.println("잘못된 학년임 다시 입력하시오");
				}
			}
			else if(msg[0].equals("select"))
			{		//select 이름 
				int number = Integer.parseInt(msg[1]);
				SM.Select(number);				
			}
			else if(msg[0].equals("delete")) 
			{		//delete
				int number = Integer.parseInt(msg[1]);
				SM.Delete(number);				
			}
			else if(msg[0].equals("update"))
			{
				int number = Integer.parseInt(msg[1]);
				int grade = Integer.parseInt(msg[2]);
				if(grade>=1&&grade<=4)
				{
					SM.Update(number,grade);
				}
				else
				{
					System.out.println("잘못된 학년임 다시 입력하시오");
				}
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
