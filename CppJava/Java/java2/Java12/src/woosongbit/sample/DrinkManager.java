package woosongbit.sample;
import java.time.LocalDate;
import java.util.ArrayList;

public class DrinkManager 
{
	private ArrayList<Drink> arr;
	
	public DrinkManager()
	{
		arr = new ArrayList<Drink>();	
	}
	
	//메서드 - 삽입
	public void Insert1(String name,int price)
	{
		Drink drink = new Drink(name,price);
		if(arr.add(drink))
		{
			PrintAll();
		}
		else
		{
			System.out.println("실패");
		}
	}
	
	public void Insert2(String name,int price,int year,int month,int day)
	{
		Drink drink = new Drink(name,price,LocalDate.of(year, month, day));
		if(arr.add(drink))
		{
			PrintAll();
		}
		else
		{
			System.out.println("실패");
		}
	}
	
	//검색알고리즘 : value => Object
	private Drink NameToDrink(String name)  
	{
		for(Drink drink : arr) {
			if(drink.getName().equals(name))	//String == String 
				return drink;		//주소넘어감....
		}
		return null;		
		//throw new Exception("없다");
	}

	
	//메서드 - 검색 obj
	public void Select(String name) 
	{
		Drink drink = NameToDrink(name);
		if( drink == null)
		{
			System.out.println("없다");
			return;
		}
		drink.Println();
	}
	//메서드 - 삭제
	public void Delete(String name)
	{
		Drink drink = NameToDrink(name);
		if( drink == null)
		{
			System.out.println("없다");
			return;
		}
		arr.remove(drink);//삭제 개체 전달
		System.out.println("삭제성공");
		PrintAll();
	}		
	
	//메서드 - 수정
	public void Update(String name, int price) 
	{		
		Drink drink = NameToDrink(name);
		if( drink == null)
		{
			System.out.println("없다");
			return;
		}
		drink.setPrice(price);
		PrintAll();
	}
	//메서드 - 전체 출력
	private void PrintAll() 
	{//이름만 출력
		/*for(int i=0; i< arr.size(); i++) {
			Drink drink  = arr.get(i); //자식 <= 부모 : 다운캐스팅
			System.out.print(drink.getName() + ", ");
		}
		System.out.println("\n");
		*/
		for(Drink drink:arr)
		{
			System.out.print(drink.getName() + ", ");
		}
		System.out.println("\n");
	}	
}
