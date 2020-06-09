import java.util.Scanner;//java.util 패키지명  Scanner 클래스명
							//import 사용하기 위해서 포함 하겠다
//start.java
public class Start 
{
	//System.out 출력 객체
	private static void PrintSample()
	{
		//print
		System.out.print("Hello, World\n");
		System.out.print(10+"\n");//정수 + 문자 = 문자열
		System.out.print('a');
		System.out.print("\n");
		//println
		System.out.println("Hello, World");
		System.out.println('a');
		System.out.println('남');//한글도 문자타입을 사용한다 (아스키코드(1 byte)가 아닌 유니코드(2 byte)를 사용함)
		//printf
		System.out.printf("문자열 호출: %s\n", "Hello, World");
	}
	
	//System.in 입력 객체
	//Scanner 입력보조 클래스(맴버 변수로 입력 객체를 가지고 있고 이를 이용해서 입력 기능을 수행)
	//문자열 입력 후 타입 변형 
	public static void InputSample()
	{
		Scanner scan = new Scanner(System.in);
		
		System.out.print("이름 : ");
		String name=scan.nextLine();//문자열 저장 클래스
		
		System.out.print("나이 : ");
		int age;
		String temp = scan.nextLine();
		age = Integer.parseInt(temp);//문자열 int로 변환
		
		System.out.print("몸무게 : ");
		float weight = Float.parseFloat(scan.nextLine());
		
		System.out.print("(남,여) : ");
		temp = scan.nextLine();
		char gender = temp.charAt(0);// 문자열 의 0번재 인덱스의 문자 변환
		//----------------------------------------------------
		System.out.println("이름:"+name);
		System.out.println("나이:"+age);
		System.out.println("몸무게:"+weight);
		System.out.println("성별:"+gender);
	}
	
	public static void InputSample1()
	{
		Scanner scan = new Scanner(System.in);
		
		System.out.print("이름 : ");
		String name=scan.nextLine();//문자열 저장 클래스
		
		System.out.print("나이 : ");
		int age = scan.nextInt();

		
		System.out.print("몸무게 : ");
		float weight = scan.nextFloat();
		scan.nextLine();
		System.out.print("성별(남, 여) : ");
		char gender = scan.nextLine().charAt(0); // 문자열 의 0번재 인덱스의 문자 변환
		//----------------------------------------------------
		System.out.println("이름:"+name);
		System.out.println("나이:"+age);
		System.out.println("몸무게:"+weight);
		System.out.println("성별:"+gender);
	}
	
	private static void Array1()
	{
		Scanner scan = new Scanner(System.in);
		//배열은 레퍼런스 타입
		//int를 저장하는 []배열 타입이다 그이름은 arr
		int[] arr; 	//선호하는 방식
		int arr1[];
		//배열은 레퍼런스 타입
		System.out.print("정수 값 저장 개수");
		int max = scan.nextInt();
		arr= new int[max];
		//랜덤값
		for(int i=0;i<arr.length;i++)
		{
			arr[i]=(int)(Math.random()*10)+1;//
		}
		//출력
		for(int i=0;i<arr.length;i++)
		{
			System.out.println(arr[i]+" ");
		}
	}
	
	private static void Array2() //2차원 배열 사용법(2*3)
	{
		int[][] arr = new int[2][3];
		
		int[][] arr1 = {{1,2,3},
						{4,5,6}};
		//2차원 배열의 순회
		for(int i=0; i<arr.length; i++) //행 2번
		{
			for(int j=0; j<arr[i].length; j++) //열 3번
			{
				System.out.printf("arr[%d][%d] = %d\n",  i, j, arr[i][j]);
			}
		}

		
	}
	
	private static void Array3() //행마다 열의 개수가 다른 가변배열 사용법
	{
		int[][] arr = new int[2][];
		
		arr[0]=new int [5];
		arr[1]=new int [3];
		
		//2차원 배열의 순회
		for(int i=0; i<arr.length; i++) //행 2번
		{
			for(int j=0; j<arr[i].length; j++) //열 3번
			{
				System.out.printf("arr[%d][%d] = %d\n",  i, j, arr[i][j]);
			}
		}

		
	}

	
	private static void ArrayCopy1()
	{
		int[] arr1= {1,2,3,4,5,6,7,8,9,10};
		int[] arr2 = new int[20];
		//배열 복사
		for(int i =0;i<10;i++)
		{
			arr2[i] = arr1[i];
		}
		//출력
		for(int i=0; i<arr2.length; i++)
		{
			System.out.print(arr2[i] + "  ");
		}
		System.out.println();
	}

	private static void ArrayCopy2()
	{
		int[] arr1= {1,2,3,4,5,6,7,8,9,10};
		int[] arr2 = new int[20];
		//배열 복사
		//arr1 0번째 인덱스부터 값을 가져와서   arr2 0번째 인덱스 위치 부터 저장해라 arr1.length만큼
		System.arraycopy(arr1, 0, arr2, 0, arr1.length);
		//출력
		for(int i=0; i<arr2.length; i++)
		{
			System.out.print(arr2[i] + "  ");
		}
		System.out.println();
	}
	public static void main(String[] args)
	{//static 메서드 내에서는 static 메서드만 호출 가능
		//PrintSample();
		//InputSample1();
		ArrayCopy2();
	}
}
