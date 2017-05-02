#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

/*
* Ŭ���� �̸� : AccountHandler
* Ŭ���� ���� : Control Class
*/

#include "Account.h"

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

#endif