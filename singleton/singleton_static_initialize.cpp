#include <iostream>

using namespace std;

// This mode would work normally when this is multithread program.
class Singleton{
	public:
		static Singleton* getInstance(){
			return const_cast<Singleton*>(m_instance);  // remove const attribution.
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
		static const Singleton* m_instance;
};
// static initializitioin would be finished in a single thread mode before going into main function.
const Singleton* Singleton::m_instance = new Singleton(100);

int main(){
	Singleton* p = Singleton::getInstance();
	cout << p->getVariable() << endl;
	Singleton::destoryInstance();
	return 0;
} 
