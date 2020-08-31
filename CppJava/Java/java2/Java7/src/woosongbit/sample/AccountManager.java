package woosongbit.sample;
//전체 관리 클래스
public class AccountManager 
{
	//저장 객체
	private ObjectDArray array;
	//생성자
	public AccountManager()
	{
		int max = InputSize();
		array = new ObjectDArray(max);//갯수 전달
	}
	//메서드-초기화
	private int InputSize()
	{
		return Input.InputInteger("저장개수");
	}
	//메서드-전체 출력
	private void PrintAll() 
	{
		for(int i=0; i< array.getSize(); i++) {
			Account acc  = (Account)array.getData(i); //자식 <= 부모 : 다운캐스팅
			acc.Println();
			//System.out.print(acc.getName() + ", ");
		}
		System.out.println("\n");
	}
	
	//메서드-등록
	public void Insert(String name)
	{
		Account acc = new Account(name);
		if( array.add(acc) )
			PrintAll();
		else
			System.out.println("실패");
	}
	
	public void Insert(String name,int balance, String date)
	{
		Account acc = new Account(name,balance,date);
		if( array.add(acc) )
			PrintAll();
		else
			System.out.println("실패");
	}
	
	//메서드 - 검색
	public void Select(int accnum) 
	{
		int idx = array.valueToIdx(accnum);
		if( idx == -1)
		{
			System.out.println("없다");
			return;
		}
		
		Account acc = (Account)array.getData(idx);
		acc.Println();
	}
	
	//메서드 - 수정
	public void UpdateInput(int accnum, int inputMoney) 
	{		
		int idx = array.valueToIdx(accnum);			
		if( idx == -1)
		{
			System.out.println("없다");
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
			System.out.println("없다");
			return;	
		}
			
		Account acc = (Account)array.getData(idx);
		acc.OutputMoney(outputMoney);
			PrintAll();
	}
	//메서드 - 삭제
	public void Delete(int accnum)
	{
		if(array.remove(accnum))
		{
			PrintAll();
		}
		else
		{
			System.out.println("실패");
		}
	}
	
	
}
