#ifndef HIGH_CREDIT_ACCOUNT
#define HIGH_CREDIT_ACCOUNT

#include "BankingCommonDecl.h"
#include "Account.h"
#include "String.h"

/*
* Ŭ���� �̸� : HighCreditAccount
* Ŭ���� ���� : Entity Class
*/

class HighCreditAccount : public Account
{
private:
	int ratio;     //����
	int addRatio;  //�߰� ����
public:
	HighCreditAccount(int myaccId, int mybalance, String mycusName, int ratio, int addRatio)
		: Account(myaccId, mybalance, mycusName), ratio(ratio), addRatio(addRatio)
	{}
	void ShowAccInfo() const    //�������� ���
	{
		Account::ShowAccInfo();
		cout << "������: " << ratio << endl;
		cout << "�ſ���(1toA, 2toB, 3toC): " << addRatio << endl << endl;
	}
	void Deposit(int money)     //�Ա�
	{
		int num = 0;
		switch (addRatio)
		{
		case 1:
			num = LEVEL_A;   //7%
			break;
		case 2:
			num = LEVEL_B;   //4%
			break;
		case 3:
			num = LEVEL_C;   //2%
			break;
		}

		Account::Deposit(money + money*(ratio + num)*0.01);  //���� + (���� * (����+�߰�����)
	}
};

#endif