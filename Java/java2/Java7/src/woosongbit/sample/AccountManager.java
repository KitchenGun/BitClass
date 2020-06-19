package woosongbit.sample;
//��ü ���� Ŭ����
public class AccountManager 
{
	//���� ��ü
	private ObjectDArray array;
	//������
	public AccountManager()
	{
		int max = InputSize();
		array = new ObjectDArray(max);//���� ����
	}
	//�޼���-�ʱ�ȭ
	private int InputSize()
	{
		return Input.InputInteger("���尳��");
	}
	//�޼���-��ü ���
	private void PrintAll() 
	{
		for(int i=0; i< array.getSize(); i++) {
			Account acc  = (Account)array.getData(i); //�ڽ� <= �θ� : �ٿ�ĳ����
			acc.Println();
			//System.out.print(acc.getName() + ", ");
		}
		System.out.println("\n");
	}
	
	//�޼���-���
	public void Insert(String name)
	{
		Account acc = new Account(name);
		if( array.add(acc) )
			PrintAll();
		else
			System.out.println("����");
	}
	
	public void Insert(String name,int balance, String date)
	{
		Account acc = new Account(name,balance,date);
		if( array.add(acc) )
			PrintAll();
		else
			System.out.println("����");
	}
	
	//�޼��� - �˻�
	public void Select(int accnum) 
	{
		int idx = array.valueToIdx(accnum);
		if( idx == -1)
		{
			System.out.println("����");
			return;
		}
		
		Account acc = (Account)array.getData(idx);
		acc.Println();
	}
	
	//�޼��� - ����
	public void UpdateInput(int accnum, int inputMoney) 
	{		
		int idx = array.valueToIdx(accnum);			
		if( idx == -1)
		{
			System.out.println("����");
			return;	
		}
			
		Account acc = (Account)array.getData(idx);
		acc.InputMoney(inputMoney);
			PrintAll();
	}
 
	public void UpdateOutput(int accnum, int outputMoney) 
	{		
		int idx = array.valueToIdx(accnum);			
		if( idx == -1)
		{
			System.out.println("����");
			return;	
		}
			
		Account acc = (Account)array.getData(idx);
		acc.OutputMoney(outputMoney);
			PrintAll();
	}
	//�޼��� - ����
	public void Delete(int accnum)
	{
		if(array.remove(accnum))
		{
			PrintAll();
		}
		else
		{
			System.out.println("����");
		}
	}
	
	
}
