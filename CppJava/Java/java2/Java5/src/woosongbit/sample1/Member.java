package woosongbit.sample1;
//회원정보를 담는 데이터 클래스
public class Member 
{
	//맴버 변수
	private int number;
	private String name;
	private String phone;
	private static int s_number=1;
	
	//생성자
	public Member(String name,String phone)
	{
		this.number=s_number++;//후치
		this.name=name;
		this.phone=phone;
	}
	//get set
	public String getName()
	{
		return name;
	}
	
	public void setPhone(String phone)
	{
		this.phone=phone;
	}
	//메서드
	public void Println()
	{
		System.out.println("번호"+number);
		System.out.println("번호"+name);
		System.out.println("번호"+phone);
	}

}
