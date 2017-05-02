#include<iostream>
#include<cstring>
using namespace std;

// ���α׷� ������� ���� �޴�
enum{ MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// �ſ���
enum{LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};

// ������ ����
enum{NORMAL=1, CREDIT=2};

/*
 * Ŭ���� �̸� : Account
 * Ŭ���� ���� : Entity Class
 */

class Account
{
private:
	int accId;      //���� ID
	int balance;    //�ܰ�
	char *cusName;  //�̸�
public:
	Account(int myaccId, int mybalance, char *mycusName); 
	Account(const Account& copy);  
	int GetAccId() const;             //���� ID ��ȯ
	virtual void Deposit(int money);  //�Ա�
	int Withdraw(int money);          //���
	virtual void ShowAccInfo() const; //���� ���� ���
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
		cout << "�ܾ� ����!" << endl;
		return 0;
	}
	balance -= money;
	return balance;
}

void Account::ShowAccInfo() const
{
	cout << "����ID: " << accId << endl;
	cout << "�� ��: " << cusName << endl;
	cout << "�� ��: " << balance << endl;
}

Account::~Account()
{
	delete[] cusName;
}



/*
 * Ŭ���� �̸� : NormalAccount 
 * Ŭ���� ���� : Entity Class
 */

class NormalAccount : public Account
{
private:
	int ratio;  //����
public:
	NormalAccount(int myaccId, int mybalance, char *mycusName, int ratio)
		: Account(myaccId, mybalance, mycusName), ratio(ratio)
	{}
	void ShowAccInfo() const     //�������� ���
	{
		Account::ShowAccInfo();
		cout << "������: " << ratio << endl << endl;
	}
	void Deposit(int money)      //�Ա�
	{
		Account::Deposit(money+money*ratio*0.01);  //���� + (���� * ����)
	}
};


/*
* Ŭ���� �̸� : HighCreditAccount
* Ŭ���� ���� : Entity Class
*/

class HighCreditAccount : public Account
{
private:
	int ratio;     //����
	int addRatio;  //�߰� ����
public:
	HighCreditAccount(int myaccId, int mybalance, char *mycusName, int ratio, int addRatio)
		: Account(myaccId, mybalance, mycusName), ratio(ratio), addRatio(addRatio)
	{}
	void ShowAccInfo() const    //�������� ���
	{
		Account::ShowAccInfo();
		cout << "������: " << ratio << endl;
		cout << "�ſ���(1toA, 2toB, 3toC): " << addRatio << endl << endl;
	}
	void Deposit(int money)     //�Ա�
	{
		int num;
		if (addRatio == 1)
			num = LEVEL_A;   //7%
		else if (addRatio == 2)
			num = LEVEL_B;   //4%
		else if (addRatio == 3)
			num = LEVEL_C;   //2%
		Account::Deposit(money + money*(ratio+num)*0.01);  //���� + (���� * (����+�߰�����)
	}
};


/*
* Ŭ���� �̸� : AccountHandler
* Ŭ���� ���� : Control Class
*/


class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu() const;       
	void MakeAccount();           //���� �����
	void DepositMoney();          //�� �Ա�
	void WithdrawMoney();         //�� ���
	void ShowAllAccInfo() const;  //��� �������� ���
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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
}

void AccountHandler::MakeAccount()
{
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "����: ";
	int choice;
	cin >> choice;
	if (choice == NORMAL)
	{
		cout << "[���뿹�ݰ��� ����]" << endl;
		int accId, balance, ratio;
		char cusName[100];

		cout << "����ID: ";
		cin >> accId;
		cout << "�� ��: ";
		cin >> cusName;
		cout << "�Աݾ�: ";
		cin >> balance;
		cout << "������: ";
		cin >> ratio;

		accArr[accNum++] = new NormalAccount(accId, balance, cusName, ratio);
	}
	else if (choice == CREDIT)
	{
		cout << "[���뿹�ݰ��� ����]" << endl;
		int accId, balance, ratio, addRatio;
		char cusName[100];

		cout << "����ID: ";
		cin >> accId;
		cout << "�� ��: ";
		cin >> cusName;
		cout << "�Աݾ�: ";
		cin >> balance;
		cout << "������: ";
		cin >> ratio;
		cout << "�ſ���(1toA, 2toB, 3toC): ";
		cin >> addRatio;
		accArr[accNum++] = new HighCreditAccount(accId, balance, cusName, ratio, addRatio);
	}

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



/*
 * main �Լ�
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





