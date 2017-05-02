#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__


/*
* 클래스 이름 : Account
* 클래스 유형 : Entity Class
*/

class Account
{
private:
	int accId;      //계좌 ID
	int balance;    //잔고
	char *cusName;  //이름
public:
	Account(int myaccId, int mybalance, char *mycusName);
	Account(const Account& copy);
	int GetAccId() const;             //계좌 ID 반환
	virtual void Deposit(int money);  //입금
	int Withdraw(int money);          //출금
	virtual void ShowAccInfo() const; //계좌 정보 출력
	~Account();
};

#endif