package woosongbit.sample2;

public class Drink 
{
	//�ɹ� ����
	private String name;
	private int price;
	private int count;
	//������
	Drink(String name,int price,int count)
	{
		this.name=name;
		this.price=price;
		this.count=count;
	}
	//getset �ʿ�� ����
	public String getName()
	{
		return name;
	}
	public int getPrice()
	{
		return price;
	}
	//�޼���
	public void Print()
	{
		System.out.printf("%s (%d��/%d��)",name,price,count);
	}
	
	public void Buy() throws Exception 
	{
		if(count==0)
			throw new Exception("��� �����ϴ�.");
		count--;
	}
}
