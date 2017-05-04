#ifndef HIGH_CREDIT_ACCOUNT
#define HIGH_CREDIT_ACCOUNT

#include "BankingCommonDecl.h"
#include "Account.h"
#include "String.h"

/*
* 클래스 이름 : HighCreditAccount
* 클래스 유형 : Entity Class
*/

class HighCreditAccount : public Account
{
private:
	int ratio;     //이율
	int addRatio;  //추가 이율
public:
	HighCreditAccount(int myaccId, int mybalance, String mycusName, int ratio, int addRatio)
		: Account(myaccId, mybalance, mycusName), ratio(ratio), addRatio(addRatio)
	{}
	void ShowAccInfo() const    //계좌정보 출력
	{
		Account::ShowAccInfo();
		cout << "이자율: " << ratio << endl;
		cout << "신용등급(1toA, 2toB, 3toC): " << addRatio << endl << endl;
	}
	void Deposit(int money)     //입금
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

		Account::Deposit(money + money*(ratio + num)*0.01);  //원금 + (원금 * (이율+추가이율)
	}
};

#endif