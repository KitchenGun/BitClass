package WsuBitSample;//����� ������

import WsuBitSample1.Test1;

public class Start 
{
	public static void main(String[] args) 
	{
		Test.Foo();
		
		Test t1 = new Test();
		t1.Foo();//static �̷��� ������� ���ƶ�
		
		WsuBitSample1.Test1 t11= new WsuBitSample1.Test1();
		Test1 t12 = new Test1();
		t12.Foo();
	}
}
