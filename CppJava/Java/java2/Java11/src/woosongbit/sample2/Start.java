package woosongbit.sample2;

import java.util.ArrayList;

public class Start 
{
	private ArrayList arr = new ArrayList();
	
	public void Info()
	{
		System.out.println("ũ��: "+ arr.size());
	}
	
	//���� : boolean add(Object o)
	public void Insert() 
	{
		for(int i=0; i<10; i++) 
		{
			if(arr.add(i+1) == false)//1 ~ 10 ==> boxing object o = int;
				System.out.println("�������");
		}
	}

	//��ü���
	public void PrintAll()
	{
		for(int i = 0;i<arr.size();i++)
		{
			int value = (int)arr.get(i);//unboxing �� �ٿ��ɽ���
			System.out.print(value + ", ");
		}
		System.out.println();
	}
	//�˻� �˰���
	//value => idx   
	private int ValueToIdx(int value)
	{
		for(int i = 0;i<arr.size();i++)
		{
			int data = (int)arr.get(i);
			if(data==value)
			{
				return i;
			}
		}
		return -1;
	}
	//value => object
	private int ValueToData(int value) throws Exception
	{
		for(int i = 0;i<arr.size();i++)
		{
			int data = (int)arr.get(i);
			if(data==value)
			{
				return data;
			}
		}
		throw new Exception("����");
	}
	//�˻�
	public void Select()
	{
		int value = 10;
		int idx = ValueToIdx(value);
		if(idx==-1)
		{
			System.out.println("����");
			return;
		}
		System.out.printf("%d ��ġ�� %d����  ã�Ҵ� \n",idx,arr.get(idx));
	}
	//����
	public void Update()
	{
		int value = 10;
		int idx = ValueToIdx(value);
		if(idx==-1)
		{
			System.out.println("����");
			return;
		}
		//int data = (int)arr.get(idx);
		//data = 20;
		arr.set(idx, 20);
		System.out.println("�����Ϸ�");
		
	}
	//����
	public void Delete()
	{
		int value = 5;
		int idx = ValueToIdx(value);
		if(idx==-1)
		{
			System.out.println("����");
			return;
		}
		arr.remove(idx);//�ش� �ε����� ������ ���� �ڵ����� �������� ���ĵ� ũ�⵵ �پ��
		System.out.println("������");
	}
	
	public static void main(String[] args)
	{
		Start s = new Start();
		s.Info();
		s.Insert();
		s.PrintAll();
		s.Select();
		s.Update();
		s.PrintAll();
		s.Delete();
		s.Info();
		s.PrintAll();
	}
}
