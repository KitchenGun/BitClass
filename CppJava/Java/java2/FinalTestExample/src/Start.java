import woosongbit.sample.MemberManager;
import woosongbit.sample.Input;

public class Start 
{
	private MemberManager MM = new MemberManager();
	
	private String[] InputPaser() 
	{
		String msg = Input.InputString(">> ");
		return msg.split(" ");  //split : ���ڿ��� (" ")���� �ɰ���.
	}
	
	private void Init() {
		 System.out.println("-------------------------------------------------");
			System.out.println(" Java ���� ���� ��ǰ ���� ���α׷�");
			System.out.println("-------------------------------------------------");
			System.out.println(" �����");
			System.out.println(" �Է� : insert1 �̸�");
			System.out.println(" �Է� : insert2 �̸� ���� ��ȭ��ȣ �� �� ��");
			System.out.println(" �˻� : select  �̸�");
			System.out.println(" ���� : delete �̸�");
			System.out.println(" ���� : update �̸� ��ȭ��ȣ");
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
				MM.Insert1(name);				
			}
			else if(msg[0].equals("insert2")) 
			{			//insert �̸� ���� �� �� ��
				String name = msg[1];
				char gender = msg[2].charAt(0);
				String phone = msg[3];
				int year = Integer.parseInt(msg[4]);
				int month = Integer.parseInt(msg[5]);
				int day = Integer.parseInt(msg[6]);
				MM.Insert2(name,gender,phone,year,month,day);				
			}
			else if(msg[0].equals("select"))
			{		//select �̸� 
				String name = msg[1];
				MM.Select(name);				
			}
			else if(msg[0].equals("delete")) 
			{		//delete
				String name = msg[1];
				MM.Delete(name);				
			}
			else if(msg[0].equals("update"))
			{
				String name = msg[1];
				String phone = msg[2];
				MM.Update(name,phone);
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
