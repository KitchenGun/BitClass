package woosongbit.sample;
import java.time.LocalDate;


public class UniStudent 
{
	private int number;
	private String name;
	private String subject;
	private int grade;
	private LocalDate date;
	
	private static int s_number=1000;
	
	//==============================================================
	UniStudent(String name, String subject, int grade)
	{
		this.number=s_number;
		this.name = name;
		this.subject= subject;
		setGrade(grade);
		date=LocalDate.now();
		s_number+=10;
	}

	//==============================================================
	
	public String getName()
	{
		return name;
	}
	
	public void setGrade(int grade) 
	{
			this.grade=grade;	
	}
	
	public int getNumber()
	{
		return number;
	}
	
	//===============================================================
	public void Println()
	{
		System.out.println("[ ��ȣ ]"+number);
		System.out.println("[ �̸� ]"+name);
		System.out.println("[ �а� ]"+subject);
		System.out.println("[ �г� ]"+grade);
		System.out.println("[ ����� ]"+ date);
	}
	
}
