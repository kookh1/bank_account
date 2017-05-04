#ifndef __STRING_H__
#define __STRING_H__

#include "BankingCommonDecl.h"

/*
* 클래스 이름 : String
* 클래스 유형 : 문자열 처리 클래스
*/

class String
{
private:
	int len;
	char * str;
public:
	String();
	String(const char * s);
	String(const String& s);
	~String();
	String& operator= (const String& s);
	String& operator+= (const String& s);
	bool operator== (const String& s);
	String operator+ (const String& s);

	friend ostream& operator<< (ostream& os, const String& s);
	friend istream& operator>> (istream& is, String& s);
};

#endif