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
	
	//�޼��� - ����
	public void Insert1(String name)
	{
		Member mem = new Member(name);
		if(arr.add(mem))
		{
			PrintAll();
		}
		else
		{
			System.out.println("����");
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
			System.out.println("����");
		}
	}
	
	//�˻��˰��� : value => Object
	private Member NameToMem(String name)  
	{
		for(Member mem : arr) {
			if(mem.getName().equals(name))	//String == String 
				return mem;		//�ּҳѾ....
		}
		return null;		
		//throw new Exception("����");
	}

	
	//�޼��� - �˻� obj
	public void Select(String name) 
	{
		Member mem = NameToMem(name);
		if( mem == null)
		{
			System.out.println("����");
			return;
		}
		mem.Println();
	}
	//�޼��� - ����
	public void Delete(String name)
	{
		Member mem = NameToMem(name);
		if( mem == null)
		{
			System.out.println("����");
			return;
		}
		arr.remove(mem);//���� ��ü ����
		System.out.println("��������");
		PrintAll();
	}		
	
	//�޼��� - ����
	public void Update(String name, String phone) 
	{		
		Member mem = NameToMem(name);
		if( mem == null)
		{
			System.out.println("����");
			return;
		}
		mem.setPhone(phone);
		PrintAll();
	}
	//�޼��� - ��ü ���
	private void PrintAll() 
	{//�̸��� ���
		/*for(int i=0; i< arr.size(); i++) {
			Drink drink  = arr.get(i); //�ڽ� <= �θ� : �ٿ�ĳ����
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
