#ifndef __EXCEPTION_HANDLER_H__
#define __EXCEPTION_HANDLER_H__

#include<iostream>
#include<cstring>

class DepositException
{
private:
	int reqDep;  //요청 입금액
public:
	DepositException(int money) : reqDep(money)
	{}
	void ShowExceptionReason()
	{
		cout << "[예외 메시지: " << reqDep << "는 입금불가]" << endl;
	}
};

class WithdrawException
{
private:
	int balance;
public:
	WithdrawException(int money) : balance(money)
	{}
	void ShowExceptionReason()
	{
		cout << "[예외 메시지: 잔액부족 "<<balance<<']'<<endl;
	}
};


#endif