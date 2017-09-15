#include <iostream>

//工厂方法模式的意义是定义一个创建产品对象的工厂接口，将实际创建工作推迟到子类当中;
//核心工厂类不再负责产品的创建，这样核心类成为一个抽象工厂角色，仅负责具体工厂子类必须实现的接口，
//这样进一步抽象化的好处是使得工厂方法模式可以使系统在不修改具体工厂角色的情况下引进新的产品。

using namespace std;

class Product{
	public:
		virtual void show() = 0;
};

class ProductA : public Product{
	public:
		void show(){
			cout << "This is product A" << endl;
		}
};

class ProductB : public Product{
	public:
		void show(){
			cout << "This is product B" << endl;
		}
};

class Factory{
	public:
		virtual Product* CreateProduct() =  0;
};

class FactoryA : public Factory{
	public:
		Product* CreateProduct(){
			return new ProductA();
		}
};

class FactoryB : public Factory{
	public:
		Product* CreateProduct(){
			return new ProductB();
		}
};

int main(){
	Factory* facA = new FactoryA();
	Product* proA = facA->CreateProduct();
	proA->show();
	
	Factory* facB = new FactoryB();
	Product* proB = facB->CreateProduct();
	proB->show();
	
	if(facA != NULL ){
		delete facA;
		facA = NULL; 
	} 
	
	if(facB != NULL ){
		delete facB;
		facB = NULL; 
	}
	
	if(proA != NULL ){
		delete proA;
		proA = NULL; 
	}
	
	if(proB != NULL ){
		delete proB;
		proB = NULL; 
	}
	
	return 0;
} 
