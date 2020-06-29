import woosongbit.sample.DrinkManager;
import woosongbit.sample.Input;

public class Start 
{
	private DrinkManager DM = new DrinkManager();
	
	private String[] InputPaser() 
	{
		String msg = Input.InputString(">> ");
		return msg.split(" ");  //split : ���ڿ��� (" ")���� �ɰ���.
	}
	
	private void Init() {
		System.out.println(" java ���� ���� �ɹ� ���� ���α׷�");
	      System.out.println("-------------------------------------------------");
			System.out.println(" �����");
			System.out.println(" �Է� : insert1 �̸� ����");
			System.out.println(" �Է� : insert2 �̸� ���� �� �� ��");
			System.out.println(" �˻� : select  ��ǰ��");
			System.out.println(" ���� : delete ��ǰ��");
			System.out.println(" ���� : update ��ǰ�� ����");
			System.out.println(" ���α׷� ���� : exit");
			System.out.println("-------------------------------------------------\n");
		Input.InputString("����Ű�� ��������");
	}
	
	
	//�迭�� ����� ������ ��ü ���
	public void Run() {		
		//�����
		while(true) {
			String[] msg = InputPaser();
			if(msg[0].equals("insert1")) 
			{			//insert �̸� ����
				String name = msg[1];
				int price = Integer.parseInt(msg[2]);
				DM.Insert1(name,price);				
			}
			else if(msg[0].equals("insert2")) 
			{			//insert �̸� ���� �� �� ��
				String name = msg[1];
				int price = Integer.parseInt(msg[2]);
				int year = Integer.parseInt(msg[3]);
				int month = Integer.parseInt(msg[4]);
				int day = Integer.parseInt(msg[5]);
				DM.Insert2(name,price,year,month,day);				
			}
			else if(msg[0].equals("select"))
			{		//select �̸� 
				String name = msg[1];
				DM.Select(name);				
			}
			else if(msg[0].equals("delete")) 
			{		//delete
				String name = msg[1];
				DM.Delete(name);				
			}
			else if(msg[0].equals("update"))
			{
				String name = msg[1];
				int price = Integer.parseInt(msg[2]);
				DM.Update(name,price);
			}
			else if(msg[0].equals("exit"))
				break;
		}
	}
	
	
	public static void main(String[] args)
	{
		Start s= new Start();
		s.Init();
		s.Run();
		
	}
}
