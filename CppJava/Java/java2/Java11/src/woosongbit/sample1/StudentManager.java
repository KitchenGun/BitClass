package woosongbit.sample1;

import java.util.ArrayList;
//��ü ���� Ŭ����
public class StudentManager 
{
	//���� ��ü
	@SuppressWarnings("rawtypes")
	private ArrayList arr;
	//������
	@SuppressWarnings("rawtypes")
	public StudentManager()
	{
		arr = new ArrayList();//���� ����
	}
	//�޼���-�ʱ�ȭ
	private int InputSize()
	{
		return Input.InputInteger("���尳��");
	}
	//�޼���-��ü ���
	private void PrintAll() 
	{//�̸��� ���
		for(int i=0; i< arr.size(); i++) {
			Student stu  = (Student)arr.get(i); //�ڽ� <= �θ� : �ٿ�ĳ����
			System.out.print(stu.getName() + ", ");
		}
		System.out.println("\n");
	}
	
	//�޼���-���
	@SuppressWarnings("unchecked")
	public void Insert(String name)
	{
		Student stu = new Student(name);
		if( arr.add(stu))
			PrintAll();
		else
			System.out.println("����");
	}
	
	//�˻��˰��� : value => idx
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
		
		//�˻��˰��� : value => Object
	private Student ValueToData(String value) //throws Exception 
	{
		for(int i=0; i<arr.size(); i++) 
		{
			Student stu = (Student)arr.get(i);
			if(stu.getName().equals(value))
				return stu;
		}
		return null;//���۷����� null�� �����
		//throw new Exception("����");
	}

	//�޼��� - �˻� idx
	public void Select(String name) 
	{
		int idx = ValueToIdx(name);
		if( idx == -1)
		{
			System.out.println("����");
			return;
		}
		
		Student stu = (Student)arr.get(idx);
		stu.Println();
	}
	
	//�޼��� - �˻� obj
		public void Select1(String name) 
		{
			Student stu = ValueToData(name);
			if( stu == null)
			{
				System.out.println("����");
				return;
			}
			
			stu.Println();
		}
	//�޼��� - ����
	public void Delete(String name)
	{
		int idx = ValueToIdx(name);
		if( idx == -1)
		{
			System.out.println("����");
			return;
		}
		arr.remove(idx);
		System.out.println("��������");
		PrintAll();
	}	
	//�޼��� - ����
	public void Delete1(String name)
	{
		Student stu = ValueToData(name);
		if( stu == null)
		{
			System.out.println("����");
			return;
		}
		arr.remove(stu);//���� ��ü ����
		System.out.println("��������");
		PrintAll();
	}		
	//�޼��� - ����
	public void Update(String name, int c,int cpp) 
	{		
		int idx = ValueToIdx(name);
		if( idx == -1)
		{
			System.out.println("����");
			return;
		}
			Student stu = (Student)arr.get(idx);
			stu.SetJumsu(c, cpp);
			PrintAll();
	}
 
	//�޼��� - ����
	public void Update1(String name, int c,int cpp) 
	{		
		Student stu = ValueToData(name);
		if( stu == null)
		{
			System.out.println("����");
			return;
		}
		stu.SetJumsu(c, cpp);
		PrintAll();
	}
	
	

	
}
