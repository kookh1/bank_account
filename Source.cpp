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

void ShowMenu()
{
	cout << "-------Menu-------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
}

void MakeAccount()
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

void DepositMoney()
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

void WithdrawMoney()
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

