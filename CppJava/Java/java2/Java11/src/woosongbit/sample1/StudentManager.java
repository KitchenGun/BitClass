package woosongbit.sample1;

import java.util.ArrayList;
//전체 관리 클래스
public class StudentManager 
{
	//저장 객체
	@SuppressWarnings("rawtypes")
	private ArrayList arr;
	//생성자
	@SuppressWarnings("rawtypes")
	public StudentManager()
	{
		arr = new ArrayList();//갯수 전달
	}
	//메서드-초기화
	private int InputSize()
	{
		return Input.InputInteger("저장개수");
	}
	//메서드-전체 출력
	private void PrintAll() 
	{//이름만 출력
		for(int i=0; i< arr.size(); i++) {
			Student stu  = (Student)arr.get(i); //자식 <= 부모 : 다운캐스팅
			System.out.print(stu.getName() + ", ");
		}
		System.out.println("\n");
	}
	
	//메서드-등록
	@SuppressWarnings("unchecked")
	public void Insert(String name)
	{
		Student stu = new Student(name);
		if( arr.add(stu))
			PrintAll();
		else
			System.out.println("실패");
	}
	
	//검색알고리즘 : value => idx
	private int ValueToIdx(String value) 
	{
		for(int i=0; i<arr.size(); i++) 
		{
			Student stu = (Student)arr.get(i);
			if(stu.getName().equals(value))
				return i;
		}
		return -1;
	}
		
		//검색알고리즘 : value => Object
	private Student ValueToData(String value) //throws Exception 
	{
		for(int i=0; i<arr.size(); i++) 
		{
			Student stu = (Student)arr.get(i);
			if(stu.getName().equals(value))
				return stu;
		}
		return null;//레퍼런스는 null을 쓰면됨
		//throw new Exception("없다");
	}

	//메서드 - 검색 idx
	public void Select(String name) 
	{
		int idx = ValueToIdx(name);
		if( idx == -1)
		{
			System.out.println("없다");
			return;
		}
		
		Student stu = (Student)arr.get(idx);
		stu.Println();
	}
	
	//메서드 - 검색 obj
		public void Select1(String name) 
		{
			Student stu = ValueToData(name);
			if( stu == null)
			{
				System.out.println("없다");
				return;
			}
			
			stu.Println();
		}
	//메서드 - 삭제
	public void Delete(String name)
	{
		int idx = ValueToIdx(name);
		if( idx == -1)
		{
			System.out.println("없다");
			return;
		}
		arr.remove(idx);
		System.out.println("삭제성공");
		PrintAll();
	}	
	//메서드 - 삭제
	public void Delete1(String name)
	{
		Student stu = ValueToData(name);
		if( stu == null)
		{
			System.out.println("없다");
			return;
		}
		arr.remove(stu);//삭제 개체 전달
		System.out.println("삭제성공");
		PrintAll();
	}		
	//메서드 - 수정
	public void Update(String name, int c,int cpp) 
	{		
		int idx = ValueToIdx(name);
		if( idx == -1)
		{
			System.out.println("없다");
			return;
		}
			Student stu = (Student)arr.get(idx);
			stu.SetJumsu(c, cpp);
			PrintAll();
	}
 
	//메서드 - 수정
	public void Update1(String name, int c,int cpp) 
	{		
		Student stu = ValueToData(name);
		if( stu == null)
		{
			System.out.println("없다");
			return;
		}
		stu.SetJumsu(c, cpp);
		PrintAll();
	}
	
	

	
}
