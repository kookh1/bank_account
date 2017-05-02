#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__


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

#endif