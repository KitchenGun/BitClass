import woosongbit.sample1.Input;
import woosongbit.sample1.StudentManager;;

public class Start 
{
	
		private StudentManager stu = new StudentManager();
		
		private String[] InputPaser() 
		{
			String msg = Input.InputString(">> ");
			return msg.split(" ");  //split : 문자열을 (" ")공백 쪼갠다.
		}
		
		private void Init() {
			System.out.println(" java 언어로 만든 맴버 관리 프로그램");
			System.out.println("==========================================================");
			System.out.println(" 사용법");
			System.out.println(" 입력 : insert 이름");
			System.out.println(" 검색 : select 이름");
			System.out.println(" 삭제 : delete 이름");
			System.out.println(" 수정 : update 이름 c언어점수 cpp언어점수");
			System.out.println(" 종료: exit");
			System.out.println("==========================================================\n");
			Input.InputString("엔터키를 누르세요");
		}
		
		
		//배열에 저장된 정보를 전체 출력
		public void Run() {		
			//실행부
			while(true) {
				String[] msg = InputPaser();
				if(msg[0].equals("insert")) 
				{			//insert 이름 전화번호 
					String name = msg[1];
					stu.Insert(name);				
				}
				else if(msg[0].equals("select"))
				{		//select 이름 
					String name = msg[1];
					stu.Select1(name);				
				}
				else if(msg[0].equals("delete")) 
				{		//delete
					String name = msg[1];
					stu.Delete1(name);				
				}
				else if(msg[0].equals("update"))
				{
					String name = msg[1];
					int c = Integer.parseInt(msg[2]);
					int cpp = Integer.parseInt(msg[3]);
					stu.Update1(name,c,cpp);
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
