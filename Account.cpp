#include "Account.h"
#include "BankingCommonDecl.h"

//Account Member Function

Account::Account(int myaccId, int mybalance, String mycusName)
	: accId(myaccId), balance(mybalance)
{
	//cusName = new char[strlen(mycusName) + 1];
	//strcpy(cusName, mycusName);
	cusName = mycusName;
}

/*
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

Account& Account::operator=(const Account& copy) //대입 연산자 오버로딩
{
	this->accId = copy.accId;
	this->balance = copy.balance;
	this->cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
	
	return *this;
}

Account::~Account()
{
delete[] cusName;
}


*/

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

