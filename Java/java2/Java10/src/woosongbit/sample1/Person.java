package woosongbit.sample1;

public class Person 
{
	private int id;
	public Person(int id)
	{
		this.id =id;
	}
	
	@Override//아이디 비교
	public boolean equals(Object obj)
	{
		if(obj!=null&&obj instanceof Person)
		{
			Person temp = (Person)obj;
			if(this.id==temp.id)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return false;
	}
	
	
	
	
}
