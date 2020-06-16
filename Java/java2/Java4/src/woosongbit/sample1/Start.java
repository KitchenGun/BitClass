package woosongbit.sample1;
import java.util.Scanner;

public class Start 
{

	private static void exam1() 
	{
		IntDArray arry1 = new IntDArray(5);
		System.out.println("���� ���� : " + arry1.getSize());
		arry1.add(10);
		arry1.add(20);
		arry1.add(30);
		System.out.println("���� ���� : " + arry1.getSize());
	}
	//=====================================================================

	private Scanner scan = new Scanner(System.in);
	private IntDArray array;

	//����ڿ��� ���尳�� ����
	private int Init() {
		System.out.print("���� ���� : ");
		//return scan.nextInt();//enter�� ����
		return Integer.parseInt(scan.nextLine());
	}
	//�Է� ��ɾ �Ľ�
	private String[] InputPaser() {
		System.out.print(">> ");
		String msg = scan.nextLine();
		return msg.split(" ");//���ڿ��� �������� �ɰ���.
	}
	
	private void PrintAll()
	{
		System.out.print("[���尳�� : "+array.getSize()+"]");
		for(int i=0; i< array.getSize(); i++) 
		{
			System.out.print(array.getData(i) + " ");			
		}
		System.out.println();
	}
	
	
	//�迭�� ����� ������ ��ü ���
	public void examrun()
	{
		//�ʱ�ȭ
		int capacity = Init();
		array = new IntDArray(capacity);
		//�����
		while(true) 
		{
			String[] msg = InputPaser();
			if(msg[0].equals("add")) 
			{
				boolean b = array.add( Integer.parseInt(msg[1]));
				if(b)
					PrintAll();
				else
					System.out.println("����");
			}
			else if(msg[0].equals("remove"))
			{
				boolean b = array.remove(Integer.parseInt(msg[1]));
				if(b)
				{
					PrintAll();
				}
				else
				{
					System.out.println("����");
				}
			}
			else if(msg[0].equals("update"))
			{
				int value = Integer.parseInt(msg[1]);
				int upvalue = Integer.parseInt(msg[2]);
				boolean b = array.update(value, upvalue);
				if(b)
					PrintAll();
				else
					System.out.println("����");
			}
			else if(msg[0].equals("exit"))
			{
				break;
			}
		}
	}
	
	public static void main(String[] args)
	{
		new Start().examrun();
	}
}
