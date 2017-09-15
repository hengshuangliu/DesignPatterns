#include <iostream>

using namespace std;

// This program provide a new way to avoid destorying the pointer manually.
//RAII: Resource Acquisition Is Initialization
//RAII�ı����������ö��������Դ���ѹ�����Դ������ת��Ϊ������������
//����Դ�Ļ�ȡ���ͷ������Ĺ����������Ӧ������
//�Ӷ�ȷ���ڶ��������������Դʼ����Ч����������ʱ��Դһ���ᱻ�ͷš�

class Singleton{
	public:
		static Singleton* getInstance(){
			return const_cast<Singleton*>(m_instance);  // remove const attribution.
		}
		
		int getVariable(){
			return m_variable;
		}
		
		class Gc{
			public:
				~Gc(){
					if(m_instance == NULL){
						cout << "destory all the resources" << endl;
						delete m_instance;
						m_instance = NULL;
					}
				}
		};
		static Gc gc;
		
	private:
		Singleton(int variable) : m_variable(variable){}
		int m_variable;
		static const Singleton* m_instance;
};

const Singleton* Singleton::m_instance = new Singleton(100);
Singleton::Gc Singleton::gc;

int main(){
	Singleton* p = Singleton::getInstance();
	cout << p->getVariable() << endl;
	
	return 0;
} 
