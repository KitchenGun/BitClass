
public class Triangle extends Shape
{
	private Point[] p;
	
	
	public Triangle(String color,Point[] p)
	{
		super(color); // 부모 객체 생성시 사용될 생성자를 지정
		
		this.p=p;
	}

	public Triangle(String color,Point p1,Point p2, Point p3)
	{
		super(color);
		this.p=new Point[] {p1,p2,p3};
	}



}
