package woosongbit.sample1;


//ȸ����ȣ,�̸� �� ��ȭ ��ȣ ���� ���α׷�
//1���� ���� �����ϴ� ȸ�� ��ȣ//static�ɹ� ����
//�̸� ��ȭ��ȣ�� ����� �Է�
//���:���,�˻�(�̸�-key),����(�̸�-key ��ȭ��ȣ�� ����),��ü ���
public class Start 
{
	private MemberManager mem = new MemberManager();
	
	private String[] InputPaser() 
	{
		String msg = Input.InputString(">> ");
		return msg.split(" ");  //split : ���ڿ��� (" ")���� �ɰ���.
	}
	
	private void Init() {
		System.out.println(" java ���� ���� �ɹ� ���� ���α׷�");
		System.out.println("==========================================================");
		System.out.println(" ����");
		System.out.println(" �Է�: insert �̸� ��ȭ��ȣ");
		System.out.println(" �˻�: select �̸�");
		System.out.println(" ����: delete �̸�");
		System.out.println(" ����: update �̸� ��ȭ��ȣ");
		System.out.println(" ����: exit");
		System.out.println("==========================================================");
		
		Input.InputString("����Ű�� ��������");
	}
	
	
	//�迭�� ����� ������ ��ü ���
	public void Run() {		
		//�����
		while(true) {
			String[] msg = InputPaser();
			if(msg[0].equals("insert")) 
			{			//insert �̸� ��ȭ��ȣ 
				String name = msg[1];
				String phone = msg[2];
				mem.Insert(name,  phone);				
			}
			else if(msg[0].equals("select"))
			{		//select �̸� 
				String name = msg[1];
				mem.Select(name);				
			}
			else if(msg[0].equals("delete")) 
			{		//delete
				String name = msg[1];
				mem.Delete(name);				
			}
			else if(msg[0].equals("update"))
			{
				String name = msg[1];
				String newphone= msg[2];
				mem.Update(name,newphone);
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
