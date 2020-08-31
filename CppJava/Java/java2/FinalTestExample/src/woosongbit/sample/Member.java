package woosongbit.sample;
import java.time.LocalDate;

public class Member 
{
	private int number;
	private String name;
	private char gender;  
	private String phone; 
	private LocalDate date;
	
	private static int s_number=1000;
	
	//======================\
	Member(String name)
	{
		this(name,' ',"",LocalDate.now());
	}
	
	Member(String name,char gender,String phone,LocalDate date)
	{
		this.number=s_number;
		this.name=name;
		this.gender=gender;
		this.phone=phone;
		this.date=date;
		s_number++;		
	}
	//==============
	public String getName()
	{
		return name;
	}
	public void setPhone(String phone)
	{
		this.phone=phone;
	}
	
	public void Println()
	{
		System.out.println("[ 번호 ]"+number);
		System.out.println("[ 이름 ]"+name);
		System.out.println("[ 성별 ]"+gender);
		System.out.println("[ 전화 ]"+phone);
		System.out.println("[ 날짜 ]"+LocalDate.now());
	}
	
}
