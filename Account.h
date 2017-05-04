#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

/*
* Ŭ���� �̸� : Account
* Ŭ���� ���� : Entity Class
*/

class Account
{
private:
	int accId;      //���� ID
	int balance;    //�ܰ�
	String cusName;
public:
	Account(int myaccId, int mybalance, String mycusName);  //������ 

	int GetAccId() const;             //���� ID ��ȯ
	virtual void Deposit(int money);  //�Ա�
	int Withdraw(int money);          //���
	virtual void ShowAccInfo() const; //���� ���� ���
};

#endif