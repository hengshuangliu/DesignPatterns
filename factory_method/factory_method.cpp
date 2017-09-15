#include <iostream>

//��������ģʽ�������Ƕ���һ��������Ʒ����Ĺ����ӿڣ���ʵ�ʴ��������Ƴٵ����൱��;
//���Ĺ����಻�ٸ����Ʒ�Ĵ����������������Ϊһ�����󹤳���ɫ����������幤���������ʵ�ֵĽӿڣ�
//������һ�����󻯵ĺô���ʹ�ù�������ģʽ����ʹϵͳ�ڲ��޸ľ��幤����ɫ������������µĲ�Ʒ��

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
