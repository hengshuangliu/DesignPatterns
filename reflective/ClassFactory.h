#ifndef CLASSFACTORY_H
#define CLASSFACTORY_H
#include <map>
#include <string>

typedef void* (*createClass)(void);   // function iterator.

class ClassFactory {
	public:
		~ClassFactory();

		void* getClassByName(std::string className);
		void registClass(std::string name, createClass method);

		static ClassFactory& getInstance();

	private:
		ClassFactory();
		std::map<std::string, createClass> m_classMap;
};

class DynamicClass {
	public:
		DynamicClass(std::string name, createClass method);
};

#define DECLARE_CLASS(className) \
	std::string className##Name ;        \
	static DynamicClass* m_##className##dc;

#define IMPLEMENT_CLASS(className) \
	DynamicClass* className::m_##className##dc = new DynamicClass(#className, className::createInstance);

class BaseClass;
typedef void (*setValue)(BaseClass*, void* v);

class BaseClass {
	private:
		DECLARE_CLASS(BaseClass)
	public:

		BaseClass() {};
		virtual ~BaseClass() {};
		static void* createInstance() {
			return new BaseClass();
		};
		virtual void registProperty() {};
		virtual void display() {};
		std::map<std::string, setValue> m_propertyMap;
};

#define SYNTHESIZE(classType, varType, varName)    \
	inline static void set##varName(BaseClass* cp, void* value){ \
		classType* tp = (classType*)cp ;                        \
		tp->varName = (varType)value ;                      \
	}                                                       \
	inline varType get##varName(void) const {                \
		return varName ;                                      \
	}


class HelloClass : public BaseClass {
	private:
		DECLARE_CLASS(HelloClass)
	public:
		SYNTHESIZE(HelloClass, int*, m_pValue)

		HelloClass() {}
		virtual ~HelloClass() {}

		static void* createInstance();
		virtual void registProperty();
		virtual void display();

	protected:
		int* m_pValue;
};


#endif
