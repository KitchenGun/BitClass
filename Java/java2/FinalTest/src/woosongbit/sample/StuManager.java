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
	
	//�޼��� - ����
	
	public void Insert(String name,String subject,int grade)
	{
		UniStudent stu = new UniStudent(name,subject,grade);
		if(stulist.add(stu))
		{
			PrintAll();
		}
		else
		{
			System.out.println("����");
		}
	}
	
	//�˻��˰���
	private UniStudent NumberToUniStudent(int num)  
	{
		for(UniStudent stu : stulist) {
			if(stu.getNumber()==num)	//int == int 
				return stu;		
		}
		return null;		
	}

	
	//�޼��� - �˻� obj
	public void Select(int num) 
	{
		UniStudent stu = NumberToUniStudent(num);
		if( stu == null)
		{
			System.out.println("����");
			return;
		}
		stu.Println();
	}
	//�޼��� - ����
	public void Delete(int num)
	{
		UniStudent stu = NumberToUniStudent(num);
		if( stu == null)
		{
			System.out.println("����");
			return;
		}
		stulist.remove(stu);//���� ��ü ����
		System.out.println("��������");
		PrintAll();
	}		
	
	//�޼��� - ����
	public void Update(int num, int grade) 
	{	
			UniStudent stu = NumberToUniStudent(num);
			if( stu == null)
			{
				System.out.println("����");
				return;
			}
			stu.setGrade(grade);
			stu.Println();
			PrintAll();
	}
	//�޼��� - ��ü ���
	private void PrintAll() 
	{
		for(UniStudent stu:stulist)
		{
			System.out.print(stu.getNumber() + ", ");
		}
		System.out.println("\n");
	}	
}