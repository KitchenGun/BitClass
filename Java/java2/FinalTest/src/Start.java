import woosongbit.sample.Input;
import woosongbit.sample.StuManager;

public class Start 
{
private StuManager SM = new StuManager();
	
	private String[] InputPaser() 
	{
		String msg = Input.InputString(">> ");
		return msg.split(" ");  //split : ���ڿ��� (" ")���� �ɰ���.
	}
	
	private void Init() {
		 System.out.println("-------------------------------------------------");
		 System.out.println(" �����");
		 System.out.println(" �Է� : insert �̸� �а� �г�"); 
		 System.out.println(" �˻� : select  �й�");
		 System.out.println(" ���� : delete �й�");
		 System.out.println(" ���� : update �й� �г�");  // �й����� �˻��Ͽ� �г��� ������ �� System.out.println(" ���α׷� ���� : exit"); 
		 System.out.println("-------------------------------------------------\n");
		Input.InputString("����Ű�� ��������");
	}
	
	
	//�迭�� ����� ������ ��ü ���
	public void Run() {		
		//�����
		while(true) {
			String[] msg = InputPaser();
			if(msg[0].equals("insert")) 
			{			//insert �̸� ����
				String name = msg[1];
				String subject = msg[2];
				int grade =Integer.parseInt(msg[3]);
				if(grade>=1&&grade<=4)
				{
					SM.Insert(name,subject,grade);	
				}
				else
				{
					System.out.println("�߸��� �г��� �ٽ� �Է��Ͻÿ�");
				}
			}
			else if(msg[0].equals("select"))
			{		//select �̸� 
				int number = Integer.parseInt(msg[1]);
				SM.Select(number);				
			}
			else if(msg[0].equals("delete")) 
			{		//delete
				int number = Integer.parseInt(msg[1]);
				SM.Delete(number);				
			}
			else if(msg[0].equals("update"))
			{
				int number = Integer.parseInt(msg[1]);
				int grade = Integer.parseInt(msg[2]);
				if(grade>=1&&grade<=4)
				{
					SM.Update(number,grade);
				}
				else
				{
					System.out.println("�߸��� �г��� �ٽ� �Է��Ͻÿ�");
				}
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
