#include"accmanager.h"


accManager::accManager() :max(SetMax())
{
    //������ ũ�⸦ max������ �缳��

    base.resize(max, 0);
}

accManager::~accManager()
{
    for (int i = 0; i < max; i++)
    {
        if (base[i] != 0) //���� ���°� ������ ������ Ȯ��
        {
            delete base[i];
        }
    }

}

int accManager::SetMax()
{
    return wbglobal::getnum("�ִ� ������ �л� ���� �Է��ϼ���");
}

void accManager::Run()
{
    int key = 0;
    while ((key = SelectMenu()) != ESC)
    {
        switch (key)
        {
        case F1: AddAccount(); break;
        case F2: RemoveAccount(); break;
        case F3: SearchAccountByNum(); break;
        case F4: SearchAccountByName(); break;
        case F5: UpdateInputAccount(); break;
        case F6: UpdateOutputAccount(); break;
        default: cout << "�߸��� �޴��� �����Ͽ����ϴ�." << endl;
            break;
        }
        wbglobal::pause();
    }
}

keydata accManager::SelectMenu()
{
    wbglobal::clrscr();
    ListAll();
    cout << "------------------------------------------------------------" << endl;
    cout << "�޴� [ESC]:����" << endl;
    cout << "[F1]:���� �߰� [F2]:���� ���� [F3]:���� ��ȣ�� �˻�(Key)" << endl;
    cout << " [F4]:�������� �˻�(�ټ�) [F5]:�Ա�[F6]:���" << endl;
    cout << "�޴��� �����ϼ���" << endl;
    return wbglobal::getkey();
}

void accManager::ListAll()
{
    for (int i = 0; i < max; i++)
    {
        cout << "[" << i << "] ";
        Account* acc = base[i];
        if (acc) //���� �л��� �����Ǿ����� Ȯ��
        {
            cout << acc;//��� ������ ������
        }
        cout << endl;
    }
}

void accManager::AddAccount()
{
    //[�����帧]
    //���������� �Է¹޴´�.
    //���尴ü�� �����Ѵ�.(���������� �̿��ؼ�)
    //�����Ѵ�. (���尴ü��)

    //[�����帧 ����]

    int accnum;
    char name[20];

    char buf[50];
    sprintf_s(buf, "�߰��� ���� ��ȣ�� �Է��ϼ���. (0~%d)", max - 1);
    accnum = wbglobal::getnum(buf);

    strcpy_s(name, sizeof(name), wbglobal::getstr("�̸��� �Է��ϼ���"));
    //=================================================================

    if ((accnum <= 0) || (accnum > max - 1))
    {
        cout << "������ ������ϴ�." << endl;

        return;
    }

    if (base[accnum])
    {
        cout << "�̹� ������ �л��� �ֽ��ϴ�." << endl;
        return;
    }

    //=================================================================
    Account* acc = new Account(accnum, name);
    base[accnum] = acc;
    cout << "����Ǿ����ϴ�." << endl;
}

void accManager::RemoveAccount()
{
    int accnum = 0;

    char buf[50];
    //buf�� ���ڿ��� ����
    sprintf_s(buf, "������ �л� ��ȣ�� �Է��ϼ���. (0~%d)", max - 1);
    accnum = wbglobal::getnum(buf);

    if ((accnum <= 0) || (accnum > max - 1))
    {
        cout << "������ ������ϴ�." << endl;
        return;
    }

    if (base[accnum] == 0) //���� ���°� �����Ǿ����� Ȯ��
    {
        cout << "������ ���°� �����ϴ�." << endl;
        return;
    }

    delete base[accnum];  //���� �ִ� �л����� ����

    //������ �����ּҰ��� 0���� �ʱ�ȭ 
    base[accnum] = 0; //�ʱⰪ 0���� �ٽ� ����
}

void accManager::SearchAccountByNum()
{
    int accnum = 0;
    char buf[50];
    //buf�� ���ڿ��� ����
    sprintf_s(buf, "�˻��� �л� ��ȣ�� �Է��ϼ���. (0~%d)",
        max - 1);

    accnum = wbglobal::getnum(buf);

    if ((accnum < 0) || (accnum > max - 1))
    {
        cout << "������ ������ϴ�." << endl;
        return;
    }

    if (base[accnum] == 0) //���� �л��� �����Ǿ����� Ȯ��
    {
        cout << accnum << "�ش� ���´� �������� �ʾҽ��ϴ�." << endl;
        return;
    }

    Account* acc = base[accnum];
    cout << acc << endl;
}


void accManager::SearchAccountByName()
{
    char name[20];
    char buf[50];
    //buf�� ���ڿ��� ����
    sprintf_s(buf, "�˻��� �л� �̸��� �Է��ϼ���. (0~%d)", max - 1);

    strcpy_s(name, sizeof(name), wbglobal::getstr(buf));

    for (int i = 0; i < max; i++)
    {
        Account* acc = base[i];
        if (acc!=NULL) //���� �л��� �����Ǿ����� Ȯ��
        {
            if (strcmp(acc->GetName(), name) == 0)
            {
                cout << acc << endl;
            }
        }
    }
    cout << name << " ���°� �������� �ʾҽ��ϴ�." << endl;

}

void accManager::UpdateInputAccount()
{
    try
    {
        int accnum = 0;
        char buf[50];
        //buf�� ���ڿ��� ����
        sprintf_s(buf, "�˻��� �л� ��ȣ�� �Է��ϼ���. (0~%d)", max - 1);
        accnum = wbglobal::getnum(buf);

        int idx = NumToIdx(accnum);
        //�Ա� �Է�ó��
        Account* acc = base[idx];

        int money = wbglobal::getnum("�Աݾ�");
        acc->InputMoney(money);
        cout << "�ԱݵǾ����ϴ�." << endl;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
}

void accManager::UpdateOutputAccount()
{
    try
    {
        int accnum = 0;
        char buf[50];
        //buf�� ���ڿ��� ����
        sprintf_s(buf, "�˻��� �л� ��ȣ�� �Է��ϼ���. (0~%d)", max - 1);
        accnum = wbglobal::getnum(buf);

        int idx = NumToIdx(accnum);
        //��� �Է�ó��
        Account* acc = base[idx];

        int money = wbglobal::getnum("��ݾ�");
        acc->OutputMoney(money);
        cout << "��ݵǾ����ϴ�." << endl;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
}

int accManager::NumToIdx(int accnum)
{
    for (int i = 0; i < max; i++)
    {
        Account* acc = base[i];
        if (acc != NULL)
        {
            if (acc->GetNumber() == accnum)
            {
                return i;
            }
        }
    }
    throw "�ش���´� �������� �ʽ��ϴ�.";
}
