#include <iostream>
#include <string>
#include <vector>

using namespace std;

//组合模式就是把一些现有的对象或者元素，经过组合后组成新的对象，
//新的对象提供内部方法，可以让我们很方便的完成这些元素或者内部对象的访问和操作。
//我们也可以把组合对象理解成一个容器，容器提供各种访问其内部对象或者元素的API，我们只需要使用这些方法就可以操作它了。
//Component：
//
//为组合中的对象声明接口；
//在适当的情况下，实现所有类共有接口的缺省行为；
//声明一个接口用于访问和管理Component的子组件。
//Leaf：
//
//在组合中表示叶节点对象，叶节点没有子节点；
//在组合中定义叶节点的行为。
//Composite：
//
//定义有子部件的那些部件的行为；
//存储子部件。
//Client：
//
//通过Component接口操作组合部件的对象。

class Component {
	public:
		Component(string name) : m_component(name) {}
		virtual ~Component() {}
		virtual void operation() = 0;
		virtual void add(Component*) = 0;
		virtual void remove(Component*) = 0;
		virtual Component* getChild(int) = 0;
		virtual string getName() {
			return m_component;
		}
		virtual void print() = 0;

	private:
		string m_component;
};

// Leaf node. 
class Leaf : public Component {
	public:
		Leaf(string name) : Component(name) {}
		void operation() {
			cout << "This is leaf operation" << endl;
		}
		void add(Component* pcomponent) {
		}
		void remove(Component* pcomponenet) {
		}
		Component* getChild(int index) {
			return NULL;
		}
		void print() {
		}
};

// Node. 
class Composite : public Component {
	public:
		Composite(string name) : Component(name) {
		}
		~Composite() {
			vector<Component*>::iterator it = m_vector.begin();
			while( it != m_vector.end() ) {
				if( *it != NULL ) {
					delete *it;
					*it = NULL;
				}
				m_vector.erase(it);
				it = m_vector.begin();
			}
		}

		void operation() {
			cout << "This is Composite operation" << endl;
		}

		void add(Component* pcomponent) {
			m_vector.push_back(pcomponent);
		}

		void remove(Component* pcomponent) {
			for( vector<Component*>::iterator it = m_vector.begin(); it != m_vector.end(); ++it ) {
				if( *it ==  pcomponent ) {
					delete *it;
					*it = NULL;
					m_vector.erase(it);
					break;
				}
			}
		}

		Component* getChild(int index) {
			if( index < 0 || index >= m_vector.size() ) {
				return NULL;
			}
			return m_vector[index];
		}

		void print() {
			for (vector<Component *>::iterator it = m_vector.begin(); it != m_vector.end(); ++it) {
				cout<<(*it)->getName()<<endl;
			}
		}

	private:
		vector<Component*> m_vector;
};

int main(){
	Component* pnode = new Composite("Beijing Head Office");
	Component* pnodeHr = new Leaf("Beijing Human Resouce Office");
	Component* pSubnodeSH = new Composite("ShangHai Office");
	Component* pSubnodeWH = new Composite("Wuhan Office");
	pnode -> add(pnodeHr);
	pnode -> add(pSubnodeSH);
	pnode -> add(pSubnodeWH);
	pnode -> print();
	if( pnode ->getChild(0) == pnodeHr ){
		cout << "ok" << endl;
	}
	Component* pnodeWhHr = new Leaf("Wuhan Human Resouce Office");
	Component* pnodeWhSa = new Leaf("Wuhan Sales Office");
	Component* pnodeWhPa = new Leaf("Wuhan Parchase Office");
	pSubnodeWH -> add(pnodeWhHr);
	pSubnodeWH -> add(pnodeWhSa);
	pSubnodeWH -> add(pnodeWhPa);
	pSubnodeWH ->print();
	pSubnodeWH->remove(pnodeWhPa);
	pSubnodeWH ->print();
	if( pnode != NULL ){
		delete pnode;
		pnode = NULL;
	}
	
	return 0;
}
