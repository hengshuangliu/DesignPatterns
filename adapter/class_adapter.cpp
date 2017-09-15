#include <iostream>

using namespace std; 

//������Adapter�̳���Target��Adaptee�࣬Adapter����Ҫ��дTarget���Request������
//��Request�����ʵ��Ĵ�������Adaptee���SepcificRequest��
//���գ�Targetʵ�ʵ��õ���Adaptee��SpecificRequest�����Request�ģ�
//������䣻���ֽ�������������

class Target{
	public:
		virtual void request(){
			cout << "This is Target: request" << endl;
		}
};

// adaptee
class Adaptee{
	public:
		void specialRequest(){
			cout << "This is Adaptee: specialRequest" << endl;
		} 
};

// adapter
class Adapter: public Target, Adaptee{
	public:
		void request(){
			Adaptee::specialRequest();
		} 
};

int main(){
	Target* ta = new Adapter();
	ta->request();
	delete ta;
	ta = NULL;
	return 0;
} 

