
//박싱 : 값형식을 주소값 형식에 대입할 때 벌어지는 일
//      - 힙메모리에 값을 저장할 수 있는 공간을 생성
//      - 생성된 공간에 값을 저장
//      - 저장된 주소값을 반환 

//언박싱 : 주소값 형식을 값 형식에 대입할 때 벌어지는 일
//      - 힙 메모리에 있는 값을 반환 
public class Start {
	public static void main(String[] args) {
		Object obj;
		int num = 10;
		
		obj = num;		//박싱(이 때 사용된 힙 객체 : Integer 클래스:맴버변수로 정수값을 갖고 있다.) 
		//obj =  new Integer(num);
		
		
		int num1 = (int)obj;   //언박싱 	
		
		System.out.println(num1); 	// 10
	}
}
