package woosongbit.sample1;


//회원번호,이름 과 전화 번호 관리 프로그램
//1부터 점점 증가하는 회원 번호//static맴버 변수
//이름 전화번호는 사용자 입력
//기능:등록,검색(이름-key),삭제(이름-key 전화번호를 수정),전체 출력
public class Start 
{
	private MemberManager mem = new MemberManager();
	
	private String[] InputPaser() 
	{
		String msg = Input.InputString(">> ");
		return msg.split(" ");  //split : 문자열을 (" ")공백 쪼갠다.
	}
	
	private void Init() {
		System.out.println(" java 언어로 만든 맴버 관리 프로그램");
		System.out.println("==========================================================");
		System.out.println(" 사용법");
		System.out.println(" 입력: insert 이름 전화번호");
		System.out.println(" 검색: select 이름");
		System.out.println(" 삭제: delete 이름");
		System.out.println(" 삭제: update 이름 전화번호");
		System.out.println(" 종료: exit");
		System.out.println("==========================================================");
		
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
				String phone = msg[2];
				mem.Insert(name,  phone);				
			}
			else if(msg[0].equals("select"))
			{		//select 이름 
				String name = msg[1];
				mem.Select(name);				
			}
			else if(msg[0].equals("delete")) 
			{		//delete
				String name = msg[1];
				mem.Delete(name);				
			}
			else if(msg[0].equals("update"))
			{
				String name = msg[1];
				String newphone= msg[2];
				mem.Update(name,newphone);
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
