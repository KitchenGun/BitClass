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
	int buycom = 0;//computer구매 개수
	int buytv = 0;//tv구매개수
	
	public void buy(Product t)//모든 제품을 구매할수있다.
	{
		money = money-t.getPrice();
		bounsPoint+=t.getBounsPoint();
		
		//t에 전달 제품이 무엇인지 확인하는 스크립트
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
//==사용클래스==================
public class Start 
{
	public static void main(String[] args)
	{
		Buyer b = new Buyer();
		
		Tv tv = new Tv(50,2);
		Computer com = new Computer(20,1);
		//Buyer가 컴퓨터를 구매한다.
		 b.buy(com);
		 //Buyer가 tv를 구매한다
		 b.buy(tv);
		 
	}
}
