#include <iostream>
#include <string>
#include <vector>

using namespace std;

//���ģʽ���ǰ�һЩ���еĶ������Ԫ�أ�������Ϻ�����µĶ���
//�µĶ����ṩ�ڲ����������������Ǻܷ���������ЩԪ�ػ����ڲ�����ķ��ʺͲ�����
//����Ҳ���԰���϶�������һ�������������ṩ���ַ������ڲ��������Ԫ�ص�API������ֻ��Ҫʹ����Щ�����Ϳ��Բ������ˡ�
//Component��
//
//Ϊ����еĶ��������ӿڣ�
//���ʵ�������£�ʵ�������๲�нӿڵ�ȱʡ��Ϊ��
//����һ���ӿ����ڷ��ʺ͹���Component���������
//Leaf��
//
//������б�ʾҶ�ڵ����Ҷ�ڵ�û���ӽڵ㣻
//������ж���Ҷ�ڵ����Ϊ��
//Composite��
//
//�������Ӳ�������Щ��������Ϊ��
//�洢�Ӳ�����
//Client��
//
//ͨ��Component�ӿڲ�����ϲ����Ķ���

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
