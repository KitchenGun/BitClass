package woosongbit.sample;
import java.time.LocalDate;
import java.util.Date;

public class Drink 
{
	//�ɹ� ����
	private int number;
	private String name;
	private int price;
	private LocalDate date;
	
	private static int s_number;
	//������
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
	
	//getset �ʿ�� ����
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
	//�޼���
	public void Println()
	{
		System.out.println("[ ��ȣ ]"+number);
		System.out.println("[ �̸� ]"+name);
		System.out.println("[ ���� ]"+price);
		System.out.println("[ ��¥ ]"+LocalDate.now());
	}
	
}
