#include <iostream>
#include <vector>

using namespace std;

typedef enum ProductTypeTag{
	TypeA,
	TypeB,
	TypeC
}PRODUCTTYPE;

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

class ProductC : public Product{
	public:
		void show(){
			cout << "This is product C" << endl;
		}
};

class Factory{
	public:
		Product* CreateProduct(PRODUCTTYPE product){
			switch(product){
				case TypeA: return new ProductA(); break;
				case TypeB: return new ProductB(); break;
				case TypeC: return new ProductC(); break;
				default: return NULL;
			}
				
		}
};

int main(){
	Factory fac;
	Product* pa = fac.CreateProduct(TypeA);
	if(pa != NULL){
		pa->show();
	}
	
	Product* pb = fac.CreateProduct(TypeB);
	if(pb != NULL){
		pb->show();
	}
	Product* pc = fac.CreateProduct(TypeC);
	if(pc != NULL){
		pc->show();
	}
	
	delete pa;
	pa = NULL;
	delete pb;
	pb = NULL;
	delete pc;
	pc = NULL;
	
	return 0;
}
