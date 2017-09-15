#include <iostream>

//而抽象工厂方法适用于产品种类结构多的场合，主要用于创建一组（有多个种类）相关的产品，
//为它们提供创建的接口；就是当具有多个抽象角色时，抽象工厂便可以派上用场。


using namespace std;

class ProductA{
	public:
		virtual void show() = 0;
};

class ProductA1 : public ProductA{
	public:
		void show(){
			cout << "This is product A1" << endl;
		}
};

class ProductA2 : public ProductA{
	public:
		void show(){
			cout << "This is product A2" << endl;
		}
};

class ProductB{
	public:
		virtual void show() = 0;
};

class ProductB1 : public ProductB{
	public:
		void show(){
			cout << "This is product B1" << endl;
		}
};

class ProductB2 : public ProductB{
	public:
		void show(){
			cout << "This is product B2" << endl;
		}
};

class Factory{
	public:
		virtual ProductA* createProductA() = 0;
		virtual ProductB* createProductB() = 0;
};

class Factory1 : public Factory{
	public:
		ProductA* createProductA(){
			return new ProductA1();
		}
		
		ProductB* createProductB(){
			return new ProductB1();
		}
};

class Factory2 : public Factory{
	public:
		ProductA* createProductA(){
			return new ProductA2();
		}
		
		ProductB* createProductB(){
			return new ProductB2();
		}
};

int main(){
	Factory1 fac1;
	ProductA* pa1 = fac1.createProductA();
	pa1->show();
	ProductB* pb1 = fac1.createProductB();
	pb1->show();
	
	Factory2 fac2;
	ProductA* pa2 = fac1.createProductA();
	pa2->show();
	ProductB* pb2 = fac1.createProductB();
	pb2->show();
	
	if(pa1 != NULL ){
		delete pa1;
		pa1 = NULL;
	}
	
	if(pa1 != NULL ){
		delete pb1;
		pb1 = NULL;
	}
	
	if(pa1 != NULL ){
		delete pa2;
		pa2 = NULL;
	}
	
	if(pa1 != NULL ){
		delete pb2;
		pb2 = NULL;
	}
	
	return 0;
} 

