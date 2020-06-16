package woosongbit.sample2;
//char들을 저장
public class charDArray 
{
	//1.맴버 필드(변수)
	private char[] base;//배열의 주소를 가지는 참조형 변
	private int capacity;//배열의 최대크기
	private int size; //배열의 데이터 저장개수,배열의 데이터 저장 위치
		
		//2.생성자 맴버 필드 초기화
	public	charDArray()
	{
		this(10);//사용자 크기 지정 안할시 기본 10으로 생성하겠다.
	}
		
	public charDArray(int capacity)
	{
		this.capacity=capacity;
		base=new char[capacity];
		size=0;
	}
		
	//3.GetSet메서드
	public int getSize()
	{
		return size;
	}
	//4.메서드
	private boolean isFull()
	{
		return capacity == size;
	}
	//저장 : 예외 처리(플로우)
	public boolean add(char value)
	{
		if(isFull())
			return false;
		
		base[size] = value;
		size++;
		return true;
	}
	//삭제
	public boolean remove(char value)
	{
		int idx=valueToIdx(value);
		if(idx==-1)
		{
			return false;
		}
		//삭제알고리즘
		for(int i = idx;i<size-1;i++)
		{
			base[i]=base[i+1];
		}
		size--;
		return true;
	}
		//검색
	public int valueToIdx(char value)
	{
		for(int i=0;i<size;i++)
		{
			if(base[i]==value)
			{
				return i;
			}
		}
		return -1;
	}
	//특정 인덱스에 있는 값 반환
	public char getData(int idx)
	{
		return base[idx];
	}
	//수정
	public boolean update(char value,char upvalue)
	{
		int idx=valueToIdx(value);
		if(idx==-1)
		{
			return false;
		}
		//수정알고리즘
		base[idx]=upvalue;
		return true;
	}
}
