package woosongbit.sample1;

class Product
{
	int price;
	int bounsPoint;
	
	public Product(int price,int bounsPoint)
	{
		this.price=price;
		this.bounsPoint=bounsPoint;
	}
	public int getPrice()
	{
		return price;
	}
	public int getBounsPoint()
	{
		return bounsPoint;
	}
}

class Tv extends Product
{
	public Tv(int price,int bounsPoint)
	{
		super(price,bounsPoint);
	}
}

class Computer extends Product
{
	public Computer(int price,int bounsPoint)
	{
		super(price,bounsPoint);
	}
}

class Audio extends Product
{
	public Audio(int price,int bounsPoint)
	{
		super(price,bounsPoint);
	}
}

class Buyer
{
	int money=10000;
	int bounsPoint = 0;
	int buycom = 0;//computer���� ����
	int buytv = 0;//tv���Ű���
	
	public void buy(Product t)//��� ��ǰ�� �����Ҽ��ִ�.
	{
		money = money-t.getPrice();
		bounsPoint+=t.getBounsPoint();
		
		//t�� ���� ��ǰ�� �������� Ȯ���ϴ� ��ũ��Ʈ
		if(t instanceof Tv)
		{
			buytv++;
		}
		else if(t instanceof Computer)
		{
			buycom++;
		}
	}
}
//==���Ŭ����==================
public class Start 
{
	public static void main(String[] args)
	{
		Buyer b = new Buyer();
		
		Tv tv = new Tv(50,2);
		Computer com = new Computer(20,1);
		//Buyer�� ��ǻ�͸� �����Ѵ�.
		 b.buy(com);
		 //Buyer�� tv�� �����Ѵ�
		 b.buy(tv);
		 
	}
}
