#include <iostream>

using namespace std;

// This program provide a new way to avoid destorying the pointer manually.
//RAII: Resource Acquisition Is Initialization
//RAII的本质内容是用对象代表资源，把管理资源的任务转化为管理对象的任务，
//将资源的获取和释放与对象的构造和析构对应起来，
//从而确保在对象的生存期内资源始终有效，对象销毁时资源一定会被释放。

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
