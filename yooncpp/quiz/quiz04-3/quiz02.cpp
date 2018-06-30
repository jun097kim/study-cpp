#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
    enum { CLERK, SENIOR, ASSIST, MANAGER };

    void ShowPositionInfo(int pos)
    {
        switch (pos)
        {
            case COMP_POS::CLERK:
                cout << "사원" << endl;
                break;
            case COMP_POS::SENIOR:
                cout << "주임" << endl;
                break;
            case COMP_POS::ASSIST:
                cout << "대리" << endl;
                break;
            case COMP_POS::MANAGER:
                cout << "과장" << endl;
                break;
        }
    }
}

class NameCard
{
    char *name;
    char *company;
    char *phone;
    int position;

public:
    NameCard(char *_name, char *_company, char *_phone, int _position)
        :position(_position)
    {
        name = new char[strlen(_name) + 1];
        company = new char[strlen(_company) + 1];
        phone = new char[strlen(_phone) + 1];
        strcpy(name, _name);
        strcpy(company, _company);
        strcpy(phone, _phone);
    }
    void ShowNameCardInfo()
    {
        cout << "이름: " << name << endl;
        cout << "회사: " << company << endl;
        cout << "전화번호: " << phone << endl;
        cout << "직급: "; COMP_POS::ShowPositionInfo(position);
        cout << endl;
    }
    ~NameCard()
    {
        delete[] name;
        delete[] company;
        delete[] phone;
    }
};

int main()
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}