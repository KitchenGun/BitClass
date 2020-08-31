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
	
	//�޼��� - ����
	public void Insert1(String name,int price)
	{
		Drink drink = new Drink(name,price);
		if(arr.add(drink))
		{
			PrintAll();
		}
		else
		{
			System.out.println("����");
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
			System.out.println("����");
		}
	}
	
	//�˻��˰��� : value => Object
	private Drink NameToDrink(String name)  
	{
		for(Drink drink : arr) {
			if(drink.getName().equals(name))	//String == String 
				return drink;		//�ּҳѾ....
		}
		return null;		
		//throw new Exception("����");
	}

	
	//�޼��� - �˻� obj
	public void Select(String name) 
	{
		Drink drink = NameToDrink(name);
		if( drink == null)
		{
			System.out.println("����");
			return;
		}
		drink.Println();
	}
	//�޼��� - ����
	public void Delete(String name)
	{
		Drink drink = NameToDrink(name);
		if( drink == null)
		{
			System.out.println("����");
			return;
		}
		arr.remove(drink);//���� ��ü ����
		System.out.println("��������");
		PrintAll();
	}		
	
	//�޼��� - ����
	public void Update(String name, int price) 
	{		
		Drink drink = NameToDrink(name);
		if( drink == null)
		{
			System.out.println("����");
			return;
		}
		drink.setPrice(price);
		PrintAll();
	}
	//�޼��� - ��ü ���
	private void PrintAll() 
	{//�̸��� ���
		/*for(int i=0; i< arr.size(); i++) {
			Drink drink  = arr.get(i); //�ڽ� <= �θ� : �ٿ�ĳ����
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
