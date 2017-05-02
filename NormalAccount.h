#ifndef NORMAL_ACCOUNT_H__
#define NORMAL_ACCOUNT_H__

#include "BankingCommonDecl.h"
#include "Account.h"

/*
* Ŭ���� �̸� : NormalAccount
* Ŭ���� ���� : Entity Class
*/

class NormalAccount : public Account
{
private:
	int ratio;  //����
public:
	NormalAccount(int myaccId, int mybalance, char *mycusName, int ratio)
		: Account(myaccId, mybalance, mycusName), ratio(ratio)
	{}
	void ShowAccInfo() const     //�������� ���
	{
		Account::ShowAccInfo();
		cout << "������: " << ratio << endl << endl;
	}
	void Deposit(int money)      //�Ա�
	{
		Account::Deposit(money + money*ratio*0.01);  //���� + (���� * ����)
	}
};

#endif