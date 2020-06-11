
public class Student 
{
	private int number =10;//생성시 10
	static int sample=10;
	
	//static 초기화 블럭
	static
	{//static 맴버를 초기화 하는데 복잡한 연산을 사용해서 초기화를 해야될 경우
		sample =10*20-10*200;
	}
	//인스턴스 초기화 블럭
	{//인스턴스가 호출 될때 마다 실행되고 생성자가 실행됨====그냥 생성자에 넣으면됨
		
	}
	//생성자
	public Student()
	{
		this(0);
	}
	public Student(int number)
	{
		this.number=number;
	}
}
