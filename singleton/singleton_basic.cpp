#include <iostream>

using namespace std;
//  This mode don't consider that the instance should be destoryed. 
class Singleton{
	public:
		static Singleton* getInstance(){
			static Singleton singelInstance(0);
			return &singelInstance;
		}
		
		int getVariable(){
			return m_variable;
		}
	private:
		Singleton(int variable) : m_variable(variable){}
		int m_variable;
};

int main(){
	Singleton* p = Singleton::getInstance();
	cout << p->getVariable() << endl;
	return 0;
} 
