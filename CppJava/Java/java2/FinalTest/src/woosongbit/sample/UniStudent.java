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
		System.out.println("[ 번호 ]"+number);
		System.out.println("[ 이름 ]"+name);
		System.out.println("[ 학과 ]"+subject);
		System.out.println("[ 학년 ]"+grade);
		System.out.println("[ 등록일 ]"+ date);
	}
	
}
