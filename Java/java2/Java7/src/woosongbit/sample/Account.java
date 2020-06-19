package woosongbit.sample;

public class Account 
{
	private int accnumber;
	private String name;
	private int balance;
	private String date;
	
	private static int s_accnumber=10000;
	
	public Account(String name)
	{
		s_accnumber+=15;
		accnumber=s_accnumber;
		this.name= name;
		this.balance = 0;
		this.date="2020-06-19";
	}
	
	public Account(String name,int balance,String date)
	{
		s_accnumber+=15;
		accnumber=s_accnumber;
		this.name= name;
		this.balance = balance;
		this.date=date;
	}
	//get set
	public int getAccNumber()
	{
		return accnumber;
	}
	//�޼���
	public final void Println()
	{
		System.out.println("���¹�ȣ"+accnumber);
		System.out.println("�̸�"+name);
		System.out.println("�ܾ�"+balance);
		System.out.println("��������"+date);
	}
	
	public boolean InputMoney(int inputMoney)
	{
		if(inputMoney<=0)
		{
			return false;
		}
		else
		{
			balance+=inputMoney;
			return true;
		}
	}
	
	public boolean OutputMoney(int outputMoney)
	{
		if(outputMoney<=0)
		{
			return false;
		}
		else
		{
			if(outputMoney>balance)
			{
				return false;
			}
			else 
			{
				balance-=outputMoney;
				return true;
			}
		}
	}
	
	
}
