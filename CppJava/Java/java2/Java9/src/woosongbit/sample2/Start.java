package woosongbit.sample2;

//자판기
/*맴버 변수
 * 음료수들class Drink[]
 * 투입 금액int
 * 맴버함수
 * 돈 넣는 기능InputMoney(int money)
 * 제품 선택SelectDrink(String name)
 * 반환GetMoney()
 * ===================================
 * [1]콜라(1000/5) [2]사이다(900/3) [3]커피(500/2) 
 * ----------------------------------------
 * 투입금액>>0원
 * ------------------------------------------
 * [1]돈을 넣음 [2]제품을 선택 [3]잔액 반환
 * ------------------------------------------
 *
 */


public class Start 
{
	private MachineManager mm = new MachineManager();
	
	private String[] InputPaser() 
	{
		String msg = Input.InputString(">> ");
		return msg.split(" ");  //split : 문자열을 (" ")공백 쪼갠다.
	}
	
	private void Init() 
	{
		System.out.println("-------------------------------------------------");
		System.out.println(" Java 언어로 만든 자판기 관리 프로그램");
		System.out.println("-------------------------------------------------");
		System.out.println(" 사용방법");
		System.out.println(" 동전투입 : input 투입금액");
		System.out.println(" 제품선택 : select 제품명");
		System.out.println(" 잔액반환 : getmoney");
		System.out.println(" 프로그램 종료 : exit");
		System.out.println("-------------------------------------------------\n");
		
		Input.InputString("엔터키를 누르세요");
	}
	
	
	//배열에 저장된 정보를 전체 출력
	public void Run() {		
		//실행부
		while(true) {
			mm.View();
			String[] msg = InputPaser();
			if(msg[0].equals("input")) {			//insert 이름 
				int money = Integer.parseInt(msg[1]);				
				mm.InputMoney(money);				
			}
			else if(msg[0].equals("select")) {			//insert 이름 
				String name = msg[1];				
				mm.SelectProduct(name);				
			}
			else if(msg[0].equals("getmoney")) {		//select 이름 			
				mm.GetMoney();				
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
