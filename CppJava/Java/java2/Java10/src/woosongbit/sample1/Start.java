package woosongbit.sample1;

public class Start 
{
	private static void exam1()
	{
		Date d1 = new Date(2020,6,25);
		Date d2 = new Date(2020,6,25);
		
		System.out.println(d1.hashCode());
		System.out.println(d2.hashCode());
		
		if(d1==d2)
		{//data Ÿ���� ���ϸ� �ּҰ� �񱳴�
			System.out.println("d1==d2 ����");
		}
		
		if(d1.equals(d2))//�θ�� ���� �������� equlas �ɹ� �Լ��� ���� �������� �ּҰ��� ���Ѵ� ���� ��ü�� ���� ���Ϸ��� ������ �ؾ��Ѵ�
		{
			System.out.println("d1==d2 ����");
		}
	}
	
	private static void exam2()
	{
		Date d1 = new Date(2020,6,25);
		Date d2 = new Date(2020,6,25);
		
		System.out.println(d1);
		System.out.println(d2);//��ü������ ����ϸ� ���������� tostring �޼��带 ȣ���Ѵ�.
		
		System.out.println(d1.toString());
		System.out.println(d2.toString());
	}
	//����
	private static void exam3()
	{
		try
		{
		Date d1 = new Date(2020,6,25);
		Date d2 = (Date)d1.clone();// ����
		Date d3 = (Date)d1;
		
		System.out.println(d1);
		System.out.println(d2);
		System.out.println(d3);
		
		System.out.println(d1.hashCode());
		System.out.println(d2.hashCode());
		System.out.println(d3.hashCode());
		}
		catch(Exception ex)
		{
			
		}
	}
	
	public static void main(String[] args) 
	{
		exam3();
	}

}
