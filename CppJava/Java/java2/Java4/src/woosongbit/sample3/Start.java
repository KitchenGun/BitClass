package woosongbit.sample3;
import java.util.Scanner;
//object(레퍼런스)<=char(값)
public class Start 
{
	private Scanner scan = new Scanner(System.in);
	private ObjectDArray array;//<===========
	
	//사용자에게 저장개수 질의
	private int Init() {
		System.out.print("저장 개수 : ");
		//return scan.nextInt();//enter가 남음
		return Integer.parseInt(scan.nextLine());
	}
	//입력 명령어를 파싱
	private String[] InputPaser() {
		System.out.print(">> ");
		String msg = scan.nextLine();
		return msg.split(" ");//문자열을 공백으로 쪼갠다.
	}
	
	private void PrintAll()
	{
		System.out.print("[저장개수 : "+array.getSize()+"]");
		for(int i=0; i< array.getSize(); i++) 
		{
			System.out.print(array.getData(i) + " ");			
		}
		System.out.println();
	}
	
	
	//배열에 저장된 정보를 전체 출력
	public void examrun()
	{
		//초기화
		int capacity = Init();
		array = new ObjectDArray(capacity);//<===========
		//실행부
		while(true) 
		{
			String[] msg = InputPaser();
			if(msg[0].equals("add")) 
			{
				char ch = msg[1].charAt(0);
				boolean b = array.add(ch);//값 형식이 레퍼런스 저장 방식에 저장이 됨 : 박싱
				if(b)
					PrintAll();
				else
					System.out.println("실패");
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
					System.out.println("실패");
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
					System.out.println("실패");
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
