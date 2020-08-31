package woosongbit.sample;
import java.time.LocalDate;
import java.util.ArrayList;

public class MemberManager
{
	private ArrayList<Member> arr;
	
	public MemberManager()
	{
		arr = new ArrayList<Member>();	
	}
	
	//메서드 - 삽입
	public void Insert1(String name)
	{
		Member mem = new Member(name);
		if(arr.add(mem))
		{
			PrintAll();
		}
		else
		{
			System.out.println("실패");
		}
	}
	
	public void Insert2(String name,char gender,String phone ,int year,int month,int day)
	{
		Member mem = new Member(name,gender,phone,LocalDate.of(year, month, day));
		if(arr.add(mem))
		{
			PrintAll();
		}
		else
		{
			System.out.println("실패");
		}
	}
	
	//검색알고리즘 : value => Object
	private Member NameToMem(String name)  
	{
		for(Member mem : arr) {
			if(mem.getName().equals(name))	//String == String 
				return mem;		//주소넘어감....
		}
		return null;		
		//throw new Exception("없다");
	}

	
	//메서드 - 검색 obj
	public void Select(String name) 
	{
		Member mem = NameToMem(name);
		if( mem == null)
		{
			System.out.println("없다");
			return;
		}
		mem.Println();
	}
	//메서드 - 삭제
	public void Delete(String name)
	{
		Member mem = NameToMem(name);
		if( mem == null)
		{
			System.out.println("없다");
			return;
		}
		arr.remove(mem);//삭제 개체 전달
		System.out.println("삭제성공");
		PrintAll();
	}		
	
	//메서드 - 수정
	public void Update(String name, String phone) 
	{		
		Member mem = NameToMem(name);
		if( mem == null)
		{
			System.out.println("없다");
			return;
		}
		mem.setPhone(phone);
		PrintAll();
	}
	//메서드 - 전체 출력
	private void PrintAll() 
	{//이름만 출력
		/*for(int i=0; i< arr.size(); i++) {
			Drink drink  = arr.get(i); //자식 <= 부모 : 다운캐스팅
			System.out.print(drink.getName() + ", ");
		}
		System.out.println("\n");
		*/
		for(Member mem:arr)
		{
			System.out.print(mem.getName() + ", ");
		}
		System.out.println("\n");
	}	
}
