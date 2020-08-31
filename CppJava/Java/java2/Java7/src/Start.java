import woosongbit.sample.*;

public class Start 
{
	
		private AccountManager acc = new AccountManager();
		
		private String[] InputPaser() 
		{
			String msg = Input.InputString(">> ");
			return msg.split(" ");  //split : ���ڿ��� (" ")���� �ɰ���.
		}
		
		private void Init() 
		{
			System.out.println("-------------------------------------------------");
			System.out.println(" Java ���� ���� ���� ���� ���α׷�");
			System.out.println("-------------------------------------------------");
			System.out.println(" �����");
			System.out.println(" �Է� : insert1 �̸�");
			System.out.println(" �Է� : insert2 �̸� �Աݾ� ��������");
			System.out.println(" �˻� : select  ���¹�ȣ");
			System.out.println(" ���� : delete ���¹�ȣ");
			System.out.println(" ���� : updateinput ���¹�ȣ �Աݾ�");
			System.out.println(" ���� :  ���¹�ȣ ��ݾ�");
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
				{			
					String name = msg[1];
					acc.Insert(name);				
				}
				else if(msg[0].equals("insert2")) 
				{			
					String name = msg[1];
					int balance = Integer.parseInt(msg[2]);
					String date = msg[3];
					acc.Insert(name,balance,date);				
				}
				else if(msg[0].equals("select"))
				{		 
					int accnum = Integer.parseInt(msg[1]);
					acc.Select(accnum);				
				}
				else if(msg[0].equals("delete")) 
				{		
					int accnum = Integer.parseInt(msg[1]);
					acc.Delete(accnum);				
				}
				else if(msg[0].equals("updateinput"))
				{
					int accnum = Integer.parseInt(msg[1]);
					int inputMoney = Integer.parseInt(msg[2]);
					acc.UpdateInput(accnum, inputMoney);
				}
				else if(msg[0].equals("updateoutput"))
				{
					int accnum = Integer.parseInt(msg[1]);
					int outputMoney = Integer.parseInt(msg[2]);
					acc.UpdateOutput(accnum, outputMoney);
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
