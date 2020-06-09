import java.util.Scanner;//java.util ��Ű����  Scanner Ŭ������
							//import ����ϱ� ���ؼ� ���� �ϰڴ�
//start.java
public class Start 
{
	//System.out ��� ��ü
	private static void PrintSample()
	{
		//print
		System.out.print("Hello, World\n");
		System.out.print(10+"\n");//���� + ���� = ���ڿ�
		System.out.print('a');
		System.out.print("\n");
		//println
		System.out.println("Hello, World");
		System.out.println('a');
		System.out.println('��');//�ѱ۵� ����Ÿ���� ����Ѵ� (�ƽ�Ű�ڵ�(1 byte)�� �ƴ� �����ڵ�(2 byte)�� �����)
		//printf
		System.out.printf("���ڿ� ȣ��: %s\n", "Hello, World");
	}
	
	//System.in �Է� ��ü
	//Scanner �Էº��� Ŭ����(�ɹ� ������ �Է� ��ü�� ������ �ְ� �̸� �̿��ؼ� �Է� ����� ����)
	//���ڿ� �Է� �� Ÿ�� ���� 
	public static void InputSample()
	{
		Scanner scan = new Scanner(System.in);
		
		System.out.print("�̸� : ");
		String name=scan.nextLine();//���ڿ� ���� Ŭ����
		
		System.out.print("���� : ");
		int age;
		String temp = scan.nextLine();
		age = Integer.parseInt(temp);//���ڿ� int�� ��ȯ
		
		System.out.print("������ : ");
		float weight = Float.parseFloat(scan.nextLine());
		
		System.out.print("(��,��) : ");
		temp = scan.nextLine();
		char gender = temp.charAt(0);// ���ڿ� �� 0���� �ε����� ���� ��ȯ
		//----------------------------------------------------
		System.out.println("�̸�:"+name);
		System.out.println("����:"+age);
		System.out.println("������:"+weight);
		System.out.println("����:"+gender);
	}
	
	public static void InputSample1()
	{
		Scanner scan = new Scanner(System.in);
		
		System.out.print("�̸� : ");
		String name=scan.nextLine();//���ڿ� ���� Ŭ����
		
		System.out.print("���� : ");
		int age = scan.nextInt();

		
		System.out.print("������ : ");
		float weight = scan.nextFloat();
		scan.nextLine();
		System.out.print("����(��, ��) : ");
		char gender = scan.nextLine().charAt(0); // ���ڿ� �� 0���� �ε����� ���� ��ȯ
		//----------------------------------------------------
		System.out.println("�̸�:"+name);
		System.out.println("����:"+age);
		System.out.println("������:"+weight);
		System.out.println("����:"+gender);
	}
	
	private static void Array1()
	{
		Scanner scan = new Scanner(System.in);
		//�迭�� ���۷��� Ÿ��
		//int�� �����ϴ� []�迭 Ÿ���̴� ���̸��� arr
		int[] arr; 	//��ȣ�ϴ� ���
		int arr1[];
		//�迭�� ���۷��� Ÿ��
		System.out.print("���� �� ���� ����");
		int max = scan.nextInt();
		arr= new int[max];
		//������
		for(int i=0;i<arr.length;i++)
		{
			arr[i]=(int)(Math.random()*10)+1;//
		}
		//���
		for(int i=0;i<arr.length;i++)
		{
			System.out.println(arr[i]+" ");
		}
	}
	
	private static void Array2() //2���� �迭 ����(2*3)
	{
		int[][] arr = new int[2][3];
		
		int[][] arr1 = {{1,2,3},
						{4,5,6}};
		//2���� �迭�� ��ȸ
		for(int i=0; i<arr.length; i++) //�� 2��
		{
			for(int j=0; j<arr[i].length; j++) //�� 3��
			{
				System.out.printf("arr[%d][%d] = %d\n",  i, j, arr[i][j]);
			}
		}

		
	}
	
	private static void Array3() //�ึ�� ���� ������ �ٸ� �����迭 ����
	{
		int[][] arr = new int[2][];
		
		arr[0]=new int [5];
		arr[1]=new int [3];
		
		//2���� �迭�� ��ȸ
		for(int i=0; i<arr.length; i++) //�� 2��
		{
			for(int j=0; j<arr[i].length; j++) //�� 3��
			{
				System.out.printf("arr[%d][%d] = %d\n",  i, j, arr[i][j]);
			}
		}

		
	}

	
	private static void ArrayCopy1()
	{
		int[] arr1= {1,2,3,4,5,6,7,8,9,10};
		int[] arr2 = new int[20];
		//�迭 ����
		for(int i =0;i<10;i++)
		{
			arr2[i] = arr1[i];
		}
		//���
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
		//�迭 ����
		//arr1 0��° �ε������� ���� �����ͼ�   arr2 0��° �ε��� ��ġ ���� �����ض� arr1.length��ŭ
		System.arraycopy(arr1, 0, arr2, 0, arr1.length);
		//���
		for(int i=0; i<arr2.length; i++)
		{
			System.out.print(arr2[i] + "  ");
		}
		System.out.println();
	}
	public static void main(String[] args)
	{//static �޼��� �������� static �޼��常 ȣ�� ����
		//PrintSample();
		//InputSample1();
		ArrayCopy2();
	}
}
