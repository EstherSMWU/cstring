#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

class String {
private:
	char* m_p;
	int m_length;

public:
	String() {
		m_p = nullptr;
		m_length = 0;
	}
	String(const char* str) {
		m_length = strlen(str);

		m_p = (char*)malloc(sizeof(char) * (m_length + 1));
		strcpy(m_p, str);
	}
	String(const String& src) {
		m_p = new char[src.m_length + 1];
		strcpy(m_p, src.m_p);
		m_length = src.m_length;
	}

	~String() {
		delete m_p;
	}


	int length() const {
		return m_length;
	}

	String& operator=(const char* str) {
		//operator: '.'으로 호출하지 않고 인스턴스에 붙여 적어도 호출할 수 있도록 하는 키워드
		//&: this포인터를 반환하기 위한 참조자. str1 = str2 = "sentence" 처럼 한 인스턴스에 대입한 결과를 다른 인스턴스에 그대로 줘야 하는 경우를 위함
		delete m_p;

		m_length = strlen(str);
		m_p = new char[m_length + 1];
		strcpy(m_p, str);

		return *this;
	}

	String& operator=(const String& src) {
		delete m_p;

		m_p = new char[src.m_length + 1];
		strcpy(m_p, src.m_p);
		m_length = src.m_length;

		return *this;
	}
	/*
	bool operator==(const String& src) {
		return strcmp(this->m_p, src.m_p) == 0;
	}
	*/

	void print() const {
		for (int i = 0; i < m_length; i++) printf("%c", m_p[i]);
	}


	friend bool operator==(String& left, String& right);

};


class ArrayString {
public:
	String m_data[];
	void Insert(String s);
	String Get(int Index);
	void Delete(int Index);

};

bool operator==(String& left, String& right) {
	return strcmp(left.m_p, right.m_p) == 0;
}

int main() {
	String myString("Implementing ");
	myString.print();
	myString = "C++ string\n";
	myString.print();

	myString = "wow\n";
	String s1 = myString;
	s1.print();
	String s2(myString);
	s2.print();

	if (s1 == s2) printf("%s", "s1 and s2 are the same");
	
	return 0;
}