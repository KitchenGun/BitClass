
//�ڽ� : �������� �ּҰ� ���Ŀ� ������ �� �������� ��
//      - ���޸𸮿� ���� ������ �� �ִ� ������ ����
//      - ������ ������ ���� ����
//      - ����� �ּҰ��� ��ȯ 

//��ڽ� : �ּҰ� ������ �� ���Ŀ� ������ �� �������� ��
//      - �� �޸𸮿� �ִ� ���� ��ȯ 
public class Start {
	public static void main(String[] args) {
		Object obj;
		int num = 10;
		
		obj = num;		//�ڽ�(�� �� ���� �� ��ü : Integer Ŭ����:�ɹ������� �������� ���� �ִ�.) 
		//obj =  new Integer(num);
		
		
		int num1 = (int)obj;   //��ڽ� 	
		
		System.out.println(num1); 	// 10
	}
}
