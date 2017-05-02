#include<iostream>
#include<cstring>
using namespace std;

// 프로그램 사용자의 선택 메뉴
enum{ MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// 신용등급
enum{LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};

// 계좌의 종류
enum{NORMAL=1, CREDIT=2};

/*
 * 클래스 이름 : Account
 * 클래스 유형 : Entity Class
 */

class Account
{
private:
	int accId;      //계좌 ID
	int balance;    //잔고
	char *cusName;  //이름
public:
	Account(int myaccId, int mybalance, char *mycusName); 
	Account(const Account& copy);  
	int GetAccId() const;             //계좌 ID 반환
	virtual void Deposit(int money);  //입금
	int Withdraw(int money);          //출금
	virtual void ShowAccInfo() const; //계좌 정보 출력
	~Account();
};

//Account Member Function
Account::Account(int myaccId, int mybalance, char *mycusName)
	: accId(myaccId), balance(mybalance)
{
	cusName = new char[strlen(mycusName) + 1];
	strcpy(cusName, mycusName);
}

Account::Account(const Account& copy)  //deep copy constructor
	: accId(copy.accId), balance(copy.balance)
{
	cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
}

int Account::GetAccId() const
{
	return accId;
}

void Account::Deposit(int money)
{
	balance += money;
}

int Account::Withdraw(int money)
{
	if (balance < money)
	{
		cout << "잔액 부족!" << endl;
		return 0;
	}
	balance -= money;
	return balance;
}

void Account::ShowAccInfo() const
{
	cout << "계좌ID: " << accId << endl;
	cout << "이 름: " << cusName << endl;
	cout << "잔 액: " << balance << endl;
}

Account::~Account()
{
	delete[] cusName;
}



/*
 * 클래스 이름 : NormalAccount 
 * 클래스 유형 : Entity Class
 */

class NormalAccount : public Account
{
private:
	int ratio;  //이율
public:
	NormalAccount(int myaccId, int mybalance, char *mycusName, int ratio)
		: Account(myaccId, mybalance, mycusName), ratio(ratio)
	{}
	void ShowAccInfo() const     //계좌정보 출력
	{
		Account::ShowAccInfo();
		cout << "이자율: " << ratio << endl << endl;
	}
	void Deposit(int money)      //입금
	{
		Account::Deposit(money+money*ratio*0.01);  //원금 + (원금 * 이율)
	}
};


/*
* 클래스 이름 : HighCreditAccount
* 클래스 유형 : Entity Class
*/

class HighCreditAccount : public Account
{
private:
	int ratio;     //이율
	int addRatio;  //추가 이율
public:
	HighCreditAccount(int myaccId, int mybalance, char *mycusName, int ratio, int addRatio)
		: Account(myaccId, mybalance, mycusName), ratio(ratio), addRatio(addRatio)
	{}
	void ShowAccInfo() const    //계좌정보 출력
	{
		Account::ShowAccInfo();
		cout << "이자율: " << ratio << endl;
		cout << "신용등급(1toA, 2toB, 3toC): " << addRatio << endl << endl;
	}
	void Deposit(int money)     //입금
	{
		int num;
		if (addRatio == 1)
			num = LEVEL_A;   //7%
		else if (addRatio == 2)
			num = LEVEL_B;   //4%
		else if (addRatio == 3)
			num = LEVEL_C;   //2%
		Account::Deposit(money + money*(ratio+num)*0.01);  //원금 + (원금 * (이율+추가이율)
	}
};


/*
* 클래스 이름 : AccountHandler
* 클래스 유형 : Control Class
*/


class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu() const;       
	void MakeAccount();           //계좌 만들기
	void DepositMoney();          //돈 입금
	void WithdrawMoney();         //돈 출금
	void ShowAllAccInfo() const;  //모든 계좌정보 출력
	~AccountHandler();
};

//AccountHandler Member Function
AccountHandler::AccountHandler() : accNum(0)
{}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}


void AccountHandler::ShowMenu() const
{
	cout << "-------Menu-------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
}

void AccountHandler::MakeAccount()
{
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: ";
	int choice;
	cin >> choice;
	if (choice == NORMAL)
	{
		cout << "[보통예금계좌 개설]" << endl;
		int accId, balance, ratio;
		char cusName[100];

		cout << "계좌ID: ";
		cin >> accId;
		cout << "이 름: ";
		cin >> cusName;
		cout << "입금액: ";
		cin >> balance;
		cout << "이자율: ";
		cin >> ratio;

		accArr[accNum++] = new NormalAccount(accId, balance, cusName, ratio);
	}
	else if (choice == CREDIT)
	{
		cout << "[보통예금계좌 개설]" << endl;
		int accId, balance, ratio, addRatio;
		char cusName[100];

		cout << "계좌ID: ";
		cin >> accId;
		cout << "이 름: ";
		cin >> cusName;
		cout << "입금액: ";
		cin >> balance;
		cout << "이자율: ";
		cin >> ratio;
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> addRatio;
		accArr[accNum++] = new HighCreditAccount(accId, balance, cusName, ratio, addRatio);
	}

}

void AccountHandler::DepositMoney()
{
	cout << "[입 금]" << endl;
	cout << "계좌ID: ";
	int accId;
	cin >> accId;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == accId)
		{
			cout << "입금액: ";
			int money;
			cin >> money;
			accArr[i]->Deposit(money);
			break;
		}
	}
}

void AccountHandler::WithdrawMoney()
{
	cout << "[출 금]" << endl;
	cout << "계좌ID: ";
	int accId;
	cin >> accId;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == accId)
		{
			cout << "출금액: ";
			int money;
			cin >> money;
			accArr[i]->Withdraw(money);
			break;
		}
	}
}

void AccountHandler::ShowAllAccInfo() const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
	}
}



/*
 * main 함수
 */

int main()
{
	AccountHandler ah;
	while (1)
	{
		ah.ShowMenu();
		int choice;
		cin >> choice;

		switch (choice)
		{
		case MAKE:
			ah.MakeAccount();
			break;
		case DEPOSIT:
			ah.DepositMoney();
			break;
		case WITHDRAW:
			ah.WithdrawMoney();
			break;
		case INQUIRE:
			ah.ShowAllAccInfo();
			break;
		case EXIT:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "Illegal Selection" << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}





