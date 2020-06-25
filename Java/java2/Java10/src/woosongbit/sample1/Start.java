package woosongbit.sample1;

public class Start 
{
	private static void exam1()
	{
		Date d1 = new Date(2020,6,25);
		Date d2 = new Date(2020,6,25);
		
		System.out.println(d1.hashCode());
		System.out.println(d2.hashCode());
		
		if(d1==d2)
		{//data 타입을 비교하면 주소값 비교다
			System.out.println("d1==d2 같다");
		}
		
		if(d1.equals(d2))//부모로 부터 물려받은 equlas 맴버 함수는 내부 연산으로 주소값을 비교한다 따라서 객체의 값을 비교하려면 재정의 해야한다
		{
			System.out.println("d1==d2 같다");
		}
	}
	
	private static void exam2()
	{
		Date d1 = new Date(2020,6,25);
		Date d2 = new Date(2020,6,25);
		
		System.out.println(d1);
		System.out.println(d2);//객체명으로 출력하면 묵시적으로 tostring 메서드를 호출한다.
		
		System.out.println(d1.toString());
		System.out.println(d2.toString());
	}
	//복제
	private static void exam3()
	{
		try
		{
		Date d1 = new Date(2020,6,25);
		Date d2 = (Date)d1.clone();// 복제
		Date d3 = (Date)d1;
		
		System.out.println(d1);
		System.out.println(d2);
		System.out.println(d3);
		
		System.out.println(d1.hashCode());
		System.out.println(d2.hashCode());
		System.out.println(d3.hashCode());
		}
		catch(Exception ex)
		{
			
		}
	}
	
	public static void main(String[] args) 
	{
		exam3();
	}

}
