#include <iostream>

using namespace std; 

//适配器Adapter类继承自Target类，同时，在Adapter类中有一个Adaptee类型的成员变量；
//Adapter类重写Request函数时，在Request中，使用Adaptee类型的成员变量调用Adaptee的SpecificRequest函数，最终完成适配；
//这种叫做对象适配器。

//当Adaptee中添加新的抽象方法时，Adapter类不需要做任何调整，也能正确的进行动作；
//可以使用多态的方式在Adapter类中调用Adaptee类子类的方法

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

