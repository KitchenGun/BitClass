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
	//오버라이드
	@Override//어트리부트 "부모의 메서드 재정의 하겠다. 컴파일러에게 알림"
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
	
	Product[] cart = new Product[10];//제품 10개 담을수 있는 배열
	int i = 0;
	
	
	public void buy(Product t)//모든 제품을 구매할수있다.
	{
		if(money<t.getPrice())
		{
			return;
		}
		money = money-t.getPrice();
		bounsPoint+=t.getBounsPoint();
		cart[i++]=t;					// 구매한 제품을 카트에 넣는다
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
				Computer c = (Computer)p;		//다운캐스팅
				c.Print();
			}
		}
	}

}
//==사용클래스==================
public class Start 
{
	public static void main(String[] args)
	{
		Buyer b = new Buyer();
		
		//Buyer가 제품을 구매한다.
		b.buy(new Computer(50, 2));
		b.buy(new Tv(50, 2));
		b.buy(new Computer(50, 2));
		b.buy(new Tv(50, 2));
		b.buy(new Computer(50, 2));
		b.buy(new Computer(50, 2));
		b.buy(new Audio(50, 2));
		b.buy(new Computer(50, 2));
		//출력
		b.PrintAll();
		System.out.println();
		b.PrintComputer();
	}
}
