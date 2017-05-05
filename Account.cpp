#include "Account.h"
#include "BankingCommonDecl.h"
#include "ExceptionHandler.h"
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
	if (money < 0)
	{
		DepositException expn(money);
		throw expn;
	}
	balance += money;
}

int Account::Withdraw(int money) 
{
	if (money>balance)
		throw WithdrawException(money-balance);
	balance -= money;
	return balance;
}

void Account::ShowAccInfo() const
{
	cout << "°èÁÂID: " << accId << endl;
	cout << "ÀÌ ¸§: " << cusName << endl;
	cout << "ÀÜ ¾×: " << balance << endl;
}

