#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "Account.h"
typedef Account* ACCOUNT_PTR;

/*
* 클래스 이름 : BoundCheckAccountPtrArray
* 클래스 유형 : 배열 경계값 검사 클래스
*/

class BoundCheckAccountPtrArray
{
private:
	ACCOUNT_PTR *arr;
	int arrlen;

	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr){}
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr){}

public:
	BoundCheckAccountPtrArray(int len=3);
	ACCOUNT_PTR& operator[] (int idx);
	ACCOUNT_PTR operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckAccountPtrArray();
};

#endif