package woosongbit.sample2;

import java.util.ArrayList;

public class Start 
{
	private ArrayList arr = new ArrayList();
	
	public void Info()
	{
		System.out.println("크기: "+ arr.size());
	}
	
	//저장 : boolean add(Object o)
	public void Insert() 
	{
		for(int i=0; i<10; i++) 
		{
			if(arr.add(i+1) == false)//1 ~ 10 ==> boxing object o = int;
				System.out.println("저장오류");
		}
	}

	//전체출력
	public void PrintAll()
	{
		for(int i = 0;i<arr.size();i++)
		{
			int value = (int)arr.get(i);//unboxing 과 다운케스팅
			System.out.print(value + ", ");
		}
		System.out.println();
	}
	//검색 알고리즘
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
		throw new Exception("없다");
	}
	//검색
	public void Select()
	{
		int value = 10;
		int idx = ValueToIdx(value);
		if(idx==-1)
		{
			System.out.println("없다");
			return;
		}
		System.out.printf("%d 위치에 %d값을  찾았다 \n",idx,arr.get(idx));
	}
	//수정
	public void Update()
	{
		int value = 10;
		int idx = ValueToIdx(value);
		if(idx==-1)
		{
			System.out.println("없다");
			return;
		}
		//int data = (int)arr.get(idx);
		//data = 20;
		arr.set(idx, 20);
		System.out.println("수정완료");
		
	}
	//삭제
	public void Delete()
	{
		int value = 5;
		int idx = ValueToIdx(value);
		if(idx==-1)
		{
			System.out.println("없다");
			return;
		}
		arr.remove(idx);//해당 인덱스의 데이터 삭제 자동으로 땡겨져서 정렬됨 크기도 줄어듬
		System.out.println("삭제됨");
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
