package woosongbit.sample2;

//���Ǳ�
/*�ɹ� ����
 * �������class Drink[]
 * ���� �ݾ�int
 * �ɹ��Լ�
 * �� �ִ� ���InputMoney(int money)
 * ��ǰ ����SelectDrink(String name)
 * ��ȯGetMoney()
 * ===================================
 * [1]�ݶ�(1000/5) [2]���̴�(900/3) [3]Ŀ��(500/2) 
 * ----------------------------------------
 * ���Աݾ�>>0��
 * ------------------------------------------
 * [1]���� ���� [2]��ǰ�� ���� [3]�ܾ� ��ȯ
 * ------------------------------------------
 *
 */


public class Start 
{
	private MachineManager mm = new MachineManager();
	
	private String[] InputPaser() 
	{
		String msg = Input.InputString(">> ");
		return msg.split(" ");  //split : ���ڿ��� (" ")���� �ɰ���.
	}
	
	private void Init() 
	{
		System.out.println("-------------------------------------------------");
		System.out.println(" Java ���� ���� ���Ǳ� ���� ���α׷�");
		System.out.println("-------------------------------------------------");
		System.out.println(" �����");
		System.out.println(" �������� : input ���Աݾ�");
		System.out.println(" ��ǰ���� : select ��ǰ��");
		System.out.println(" �ܾ׹�ȯ : getmoney");
		System.out.println(" ���α׷� ���� : exit");
		System.out.println("-------------------------------------------------\n");
		
		Input.InputString("����Ű�� ��������");
	}
	
	
	//�迭�� ����� ������ ��ü ���
	public void Run() {		
		//�����
		while(true) {
			mm.View();
			String[] msg = InputPaser();
			if(msg[0].equals("input")) {			//insert �̸� 
				int money = Integer.parseInt(msg[1]);				
				mm.InputMoney(money);				
			}
			else if(msg[0].equals("select")) {			//insert �̸� 
				String name = msg[1];				
				mm.SelectProduct(name);				
			}
			else if(msg[0].equals("getmoney")) {		//select �̸� 			
				mm.GetMoney();				
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
