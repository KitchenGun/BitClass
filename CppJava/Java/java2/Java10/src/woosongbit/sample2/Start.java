package woosongbit.sample2;

public class Start 
{
	private static void exam1()
	{
		// string �� ����(���� ����ϴ� ���)
		String s1 = "abc";
		String s2 = "abc";
		// string ��������
		String s3 = new String("abc");
		String s4 = new String("abc");
		//========================
		
		System.out.println(s1==s2);//==�� �ּҰ� ��
		System.out.println(s3==s4);//�ٸ� ���ּ�
		
		System.out.println(s1.equals(s2));
		System.out.println(s3.equals(s4));//equals�� ���� ���� ���Ѵ�.
		
		System.out.println(s1.hashCode());
		System.out.println(s2.hashCode());
		System.out.println(s3.hashCode());
		System.out.println(s4.hashCode());
	}
	
	public static void main(String[] args)
	{
		exam1();
	}

}
