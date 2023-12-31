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
	String(char* str) {
		m_length = strlen(str);

		m_p = (char*)malloc(sizeof(char)*(m_length + 1));
		strcpy(m_p, str);
	}
	~String() {
		delete m_p;
	}
	
	String& operator=(char* str) {
		//operator: '.'으로 호출하지 않고 인스턴스에 붙여 적어도 호출할 수 있도록 하는 키워드
		//&: this포인터를 반환하기 위한 참조자
		delete m_p;
		m_length = strlen(str);
		m_p = new char[m_length + 1];
		strcpy(m_p, str);
		return *this;
	}

	int length() const {
		return m_length;
	}

	void print() const {
		for (int i = 0; i < m_length; i++) printf("%c", m_p[i]);
	}
};

int main() {
	String myString("Implementing");
	myString.print();
	myString = "C++ string";
	myString.print();

	return 0;
}