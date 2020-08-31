package woosongbit.sample;
import java.time.LocalDate;
import java.util.Date;

public class Drink 
{
	//맴버 변수
	private int number;
	private String name;
	private int price;
	private LocalDate date;
	
	private static int s_number;
	//생성자
	Drink(String name, int price)
	{
		this(name,price,LocalDate.now());
	}
	Drink(String name,int price,LocalDate date)
	{
		this.number=s_number;
		this.name=name;
		this.price=price;
		this.date=date;
		s_number+=10;
	}
	
	//getset 필요시 제작
	public String getName()
	{
		return name;
	}
	public int getPrice()
	{
		return price;
	}
	public void setPrice(int price)
	{
		if(price<=0)
			return;
		this.price=price;
	}
	//메서드
	public void Println()
	{
		System.out.println("[ 번호 ]"+number);
		System.out.println("[ 이름 ]"+name);
		System.out.println("[ 가격 ]"+price);
		System.out.println("[ 날짜 ]"+LocalDate.now());
	}
	
}
