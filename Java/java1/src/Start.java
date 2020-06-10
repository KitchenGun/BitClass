
public class Start 
{
	private static void exam1()
	{
		Student stu = new Student(10,"ȫ�浿",10,10,10);
		
		stu.Print();
		
		stu.SetJumsu(5, 10, 8);
		
		stu.Println();
	}
	
	
	private static void exam2()
	{
		Student[] base=new Student[2];
		
		base[0]=new Student(10,"ȫ�浿",10,10,10);
		base[1]=new Student(10,"�̱浿",9,10,6);
		
		base[0].Print();
		
		base[1].SetJumsu(10, 10, 10);
		
		base[1].Println();
		
		
		
	}
	public static void main(String args[])
	{
		exam2();
	}
}
