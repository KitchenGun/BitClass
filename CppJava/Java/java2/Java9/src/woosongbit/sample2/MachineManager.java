package woosongbit.sample2;

//자판기1대 관리 클래스
public class MachineManager 
{
	private VendingMachine vm = new VendingMachine();
	public MachineManager()
	{
		vm= new VendingMachine();
	}
	
	public void InputMoney(int money)
	{
		try
		{
			vm.InputMoney(money);
		}
		catch(Exception ex)
		{
			System.out.println(ex.getMessage());
		}
	}
	
	public void SelectProduct(String name)
	{
		try 
		{
			Drink drink = vm.SelectDrink(name);
			System.out.printf("%s 제품이 구매되었습니다.\n", drink.getName());
		}
		catch(Exception ex)
		{
			System.out.println(ex.getMessage());
		}
			
	}

	public void GetMoney() 
	{
		try 
		{
			int money = vm.GetMoney();
			System.out.printf("%d원이 반환되었습니다.\n",money);
		}
		catch(Exception ex) 
		{
			System.out.println(ex.getMessage());
		}
	}



	public void View() 
	{
		vm.View();
	}

}
