#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

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
		MakeNormalAccount();
	else if (choice == CREDIT)
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount()
{
	cout << "[���뿹�ݰ��� ����]" << endl;
	int accId, balance, ratio;
	String cusName;

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

void AccountHandler::MakeCreditAccount()
{
	cout << "[���뿹�ݰ��� ����]" << endl;
	int accId, balance, ratio, addRatio;
	String cusName;

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

