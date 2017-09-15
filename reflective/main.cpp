#include <iostream>
#include "ClassFactory.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	BaseClass* bp = (BaseClass*)ClassFactory::getInstance().getClassByName("HelloClass");
	bp->registProperty();
	
	int pValue = 123456;
	bp->m_propertyMap["setm_pValue"](bp, &pValue);
	std::cout <<  *(((HelloClass*)bp)->getm_pValue()) << std::endl;
	bp->display();
	system("pause");
	return 0;
}
