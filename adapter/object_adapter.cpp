#include <iostream>

using namespace std; 

//������Adapter��̳���Target�࣬ͬʱ����Adapter������һ��Adaptee���͵ĳ�Ա������
//Adapter����дRequest����ʱ����Request�У�ʹ��Adaptee���͵ĳ�Ա��������Adaptee��SpecificRequest����������������䣻
//���ֽ���������������

//��Adaptee������µĳ��󷽷�ʱ��Adapter�಻��Ҫ���κε�����Ҳ����ȷ�Ľ��ж�����
//����ʹ�ö�̬�ķ�ʽ��Adapter���е���Adaptee������ķ���

class Target{
	public:
		Target(){}
		virtual ~Target(){} 
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
class Adapter: public Target{
	public:
		Adapter(): m_adaptee(new Adaptee() ){}
		virtual ~Adapter(){
			if( m_adaptee != NULL ){
				delete m_adaptee;
				m_adaptee == NULL;
			}
		}
		void request(){
			m_adaptee->specialRequest();
		}
	private:
		Adaptee* m_adaptee;
};

int main(){
	Target* ta = new Adapter();
	ta->request();
	delete ta;
	ta = NULL;
	return 0;
} 

