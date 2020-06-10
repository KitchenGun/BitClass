
public class Student 
{
		//맴버 변수
		private final int num;	//학번
		private String name;	//이름
		private int c;			//c
		private int cpp;		//cpp
		private int	java;		//java
		private float average=0.0f;	//average
		
		//생성자
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
		
		//외부접근 변경 불가능
		private void setName(String name) {
			this.name = name;
		}

		public float getAverage() {
			return average;
		}
		
		//외부접근 변경 불가능
		private void setAverage(float average) {
			this.average = average;
		}
		//출력
		public void Print()
		{
			System.out.print(num+" "+name+" "+c+" "+cpp + " "+java + " "+average + " \n");
		}
		public void Println()
		{
			System.out.println("학번 : "+num);
			System.out.println("이름 : "+name);
			System.out.println("c : "+c);
			System.out.println("cpp : "+cpp);
			System.out.println("java : "+java);
			System.out.println("average : "+average);
		}
		//연산
		public void SetJumsu(int c,int cpp,int java)
		{
			//입력
			setC(c);
			setCpp(cpp);
			setJava(java);
			//연산
			average=(float)(this.c+this.cpp+this.java)/3;
			
		}
}
