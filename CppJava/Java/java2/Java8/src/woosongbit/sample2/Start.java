package woosongbit.sample2;

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

	public void Print()
	{
		System.out.printf("[price] %d$, [point] %d", price,bounsPoint);
	}
}

class Tv extends Product
{
	public Tv(int price,int bounsPoint)
	{
		super(price,bounsPoint);
	}
	//�������̵�
	@Override//��Ʈ����Ʈ "�θ��� �޼��� ������ �ϰڴ�. �����Ϸ����� �˸�"
	public void Print()
	{
		System.out.printf("**TV**");
		super.Print();
		System.out.println();
	}
}

class Computer extends Product
{
	public Computer(int price,int bounsPoint)
	{
		super(price,bounsPoint);
	}
	public void Print()
	{
		System.out.printf("**Computer**");
		super.Print();
		System.out.println();
	}
}

class Audio extends Product
{
	public Audio(int price,int bounsPoint)
	{
		super(price,bounsPoint);
	}
	public void Print()
	{
		System.out.printf("**Audio**");
		super.Print();
		System.out.println();
	}
}

class Buyer
{
	int money=10000;
	int bounsPoint = 0;
	
	Product[] cart = new Product[10];//��ǰ 10�� ������ �ִ� �迭
	int i = 0;
	
	
	public void buy(Product t)//��� ��ǰ�� �����Ҽ��ִ�.
	{
		if(money<t.getPrice())
		{
			return;
		}
		money = money-t.getPrice();
		bounsPoint+=t.getBounsPoint();
		cart[i++]=t;					// ������ ��ǰ�� īƮ�� �ִ´�
	}
	
	public void PrintAll()
	{
		for(int j =0 ;j<i;j++)
		{
			Product p = cart[j];
			//===================
			p.Print();
		}
	}
	public void PrintComputer() 
	{
		for(int j=0; j <i; j++) {
			Product p = cart[j];
			//===============================
			if(p instanceof Computer)		{
				Computer c = (Computer)p;		//�ٿ�ĳ����
				c.Print();
			}
		}
	}

}
//==���Ŭ����==================
public class Start 
{
	public static void main(String[] args)
	{
		Buyer b = new Buyer();
		
		//Buyer�� ��ǰ�� �����Ѵ�.
		b.buy(new Computer(50, 2));
		b.buy(new Tv(50, 2));
		b.buy(new Computer(50, 2));
		b.buy(new Tv(50, 2));
		b.buy(new Computer(50, 2));
		b.buy(new Computer(50, 2));
		b.buy(new Audio(50, 2));
		b.buy(new Computer(50, 2));
		//���
		b.PrintAll();
		System.out.println();
		b.PrintComputer();
	}
}
