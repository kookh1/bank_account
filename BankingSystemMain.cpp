#include "AccountHandler.h"
#include "BankingCommonDecl.h"

int main()
{
	AccountHandler ah;
	while (1)
	{
		ah.ShowMenu();
		int choice;
		cin >> choice;

		switch (choice)
		{
		case MAKE:
			ah.MakeAccount();
			break;
		case DEPOSIT:
			ah.DepositMoney();
			break;
		case WITHDRAW:
			ah.WithdrawMoney();
			break;
		case INQUIRE:
			ah.ShowAllAccInfo();
			break;
		case EXIT:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "Illegal Selection" << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}
