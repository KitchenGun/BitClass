
public class Student 
{
	private int number =10;//������ 10
	static int sample=10;
	
	//static �ʱ�ȭ ��
	static
	{//static �ɹ��� �ʱ�ȭ �ϴµ� ������ ������ ����ؼ� �ʱ�ȭ�� �ؾߵ� ���
		sample =10*20-10*200;
	}
	//�ν��Ͻ� �ʱ�ȭ ��
	{//�ν��Ͻ��� ȣ�� �ɶ� ���� ����ǰ� �����ڰ� �����====�׳� �����ڿ� �������
		
	}
	//������
	public Student()
	{
		this(0);
	}
	public Student(int number)
	{
		this.number=number;
	}
}
