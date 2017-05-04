#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

/*
* Ŭ���� �̸� : AccountHandler
* Ŭ���� ���� : Control Class
*/

#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
	BoundCheckAccountPtrArray accArr;
	int accNum;
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();           //���� �����
	void DepositMoney();          //�� �Ա�
	void WithdrawMoney();         //�� ���
	void ShowAllAccInfo() const;  //��� �������� ���
	~AccountHandler();

	void MakeNormalAccount();     //���뿹�ݰ��� �����
	void MakeCreditAccount();     //�ſ�ŷڰ��� �����
};

#endif