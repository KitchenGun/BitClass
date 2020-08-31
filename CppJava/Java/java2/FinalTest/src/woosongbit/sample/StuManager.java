package woosongbit.sample;
import java.util.ArrayList;
import java.time.LocalDate;

public class StuManager
{
	private ArrayList<UniStudent> stulist;
	
	public StuManager()
	{
		stulist = new ArrayList<UniStudent>();	
	}
	
	//메서드 - 삽입
	
	public void Insert(String name,String subject,int grade)
	{
		UniStudent stu = new UniStudent(name,subject,grade);
		if(stulist.add(stu))
		{
			PrintAll();
		}
		else
		{
			System.out.println("실패");
		}
	}
	
	//검색알고리즘
	private UniStudent NumberToUniStudent(int num)  
	{
		for(UniStudent stu : stulist) {
			if(stu.getNumber()==num)	//int == int 
				return stu;		
		}
		return null;		
	}

	
	//메서드 - 검색 obj
	public void Select(int num) 
	{
		UniStudent stu = NumberToUniStudent(num);
		if( stu == null)
		{
			System.out.println("없다");
			return;
		}
		stu.Println();
	}
	//메서드 - 삭제
	public void Delete(int num)
	{
		UniStudent stu = NumberToUniStudent(num);
		if( stu == null)
		{
			System.out.println("없다");
			return;
		}
		stulist.remove(stu);//삭제 개체 전달
		System.out.println("삭제성공");
		PrintAll();
	}		
	
	//메서드 - 수정
	public void Update(int num, int grade) 
	{	
			UniStudent stu = NumberToUniStudent(num);
			if( stu == null)
			{
				System.out.println("없다");
				return;
			}
			stu.setGrade(grade);
			stu.Println();
			PrintAll();
	}
	//메서드 - 전체 출력
	private void PrintAll() 
	{
		for(UniStudent stu:stulist)
		{
			System.out.print(stu.getNumber() + ", ");
		}
		System.out.println("\n");
	}	
}