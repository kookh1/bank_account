#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__

#include "Account.h"
typedef Account* ACCOUNT_PTR;

/*
* 클래스 이름 : BoundCheckAccountPtrArray
* 클래스 유형 : 배열 경계값 검사 클래스
*/

template <class T>
class BoundCheckArray
{
private:
	T *arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray& arr){}
	BoundCheckArray& operator=(const BoundCheckArray& arr){}

public:
	BoundCheckArray(int len=3);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};


template <class T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrlen(len)
{
	arr = new ACCOUNT_PTR[len];
}

template <class T>
T& BoundCheckArray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <class T>
T BoundCheckArray<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <class T>
int BoundCheckArray<T>::GetArrLen() const
{
	return arrlen;
}

template <class T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[] arr;
}

#endif