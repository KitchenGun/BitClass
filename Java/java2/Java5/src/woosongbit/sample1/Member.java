package woosongbit.sample1;
//ȸ�������� ��� ������ Ŭ����
public class Member 
{
	//�ɹ� ����
	private int number;
	private String name;
	private String phone;
	private static int s_number=1;
	
	//������
	public Member(String name,String phone)
	{
		this.number=s_number++;//��ġ
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
	//�޼���
	public void Println()
	{
		System.out.println("��ȣ"+number);
		System.out.println("��ȣ"+name);
		System.out.println("��ȣ"+phone);
	}

}
