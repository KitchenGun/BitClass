import woosongbit.sample1.Input;
import woosongbit.sample1.StudentManager;;

public class Start 
{
	
		private StudentManager stu = new StudentManager();
		
		private String[] InputPaser() 
		{
			String msg = Input.InputString(">> ");
			return msg.split(" ");  //split : ���ڿ��� (" ")���� �ɰ���.
		}
		
		private void Init() {
			System.out.println(" java ���� ���� �ɹ� ���� ���α׷�");
			System.out.println("==========================================================");
			System.out.println(" ����");
			System.out.println(" �Է� : insert �̸�");
			System.out.println(" �˻� : select �̸�");
			System.out.println(" ���� : delete �̸�");
			System.out.println(" ���� : update �̸� c������� cpp�������");
			System.out.println(" ����: exit");
			System.out.println("==========================================================\n");
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
					stu.Insert(name);				
				}
				else if(msg[0].equals("select"))
				{		//select �̸� 
					String name = msg[1];
					stu.Select1(name);				
				}
				else if(msg[0].equals("delete")) 
				{		//delete
					String name = msg[1];
					stu.Delete1(name);				
				}
				else if(msg[0].equals("update"))
				{
					String name = msg[1];
					int c = Integer.parseInt(msg[2]);
					int cpp = Integer.parseInt(msg[3]);
					stu.Update1(name,c,cpp);
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
