#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

/*
* 클래스 이름 : AccountHandler
* 클래스 유형 : Control Class
*/

#include "Account.h"
#include "BouncCheckArray.h"

class AccountHandler
{
private:
	BoundCheckArray<Account*> accArr;
	int accNum;
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();           //계좌 만들기
	void DepositMoney();          //돈 입금
	void WithdrawMoney();         //돈 출금
	void ShowAllAccInfo() const;  //모든 계좌정보 출력
	~AccountHandler();

	void MakeNormalAccount();     //보통예금계좌 만들기
	void MakeCreditAccount();     //신용신뢰계좌 만들기
};

#endif