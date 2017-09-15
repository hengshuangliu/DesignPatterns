#include <iostream>

using namespace std;

// This mode would encounter error when this is multithread program.
class Singleton{
	public:
		static Singleton* getInstance(){
			if( m_instance == NULL ){
				m_instance = new Singleton(10);
			}
			return m_instance;
		}
		
		static void destoryInstance(){
			if( m_instance != NULL ){
				delete m_instance;
				m_instance = NULL;
			}
		}
		
		int getVariable(){
			return m_variable;
		}
	private:
		Singleton(int variable) : m_variable(variable){}
		int m_variable;
		static Singleton* m_instance;
};

Singleton* Singleton::m_instance = NULL;

int main(){
	Singleton* p = Singleton::getInstance();
	cout << p->getVariable() << endl;
	Singleton::destoryInstance();
	return 0;
} 
