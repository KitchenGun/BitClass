
public class Triangle extends Shape
{
	private Point[] p;
	
	
	public Triangle(String color,Point[] p)
	{
		super(color); // �θ� ��ü ������ ���� �����ڸ� ����
		
		this.p=p;
	}

	public Triangle(String color,Point p1,Point p2, Point p3)
	{
		super(color);
		this.p=new Point[] {p1,p2,p3};
	}



}
