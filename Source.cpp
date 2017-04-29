#include<iostream>
using namespace std;

void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAllAccInfo();

enum{ MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	int accId;
	int balance;
	char *cusName;
public:
	Account(int myaccId, int mybalance, char *mycusName);
	Account(const Account& copy);  //deep copy constructor
	int GetAccId() const;
	void Deposit(int money);
	void Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

Account* accArr[100];
int accNum = 0;

int main()
{
	while (1)
	{
		ShowMenu();
		int choice;
		cin >> choice;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			for (int i = 0; i < accNum; i++)
				delete accArr[i];
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

void ShowMenu()
{
	cout << "-------Menu-------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
}

void MakeAccount()
{
	int accId, balance;
	char cusName[100];
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> accId;
	cout << "이 름: ";
	cin >> cusName;
	cout << "입금액: ";
	cin >> balance;

	accArr[accNum++] = new Account(accId, balance, cusName);
}

void DepositMoney()
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

void WithdrawMoney()
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

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
	}
}

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

void Account::Withdraw(int money)
{
	if (balance < money)
	{
		cout << "잔액 부족!" << endl;
		return;
	}
	balance -= money;
}

void Account::ShowAccInfo() const
{
	cout << "계좌ID: " << accId << endl;
	cout << "이 름: " << cusName << endl;
	cout << "잔 액: " << balance << endl << endl;
}

Account::~Account()
{
	delete[] cusName;
}

