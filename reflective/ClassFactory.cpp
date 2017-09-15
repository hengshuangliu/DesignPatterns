#include "ClassFactory.h"
#include <iostream>

// ClassFactory implement.
// static variable should be initialized in source file. 
// If you initialize it in the head file, you would encounter redefine error when you include this head file twice.
IMPLEMENT_CLASS(BaseClass)
ClassFactory::ClassFactory() {}
ClassFactory::~ClassFactory() {}

void* ClassFactory::getClassByName(std::string className) {
	std::map<std::string, createClass>::iterator it = m_classMap.find(className);
	if( it != m_classMap.end() ) {
		return it -> second();
	}
	return NULL;
}

void ClassFactory::registClass(std::string name, createClass method) {
	m_classMap.insert(std::pair<std::string, createClass >(name, method)) ;
}

ClassFactory& ClassFactory::getInstance(){
	static ClassFactory classFac;
	return classFac;
}

// DynamicClass implement.
DynamicClass::DynamicClass(std::string name, createClass method){
	ClassFactory::getInstance().registClass(name, method); 
}

// HelloClass implement.
IMPLEMENT_CLASS(HelloClass)
void* HelloClass::createInstance(){
	return new HelloClass();
}

void HelloClass::registProperty(){
	m_propertyMap.insert(std::pair<std::string, setValue>("setm_pValue", setm_pValue)) ;
}

void HelloClass::display(){
	std::cout << *getm_pValue() << std::endl;
}
