#ifndef NORMAL_ACCOUNT_H__
#define NORMAL_ACCOUNT_H__

#include "BankingCommonDecl.h"
#include "Account.h"
#include "String.h"

/*
* 클래스 이름 : NormalAccount
* 클래스 유형 : Entity Class
*/

class NormalAccount : public Account
{
private:
	int ratio;  //이율
public:
	NormalAccount(int myaccId, int mybalance, String mycusName, int ratio)
		: Account(myaccId, mybalance, mycusName), ratio(ratio)
	{}
	void ShowAccInfo() const     //계좌정보 출력
	{
		Account::ShowAccInfo();
		cout << "이자율: " << ratio << endl << endl;
	}
	virtual void Deposit(int money)   //입금
	{
		if (money < 0)
		{
			DepositException expn(money);
			throw expn;
		}
		Account::Deposit(money + money*ratio*0.01);  //원금 + (원금 * 이율)
	}
};

#endif