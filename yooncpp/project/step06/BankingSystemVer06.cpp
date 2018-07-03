/* 이자관련 계좌 클래스의 추가 */
#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;

// 프로그램 사용자의 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// 신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};

// 계좌의 종류
enum { NORMAL = 1, CREDIT = 2 };

/*
 * 클래스 이름: Account
 * 클래스 유형: Entity 클래스
 */
class Account {
private:
    int accID;      // 계좌번호
    int balance;    // 잔액
    char *cusName;  // 고객이름

public:
    Account(int ID, int money, char *name);
    Account(const Account& ref);

    int GetAccID() const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
    ~Account();
};

Account::Account(int ID, int money, char *name)
    : accID(ID), balance(money)
{
    cusName = new char[strlen(name) + 1];
    strcpy(cusName, name);
}

Account::Account(const Account& ref)
    : accID(ref.accID), balance(ref.balance)
{
    cusName = new char[strlen(ref.cusName) + 1];
    strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const { return accID; }

void Account::ShowAccInfo() const
{
    cout << "계좌ID: " << accID << endl;
    cout << "이 름: " << cusName << endl;
    cout << "잔 액: " << balance << endl << endl;
}

void Account::Deposit(int money)
{
    balance += money;
}

int Account::Withdraw(int money)    // 출금액 반환, 부족 시 0 반환
{
    if (balance < money)
        return 0;

    balance -= money;
    return money;
}

Account::~Account()
{
    delete[] cusName;
}

/*
 * 클래스 이름: NormalAccount
 * 클래스 유형: Entity 클래스
 */
class NormalAccount : public Account
{
private:
    int interRate;  // 이자율 %단위

public:
    NormalAccount(int ID, int money, char *name, int rate)
        : Account(ID, money, name), interRate(rate)
    { }
    virtual void Deposit(int money)
    {
        Account::Deposit(money);    // 원금추가
        Account::Deposit(money * (interRate / 100.0));  // 이자추가
    }
};

/*
 * 클래스 이름: HighCreditAccount
 * 클래스 유형: Entity 클래스
 */

class HighCreditAccount : public NormalAccount
{
private:
    int specialRate;

public:
    HighCreditAccount(int ID, int money, char *name, int rate, int special)
        : NormalAccount(ID, money, name, rate), specialRate(special)
    { }
    virtual void Deposit(int money)
    {
        NormalAccount::Deposit(money);  // 원금과 이자추가
        Account::Deposit(money * (specialRate / 100.0));    // 특별이자추가
    }
};

/*
 * 클래스 이름: AccountHandler
 * 클래스 유형: 컨트롤(Control) 클래스
 */
class AccountHandler
{
private:
    Account *accArr[100];   // Account 저장을 위한 배열
    int accNum;             // 저장된 Account 수

public:
    AccountHandler();
    void ShowMenu() const;
    void MakeAccount();
    void DepositMoney();
    void WithdrawMoney();
    void ShowAllAccInfo() const;
    ~AccountHandler();

protected:
    void MakeNormalAccount();
    void MakeCreditAccount();
};

void AccountHandler::ShowMenu() const
{
    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount()
{
    int sel;
    cout << "[계좌종류선택]" << endl;
    cout << "1. 보통예금계좌 ";
    cout << "2. 신용신뢰계좌 " << endl;
    cout << "선택: ";
    cin >> sel;

    if (sel == NORMAL)
        MakeNormalAccount();
    else
        MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount()
{
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;

    cout << "[보틍예금계좌 개설]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "이 름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << "이자율: "; cin >> interRate;
    cout << endl;

    accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount()
{
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;
    int creditLevel;

    cout << "[신용신뢰계좌 개설]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "이 름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << "이자율: "; cin >> interRate;
    cout << "신용등급(1toA, 2toB, 3toC): "; cin >> creditLevel;
    cout << endl;

    switch (creditLevel)
    {
        case 1:
            accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
            break;
        case 2:
            accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
            break;
        case 3:
            accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
            break;
    }
}

void AccountHandler::DepositMoney()
{
    int money;
    int id;
    cout << "[입   금]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "입금액: "; cin >> money;

    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == id)
        {
            accArr[i]->Deposit(money);
            cout << "입금완료" << endl << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void AccountHandler::WithdrawMoney()
{
    int money;
    int id;

    cout << "[출   금]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "출금액: "; cin >> money;

    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == id)
        {
            if (accArr[i]->Withdraw(money) == 0)
            {
                cout << "잔액부족" << endl << endl;
                return;
            }
            
            cout << "출금완료" << endl << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void AccountHandler::ShowAllAccInfo() const
{
    for (int i = 0; i < accNum; i++)
    {
        accArr[i]->ShowAccInfo();
    }
}

AccountHandler::AccountHandler()
    : accNum(0)
{ }

AccountHandler::~AccountHandler()
{
    for (int i = 0; i < accNum; i++)
        delete accArr[i];
}

/* 컨트롤 클래스 AccountHandler 중심의 main 함수 */
int main()
{
    AccountHandler manager;
    int choice;

    while (1)
    {
        manager.ShowMenu();
        cout << "선택: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case MAKE:
                manager.MakeAccount();
                break;
            case DEPOSIT:
                manager.DepositMoney();
                break;
            case WITHDRAW:
                manager.WithdrawMoney();
                break;
            case INQUIRE:
                manager.ShowAllAccInfo();
                break;
            case EXIT:
                return 0;
            default:
                cout << "Illegal selction.." << endl;
        }
    }
    return 0;
}