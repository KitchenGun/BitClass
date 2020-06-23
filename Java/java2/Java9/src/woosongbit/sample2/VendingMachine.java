package woosongbit.sample2;

/*
 * 음료수 자판기(VendingMachine)
 *   - 맴버변수
 *     음료수들  : Drink[] d = new Drink[3];
 *     투입금액  : int money = 0;     
 *   - 맴버함수
 *     돈을 넣음     : void InputMoney(int money);
 *     제품 선택() : Drink SelectDrink(String name);
 *     잔액 반환() : int GetMoney();
 * ------------------------------------------------------------ 
 * [1] 콜라(1000원/5개)   [2] 사이다(900원/3개)  [3] 커피(500원/2개)   
 * ------------------------------------------------------------
 * 투입금액 >> 0원  
 * -------------------------------------------------------------
 * [1] 돈을 넣음      [2] 제품 선택      [3] 잔액 반환
 * -------------------------------------------------------------
 */


public class VendingMachine 
{
	//맴버 변수
	private Drink[] drink = new Drink[3];
	private int money =0;
	//생성자
	public VendingMachine() {
		//제품을 미리 등록
		drink[0] = new Drink("콜라", 1000, 5);
		drink[1] = new Drink("사이다", 900, 3);
		drink[2] = new Drink("커피", 500, 2);
	}

	//getset
	
	//메서드
	public void InputMoney(int money) throws Exception
	{
		if(money<=0)
			throw new Exception("잘못된 금액이 들어옴");
		this.money+=money;
	}
	
	public Drink SelectDrink(String name) throws Exception
	{
		for(Drink d:drink)//foreach 배열전체 순환시 사용하는 문장
		{
			if(d.getName().equals(name))
			{
				d.Buy();//throw new exception
				//잔액 감소
				if(this.money<d.getPrice())
				{
					throw new Exception("잔액부족");
				}
				this.money-=d.getPrice();
				return d;
			}
		}
		throw new Exception("제품이름 잘못 선택함");
	}
	
	public int GetMoney() throws Exception
	 {
		if( money == 0)
			throw new Exception("반환금액이 없습니다.");

		int temp = this.money;
		money = 0;
		return temp;
	}

	public void View() {
		System.out.println("------------------------------------------------------------");
		for(int i=0; i< drink.length; i++) 
		{
			System.out.printf("[%d] ",i);
			drink[i].Print();
			System.out.printf("\t");
		}
		System.out.println("");
		System.out.println("------------------------------------------------------------"); 
		System.out.printf("투입금액 >>  %d원\n", money);  
		System.out.println("------------------------------------------------------------"); 
	}

	
}
