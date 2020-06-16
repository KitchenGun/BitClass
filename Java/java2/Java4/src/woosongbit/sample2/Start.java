package woosongbit.sample2;
import java.util.Scanner;

public class Start 
{
	private Scanner scan = new Scanner(System.in);
	private charDArray array;

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
		array = new charDArray(capacity);
		//�����
		while(true) 
		{
			String[] msg = InputPaser();
			if(msg[0].equals("add")) 
			{
				char ch = msg[1].charAt(0);
				boolean b = array.add(ch);
				if(b)
					PrintAll();
				else
					System.out.println("����");
			}
			else if(msg[0].equals("remove"))
			{
				boolean b = array.remove(msg[1].charAt(0));
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
				char value = msg[1].charAt(0);
				char upvalue = msg[2].charAt(0);
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
