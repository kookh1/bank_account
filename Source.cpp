#include<iostream>
#include<cstring>
using namespace std;

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


class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
	~AccountHandler();
};



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
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "Illegal Selection" << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}



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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
}

void AccountHandler::MakeAccount()
{
	int accId, balance;
	char cusName[100];
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> accId;
	cout << "�� ��: ";
	cin >> cusName;
	cout << "�Աݾ�: ";
	cin >> balance;

	accArr[accNum++] = new Account(accId, balance, cusName);
}

void AccountHandler::DepositMoney()
{
	cout << "[�� ��]" << endl;
	cout << "����ID: ";
	int accId;
	cin >> accId;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == accId)
		{
			cout << "�Աݾ�: ";
			int money;
			cin >> money;
			accArr[i]->Deposit(money);
			break;
		}
	}
}

void AccountHandler::WithdrawMoney()
{
	cout << "[�� ��]" << endl;
	cout << "����ID: ";
	int accId;
	cin >> accId;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == accId)
		{
			cout << "��ݾ�: ";
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
		cout << "�ܾ� ����!" << endl;
		return;
	}
	balance -= money;
}

void Account::ShowAccInfo() const
{
	cout << "����ID: " << accId << endl;
	cout << "�� ��: " << cusName << endl;
	cout << "�� ��: " << balance << endl << endl;
}

Account::~Account()
{
	delete[] cusName;
}

