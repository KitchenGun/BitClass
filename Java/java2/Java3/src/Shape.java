
public class Shape 
{
	//1.맴버 필드 (변수)
	private String color = "blue";	//맴버변수 선언과 동시에 객체 초기화
									//생성되는 모든 shape객체들은 동일한 '파란색'으로 생성된다
	
	//만약 객체 생성시 객체들 마다 원하는 값으로 초기화 하고 싶다? 생성자를 활용한다
	public Shape(String color)
	{
		this.setColor(color);
	}
	//get set
	public String getColor() {
		return color;
	}
	public void setColor(String color) {
		this.color = color;
	}
	//메서드
	public void Draw()
	{
		System.out.println("색상 : " + color);
	}
}
