
public class Shape 
{
	//1.�ɹ� �ʵ� (����)
	private String color = "blue";	//�ɹ����� ����� ���ÿ� ��ü �ʱ�ȭ
									//�����Ǵ� ��� shape��ü���� ������ '�Ķ���'���� �����ȴ�
	
	//���� ��ü ������ ��ü�� ���� ���ϴ� ������ �ʱ�ȭ �ϰ� �ʹ�? �����ڸ� Ȱ���Ѵ�
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
	//�޼���
	public void Draw()
	{
		System.out.println("���� : " + color);
	}
}
