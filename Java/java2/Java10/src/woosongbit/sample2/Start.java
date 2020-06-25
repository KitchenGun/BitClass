package woosongbit.sample2;

public class Start 
{
	private static void exam1()
	{
		// string 값 형식(자주 사용하는 방식)
		String s1 = "abc";
		String s2 = "abc";
		// string 참조형식
		String s3 = new String("abc");
		String s4 = new String("abc");
		//========================
		
		System.out.println(s1==s2);//==는 주소값 비교
		System.out.println(s3==s4);//다른 힙주소
		
		System.out.println(s1.equals(s2));
		System.out.println(s3.equals(s4));//equals는 값과 값을 비교한다.
		
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
