package woosongbit.sample2;

/*
 * ����� ���Ǳ�(VendingMachine)
 *   - �ɹ�����
 *     �������  : Drink[] d = new Drink[3];
 *     ���Աݾ�  : int money = 0;     
 *   - �ɹ��Լ�
 *     ���� ����     : void InputMoney(int money);
 *     ��ǰ ����() : Drink SelectDrink(String name);
 *     �ܾ� ��ȯ() : int GetMoney();
 * ------------------------------------------------------------ 
 * [1] �ݶ�(1000��/5��)   [2] ���̴�(900��/3��)  [3] Ŀ��(500��/2��)   
 * ------------------------------------------------------------
 * ���Աݾ� >> 0��  
 * -------------------------------------------------------------
 * [1] ���� ����      [2] ��ǰ ����      [3] �ܾ� ��ȯ
 * -------------------------------------------------------------
 */


public class VendingMachine 
{
	//�ɹ� ����
	private Drink[] drink = new Drink[3];
	private int money =0;
	//������
	public VendingMachine() {
		//��ǰ�� �̸� ���
		drink[0] = new Drink("�ݶ�", 1000, 5);
		drink[1] = new Drink("���̴�", 900, 3);
		drink[2] = new Drink("Ŀ��", 500, 2);
	}

	//getset
	
	//�޼���
	public void InputMoney(int money) throws Exception
	{
		if(money<=0)
			throw new Exception("�߸��� �ݾ��� ����");
		this.money+=money;
	}
	
	public Drink SelectDrink(String name) throws Exception
	{
		for(Drink d:drink)//foreach �迭��ü ��ȯ�� ����ϴ� ����
		{
			if(d.getName().equals(name))
			{
				d.Buy();//throw new exception
				//�ܾ� ����
				if(this.money<d.getPrice())
				{
					throw new Exception("�ܾ׺���");
				}
				this.money-=d.getPrice();
				return d;
			}
		}
		throw new Exception("��ǰ�̸� �߸� ������");
	}
	
	public int GetMoney() throws Exception
	 {
		if( money == 0)
			throw new Exception("��ȯ�ݾ��� �����ϴ�.");

		int temp = this.money;
		money = 0;
		return temp;
	}

	public void View() {
		System.out.println("------------------------------------------------------------");
		for(int i=0; i< drink.length; i++) 
		{
			System.out.printf("[%d] ",i);
			drink[i].Print();
			System.out.printf("\t");
		}
		System.out.println("");
		System.out.println("------------------------------------------------------------"); 
		System.out.printf("���Աݾ� >>  %d��\n", money);  
		System.out.println("------------------------------------------------------------"); 
	}

	
}
