package WsuBitSample;//지우면 에러남

import WsuBitSample1.Test1;

public class Start 
{
	public static void main(String[] args) 
	{
		Test.Foo();
		
		Test t1 = new Test();
		t1.Foo();//static 이렇게 사용하지 말아라
		
		WsuBitSample1.Test1 t11= new WsuBitSample1.Test1();
		Test1 t12 = new Test1();
		t12.Foo();
	}
}
