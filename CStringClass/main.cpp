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
		//operator: '.'���� ȣ������ �ʰ� �ν��Ͻ��� �ٿ� ��� ȣ���� �� �ֵ��� �ϴ� Ű����
		//&: this�����͸� ��ȯ�ϱ� ���� ������
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