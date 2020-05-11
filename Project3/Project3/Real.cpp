<<<<<<< HEAD
<<<<<<< HEAD
//ÃÖÁ¾ ÄÚµå
#include<iostream>
using namespace std;

//°´Ã¼ÁöÇâÇÁ·Î±×·¥Àº class  ¸¸ »ç¿ëÇÔ
//struct->class
//±¸Á¶Ã¼´Â ±âº»ÀÌ public ÀÌ¸é Å¬·¡½º´Â ±âº»ÀÌ privateÀÌ´Ù
class Student
{
private://¸É¹ö º¯¼ö Á¤ÀÇ
	char* name;
	int number;
	char* subject;
	char gender;
public://»ı¼ºÀÚ ±¸Çö
	Student(const char* _name, int _number, const char* _subj, char _gender)
	{
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
		number = _number;
		subject = new char[strlen(_subj) + 1];
		strcpy_s(subject, strlen(_subj) + 1, _subj);
		gender = _gender;
	}
	~Student()
	{
		delete[] name;//µ¿Àû ¸Ş¸ğ¸®
		delete[] subject;//µ¿Àû ¸Ş¸ğ¸®
	}
	void Print()
	{
		cout << "ÀÌ¸§ : " << name << endl;
		cout << "ÇĞ¹ø : " << number << endl;
		cout << "ÇĞ°ú : " << subject << endl;
		cout << "¼ºº° : " << gender << endl;
	}
};

int main()
{
	//½ºÅÃ¿¡ °´Ã¼¸¦ »ı¼º
	Student stu("È«±æµ¿", 1111, "ÄÄÇ»ÅÍ", 'm');
	stu.Print();
	//Èü°´Ã¼¸¦ »ı¼º
	Student* pstu = new Student("È«±æ¼ø", 2222, "it", 'f');

=======
=======
>>>>>>> parent of e69348b... ìº¡ìŠí™” ìƒì„±ì ì†Œë©¸ì ë³µìŠµ
//ÃÖÁ¾ ÄÚµå
#include<iostream>
using namespace std;

//°´Ã¼ÁöÇâÇÁ·Î±×·¥Àº class  ¸¸ »ç¿ëÇÔ
//struct->class
//±¸Á¶Ã¼´Â ±âº»ÀÌ public ÀÌ¸é Å¬·¡½º´Â ±âº»ÀÌ privateÀÌ´Ù
class Student
{
private://¸É¹ö º¯¼ö Á¤ÀÇ
	char* name;
	int number;
	char* subject;
	char gender;
public://»ı¼ºÀÚ ±¸Çö
	Student(const char* _name, int _number, const char* _subj, char _gender)
	{
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
		number = _number;
		subject = new char[strlen(_subj) + 1];
		strcpy_s(subject, strlen(_subj) + 1, _subj);
		gender = _gender;
	}
	~Student()
	{
		delete[] name;//µ¿Àû ¸Ş¸ğ¸®
		delete[] subject;//µ¿Àû ¸Ş¸ğ¸®
	}
	void Print()	{		cout << "ÀÌ¸§ : " << name << endl;		cout << "ÇĞ¹ø : " << number << endl;		cout << "ÇĞ°ú : " << subject << endl;		cout << "¼ºº° : " << gender << endl;	}
};

int main()
{
	//½ºÅÃ¿¡ °´Ã¼¸¦ »ı¼º
	Student stu("È«±æµ¿", 1111, "ÄÄÇ»ÅÍ", 'm');
	stu.Print();
	//Èü°´Ã¼¸¦ »ı¼º
	Student* pstu = new Student("È«±æ¼ø", 2222, "it", 'f');

<<<<<<< HEAD
>>>>>>> parent of e69348b... ìº¡ìŠí™” ìƒì„±ì ì†Œë©¸ì ë³µìŠµ
=======
>>>>>>> parent of e69348b... ìº¡ìŠí™” ìƒì„±ì ì†Œë©¸ì ë³µìŠµ
}