package woosongbit.sample;

public class Student 
{
	//맴버
	private int number;
	private String name;
	private int c;
	private int cpp;
	private float average;

	private static int s_number=1000;
	
	//생성자
	public Student(String name)
	{
		number=s_number;
		this.name=name;
		this.c=0;
		this.cpp=0;
		this.average=0;
		
		s_number+=10;
	}
	
	//get&set
	public String getName()
	{
		return name;
	}
	
	//메서드
	public final void Println()
	{
		System.out.println("번호"+number);
		System.out.println("이름"+name);
		System.out.println("c언어"+c);
		System.out.println("cpp언어"+cpp);
		System.out.println("언어 평균"+average);
	}
	
	public void SetJumsu(int c ,int cpp)
	{
		this.c=c;
		this.cpp=cpp;
		this.average=(c+cpp)/2.0f;
	}

	
	
}
