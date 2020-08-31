package woosongbit.sample1;

public class Start
{
	//�������� ���� �帧
	public static void exam1()
	{
		System.out.println("������ ���� ����");
		float result = 2.0f/10;
		System.out.println("�����"+result);
	}
	
	
	//���� �߻� ���� �帧-- ���α׷��� ������ �״´�
	public static void exam2()
	{
		System.out.println("������ ���� ����");
		float result = 0/0;
		System.out.println("�����"+result);
	}
	
	//���� �߻� ���� �帧-- ���α׷��� ������ �״´�
		public static void exam3()
		{
			try
			{
				System.out.println("������ ���� ����");
				float result = 0/0;
				System.out.println("�����"+result);
			}
			catch(ArithmeticException a)
			{
				System.out.println("���� "+a.getMessage());
			}
		}
		
		//���� �߻� ���� �帧-- ��ø���� catch�� �ʿ��ϴ�
		//��� ���� Ŭ������ �θ�� exceptionŬ�����̴�.
		public static void exam4()
		{
			try
			{
				System.out.println("�迭 ���� ����");
				int[] arr = new int[2];
				arr[2]=10;//ArrayIndexOutOfBoundsException ���� ����
				System.out.println();
				float result = 0/0;
				System.out.println("�����"+result);
			}
			catch(ArithmeticException a)
			{
				System.out.println("���� "+a.getMessage());
			}
			catch(ArrayIndexOutOfBoundsException e)
			{
				System.out.println("���� "+e.getMessage());
			}
			catch(Exception e)
			{
				System.out.println("���⼭ ��� ���ܸ� �������ִ�. ");
			}
		}
		
		//finally
		//������ ������ �Ǵ� ����
		public static void exam5() {
			try 
			{
				System.out.println("1");
				System.out.println(0/0);
				System.out.println("2");
				return;
			}
			catch(Exception ex) 
			{
				System.out.println("catch");
			}
			finally {
				System.out.println("finally");
			}
			System.out.println("try catch outside");
		}

		//���ܸ� �߻���Ű�� �޼��� �����
		//���� ���� try catch�� ���ܷ� �������ִ�. ���ܸ� ���� ȣ���� �Լ����� �����Ҽ��ִ�. �̸� ���ܸ� �߻���Ű�� �޼����� �Ѵ�
		
		public static void exam6sample(int value) throws Exception
		{
			if(value<0)//value�� ������� ����
				throw new Exception("������ ���޵Ǿ����ϴ�.");
		}
		
		public static void exam6()
		{
			try
			{
				
			exam6sample(-1);
			}
			catch(Exception ex)
			{
				System.out.println("error"+ex.getMessage());
			}
		}
		
		
	public static void main(String[] args)
	{
		exam6();
	}

}
