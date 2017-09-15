#include <iostream>

using namespace std; 

//适配器Adapter继承自Target和Adaptee类，Adapter类需要重写Target类的Request函数，
//在Request中做适当的处理，调用Adaptee类的SepcificRequest。
//最终，Target实际调用的是Adaptee的SpecificRequest来完成Request的，
//完成适配；这种叫做类适配器。

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

