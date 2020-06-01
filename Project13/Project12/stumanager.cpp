#include"stumanager.h"


stuManager::stuManager():max(SetMaxStu())
{
	//������ ũ�⸦ max������ �缳��

	base.resize(max, 0);
}

stuManager::~stuManager()
{
    for (int i = 0; i < max; i++)
    {
        if (base[i]!=0) //���� �л��� ������ ������ Ȯ��
        {
            delete base[i];
        }
    }

}

int stuManager::SetMaxStu()
{
    return wbglobal::getnum("�ִ� ������ �л� ���� �Է��ϼ���");
}

void stuManager::Run()
{
    int key = 0;
    while ((key = SelectMenu()) != ESC)
    {
        switch (key)
        {
             case F1: AddStu(); break;
             case F2: RemoveStu(); break;
             case F3: SearchStuByNum(); break;
             case F4: SearchStuByName(); break;
             case F5: UpdateStu(); break;
        default: cout << "�߸��� �޴��� �����Ͽ����ϴ�." << endl;
        }
        wbglobal::pause();
    }
}

keydata stuManager::SelectMenu()
{
    wbglobal::clrscr();
    ListAll();
    cout << "------------------------------------------------------------" << endl;
    cout << "�޴� [ESC]:����" << endl;
    cout << "[F1]:�л� �߰� [F2]:�л� ���� [F3]:��ȣ�� �˻�" << endl;
    cout << " [F4]:�̸����� �˻� [F5]:���� �Է�" << endl;
    cout << "�޴��� �����ϼ���" << endl;
    return wbglobal::getkey();
}

void stuManager::ListAll()
{
    for (int i = 0; i < max; i++)
    {
        cout << "[" << i << "] ";
        Stu* stu = base[i];
        if (stu) //���� �л��� �����Ǿ����� Ȯ��
        {
            cout << base[i];//��� ������ ������
        }
        cout << endl;
    }
}

void stuManager::AddStu()
{
    int num = 0;
    char buf[50];
    //buf�� ���ڿ��� ����
    sprintf_s(buf, "�߰��� �л� ��ȣ�� �Է��ϼ���. (0~%d)",
        max - 1);
    num = wbglobal::getnum(buf);

    if ((num <= 0) || (num > max - 1))
    {//����ó��1
        cout << "������ ������ϴ�." << endl;
        return;
    }

    if (base[num]) //���� �л��� �����Ǿ����� Ȯ��
    {//����ó��2
        cout << "�̹� ������ �л��� �ֽ��ϴ�." << endl;
        return;
    }

    char name[20];

    strcpy_s(name, sizeof(name), wbglobal::getstr("�̸��� �Է��ϼ���"));

    base[num] = new Stu(num, name);
    cout << "����Ǿ����ϴ�." << endl;
}

void stuManager::RemoveStu()
{
    int num = 0;

    char buf[50];
    //buf�� ���ڿ��� ����
    sprintf_s(buf, "������ �л� ��ȣ�� �Է��ϼ���. (0~%d)",
        max - 1);

    num = wbglobal::getnum(buf);

    if ((num <= 0) || (num > max - 1))
    {
        cout << "������ ������ϴ�." << endl;
        return;
    }

    if (base[num] == 0) //���� �л��� �����Ǿ����� Ȯ��
    {
        cout << "������ �л��� �����ϴ�." << endl;
        return;
    }

    delete base[num];  //���� �ִ� �л����� ����

    //������ �����ּҰ��� 0���� �ʱ�ȭ 
    base[num] = 0; //�ʱⰪ 0���� �ٽ� ����

}

void stuManager::SearchStuByNum()
{
    int num = 0;
    char buf[50];
    //buf�� ���ڿ��� ����
    sprintf_s(buf, "�˻��� �л� ��ȣ�� �Է��ϼ���. (0~%d)",
        max - 1);

    num = wbglobal::getnum(buf);

    if ((num < 0) || (num > max - 1))
    {
        cout << "������ ������ϴ�." << endl;
        return;
    }

    if (base[num] == 0) //���� �л��� �����Ǿ����� Ȯ��
    {
        cout << num << "�� �л��� �������� �ʾҽ��ϴ�." << endl;
        return;
    }

    Stu* stu = base[num];
    cout << stu << endl;
}

void stuManager::SearchStuByName()
{
    char name[20];
    char buf[50];
    //buf�� ���ڿ��� ����
    sprintf_s(buf, "�˻��� �л� �̸��� �Է��ϼ���. (0~%d)",
        max - 1);

    strcpy_s(name, sizeof(name), wbglobal::getstr(buf));

    for (int i = 0; i < max; i++)
    {
        if (base[i]) //���� �л��� �����Ǿ����� Ȯ��
        {
            if (strcmp(base[i]->GetName(), name) == 0)
            {
                cout << base[i] << endl;
                return;
            }
        }
    }
    cout << name << " �л��� �������� �ʾҽ��ϴ�." << endl;

}

void stuManager::UpdateStu()
{
    char name[20];
    char buf[50];
    //buf�� ���ڿ��� ����
    sprintf_s(buf, "������ �Է��� �л� �̸��� �Է��ϼ���. (0~%d)",
        max - 1);

    strcpy_s(name, sizeof(name), wbglobal::getstr(buf));

    for (int i = 0; i < max; i++)
    {
        if (base[i]) //���� �л��� �����Ǿ����� Ȯ��
        {
            if (strcmp(base[i]->GetName(), name) == 0)
            {
                Stu* stu = base[i];
                //���� �Է�ó��
                int c = wbglobal::getnum("C�������");
                int cpp = wbglobal::getnum("C++�������");
                int java = wbglobal::getnum("Java�������");
                stu->SetScore(c, cpp, java);
                return;
            }
        }
    }
    cout << name << " �л��� �������� �ʾҽ��ϴ�." << endl;

}