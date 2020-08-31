#include"accmanager.h"


accManager::accManager() :max(SetMax())
{
    //백터의 크기를 max값으로 재설정

    base.resize(max, 0);
}

accManager::~accManager()
{
    for (int i = 0; i < max; i++)
    {
        if (base[i] != 0) //실제 계좌가 보관된 곳인지 확인
        {
            delete base[i];
        }
    }

}

int accManager::SetMax()
{
    return wbglobal::getnum("최대 관리할 학생 수를 입력하세요");
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
        default: cout << "잘못된 메뉴를 선택하였습니다." << endl;
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
    cout << "메뉴 [ESC]:종료" << endl;
    cout << "[F1]:계좌 추가 [F2]:계좌 삭제 [F3]:계좌 번호로 검색(Key)" << endl;
    cout << " [F4]:고객명으로 검색(다수) [F5]:입금[F6]:출금" << endl;
    cout << "메뉴를 선택하세요" << endl;
    return wbglobal::getkey();
}

void accManager::ListAll()
{
    for (int i = 0; i < max; i++)
    {
        cout << "[" << i << "] ";
        Account* acc = base[i];
        if (acc) //실제 학생이 보관되었는지 확인
        {
            cout << acc;//출력 연산자 재정의
        }
        cout << endl;
    }
}

void accManager::AddAccount()
{
    //[정상흐름]
    //저장정보를 입력받는다.
    //저장객체를 생성한다.(저장정보를 이용해서)
    //저장한다. (저장객체를)

    //[예외흐름 적용]

    int accnum;
    char name[20];

    char buf[50];
    sprintf_s(buf, "추가할 계좌 번호를 입력하세요. (0~%d)", max - 1);
    accnum = wbglobal::getnum(buf);

    strcpy_s(name, sizeof(name), wbglobal::getstr("이름을 입력하세요"));
    //=================================================================

    if ((accnum <= 0) || (accnum > max - 1))
    {
        cout << "범위를 벗어났습니다." << endl;

        return;
    }

    if (base[accnum])
    {
        cout << "이미 보관된 학생이 있습니다." << endl;
        return;
    }

    //=================================================================
    Account* acc = new Account(accnum, name);
    base[accnum] = acc;
    cout << "저장되었습니다." << endl;
}

void accManager::RemoveAccount()
{
    int accnum = 0;

    char buf[50];
    //buf에 문자열을 저장
    sprintf_s(buf, "삭제할 학생 번호를 입력하세요. (0~%d)", max - 1);
    accnum = wbglobal::getnum(buf);

    if ((accnum <= 0) || (accnum > max - 1))
    {
        cout << "범위를 벗어났습니다." << endl;
        return;
    }

    if (base[accnum] == 0) //실제 계좌가 보관되었는지 확인
    {
        cout << "보관된 계좌가 없습니다." << endl;
        return;
    }

    delete base[accnum];  //힙에 있는 학생정보 삭제

    //벡터의 저장주소값을 0으로 초기화 
    base[accnum] = 0; //초기값 0으로 다시 설정
}

void accManager::SearchAccountByNum()
{
    int accnum = 0;
    char buf[50];
    //buf에 문자열을 저장
    sprintf_s(buf, "검색할 학생 번호를 입력하세요. (0~%d)",
        max - 1);

    accnum = wbglobal::getnum(buf);

    if ((accnum < 0) || (accnum > max - 1))
    {
        cout << "범위를 벗어났습니다." << endl;
        return;
    }

    if (base[accnum] == 0) //실제 학생이 보관되었는지 확인
    {
        cout << accnum << "해당 계좌는 보관되지 않았습니다." << endl;
        return;
    }

    Account* acc = base[accnum];
    cout << acc << endl;
}


void accManager::SearchAccountByName()
{
    char name[20];
    char buf[50];
    //buf에 문자열을 저장
    sprintf_s(buf, "검색할 학생 이름을 입력하세요. (0~%d)", max - 1);

    strcpy_s(name, sizeof(name), wbglobal::getstr(buf));

    for (int i = 0; i < max; i++)
    {
        Account* acc = base[i];
        if (acc!=NULL) //실제 학생이 보관되었는지 확인
        {
            if (strcmp(acc->GetName(), name) == 0)
            {
                cout << acc << endl;
            }
        }
    }
    cout << name << " 계좌가 보관되지 않았습니다." << endl;

}

void accManager::UpdateInputAccount()
{
    try
    {
        int accnum = 0;
        char buf[50];
        //buf에 문자열을 저장
        sprintf_s(buf, "검색할 학생 번호를 입력하세요. (0~%d)", max - 1);
        accnum = wbglobal::getnum(buf);

        int idx = NumToIdx(accnum);
        //입금 입력처리
        Account* acc = base[idx];

        int money = wbglobal::getnum("입금액");
        acc->InputMoney(money);
        cout << "입금되었습니다." << endl;
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
        //buf에 문자열을 저장
        sprintf_s(buf, "검색할 학생 번호를 입력하세요. (0~%d)", max - 1);
        accnum = wbglobal::getnum(buf);

        int idx = NumToIdx(accnum);
        //출금 입력처리
        Account* acc = base[idx];

        int money = wbglobal::getnum("출금액");
        acc->OutputMoney(money);
        cout << "출금되었습니다." << endl;
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
    throw "해당계좌는 존재하지 않습니다.";
}
