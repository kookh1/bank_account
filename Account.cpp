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
		cout << "ÀÜ¾× ºÎÁ·!" << endl;
		return 0;
	}
	balance -= money;
	return balance;
}

void Account::ShowAccInfo() const
{
	cout << "°èÁÂID: " << accId << endl;
	cout << "ÀÌ ¸§: " << cusName << endl;
	cout << "ÀÜ ¾×: " << balance << endl;
}

