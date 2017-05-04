#include "Account.h"
#include "BankingCommonDecl.h"

//Account Member Function

Account::Account(int myaccId, int mybalance, String mycusName)
	: accId(myaccId), balance(mybalance)
{
	cusName = mycusName;
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

