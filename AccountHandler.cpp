#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

//AccountHandler Member Function
AccountHandler::AccountHandler() : accNum(0)
{}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}


void AccountHandler::ShowMenu() const
{
	cout << "-------Menu-------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
}

void AccountHandler::MakeAccount()
{
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: ";
	int choice;
	cin >> choice;
	if (choice == NORMAL)
		MakeNormalAccount();
	else if (choice == CREDIT)
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount()
{
	cout << "[보통예금계좌 개설]" << endl;
	int accId, balance, ratio;
	String cusName;

	cout << "계좌ID: ";
	cin >> accId;
	cout << "이 름: ";
	cin >> cusName;
	cout << "입금액: ";
	cin >> balance;
	cout << "이자율: ";
	cin >> ratio;

	accArr[accNum++] = new NormalAccount(accId, balance, cusName, ratio);
}

void AccountHandler::MakeCreditAccount()
{
	cout << "[보통예금계좌 개설]" << endl;
	int accId, balance, ratio, addRatio;
	String cusName;

	cout << "계좌ID: ";
	cin >> accId;
	cout << "이 름: ";
	cin >> cusName;
	cout << "입금액: ";
	cin >> balance;
	cout << "이자율: ";
	cin >> ratio;
	cout << "신용등급(1toA, 2toB, 3toC): ";
	cin >> addRatio;
	accArr[accNum++] = new HighCreditAccount(accId, balance, cusName, ratio, addRatio);
}

void AccountHandler::DepositMoney()
{
	cout << "[입 금]" << endl;
	cout << "계좌ID: ";
	int accId;
	cin >> accId;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == accId)
		{
			cout << "입금액: ";
			int money;
			cin >> money;
			accArr[i]->Deposit(money);
			break;
		}
	}
}

void AccountHandler::WithdrawMoney()
{
	cout << "[출 금]" << endl;
	cout << "계좌ID: ";
	int accId;
	cin >> accId;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == accId)
		{
			cout << "출금액: ";
			int money;
			cin >> money;
			accArr[i]->Withdraw(money);
			break;
		}
	}
}

void AccountHandler::ShowAllAccInfo() const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
	}
}

