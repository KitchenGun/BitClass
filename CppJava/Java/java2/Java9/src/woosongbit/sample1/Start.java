package woosongbit.sample1;

public class Start
{
	//정상적인 문장 흐름
	public static void exam1()
	{
		System.out.println("나눗셈 연산 수행");
		float result = 2.0f/10;
		System.out.println("결과값"+result);
	}
	
	
	//예외 발생 문장 흐름-- 프로그램이 강제로 죽는다
	public static void exam2()
	{
		System.out.println("나눗셈 연산 수행");
		float result = 0/0;
		System.out.println("결과값"+result);
	}
	
	//예외 발생 문장 흐름-- 프로그램이 강제로 죽는다
		public static void exam3()
		{
			try
			{
				System.out.println("나눗셈 연산 수행");
				float result = 0/0;
				System.out.println("결과값"+result);
			}
			catch(ArithmeticException a)
			{
				System.out.println("예외 "+a.getMessage());
			}
		}
		
		//예외 발생 문장 흐름-- 중첩적인 catch가 필요하다
		//모든 예외 클래스의 부모는 exception클래스이다.
		public static void exam4()
		{
			try
			{
				System.out.println("배열 연산 수행");
				int[] arr = new int[2];
				arr[2]=10;//ArrayIndexOutOfBoundsException 에러 전달
				System.out.println();
				float result = 0/0;
				System.out.println("결과값"+result);
			}
			catch(ArithmeticException a)
			{
				System.out.println("예외 "+a.getMessage());
			}
			catch(ArrayIndexOutOfBoundsException e)
			{
				System.out.println("예외 "+e.getMessage());
			}
			catch(Exception e)
			{
				System.out.println("여기서 모든 예외를 잡을수있다. ");
			}
		}
		
		//finally
		//무조건 실행이 되는 문장
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

		//예외를 발생시키는 메서드 만들기
		//내가 직접 try catch를 예외로 잡을수있다. 예외를 나를 호출한 함수에게 전달할수있다. 이를 예외를 발생시키는 메서드라고 한다
		
		public static void exam6sample(int value) throws Exception
		{
			if(value<0)//value가 음수라면 전달
				throw new Exception("음수가 전달되었습니다.");
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
