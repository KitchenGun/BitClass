
public class Student 
{
		//�ɹ� ����
		private final int num;	//�й�
		private String name;	//�̸�
		private int c;			//c
		private int cpp;		//cpp
		private int	java;		//java
		private float average=0.0f;	//average
		
		//������
		public Student(int num,String name,int c,int cpp,int java)
		{
			this.num=num;
			setName(name);
			setC(c);
			setCpp(cpp);
			setJava(java);
			SetJumsu(c, cpp, java);
		}

		//score
		public int getC() {
			return c;
		}

		public void setC(int c) {
			this.c = c;
		}

		public int getCpp() {
			return cpp;
		}

		public void setCpp(int cpp) {
			this.cpp = cpp;
		}

		public int getJava() {
			return java;
		}

		public void setJava(int java) {
			this.java = java;
		}

		//info
		public int getNum() {
			return num;
		}

		public String getName() {
			return name;
		}
		
		//�ܺ����� ���� �Ұ���
		private void setName(String name) {
			this.name = name;
		}

		public float getAverage() {
			return average;
		}
		
		//�ܺ����� ���� �Ұ���
		private void setAverage(float average) {
			this.average = average;
		}
		//���
		public void Print()
		{
			System.out.print(num+" "+name+" "+c+" "+cpp + " "+java + " "+average + " \n");
		}
		public void Println()
		{
			System.out.println("�й� : "+num);
			System.out.println("�̸� : "+name);
			System.out.println("c : "+c);
			System.out.println("cpp : "+cpp);
			System.out.println("java : "+java);
			System.out.println("average : "+average);
		}
		//����
		public void SetJumsu(int c,int cpp,int java)
		{
			//�Է�
			setC(c);
			setCpp(cpp);
			setJava(java);
			//����
			average=(float)(this.c+this.cpp+this.java)/3;
			
		}
}
