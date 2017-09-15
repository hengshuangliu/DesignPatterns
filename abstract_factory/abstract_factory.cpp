#include <iostream>

//�����󹤳����������ڲ�Ʒ����ṹ��ĳ��ϣ���Ҫ���ڴ���һ�飨�ж�����ࣩ��صĲ�Ʒ��
//Ϊ�����ṩ�����Ľӿڣ����ǵ����ж�������ɫʱ�����󹤳�����������ó���


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

