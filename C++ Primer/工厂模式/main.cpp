#include <iostream>

using namespace std;

//����Ь��
class Shoes {
public:
	virtual void show() = 0;
	virtual ~Shoes(){};
};

//�Ϳ�Ь��
class NikeShoes : public Shoes {
public:
	void show () {
		cout << "�����Ϳ���Ь���ҵĹ���Just do it" << endl;
	}
};

//�����·�
class Clothe {
public:
	virtual void show() = 0;
	virtual ~Clothe(){};
};

//���¿��·�
class UniqloClothe : public Clothe {
public:
	void show() {
		std::cout << "�������¿��·����ҵĹ���I am Uniqlo" << std::endl;	
	}
};

// ����ģ�幤����
// ģ�������AbstractProduct_t ��Ʒ������
template <class AbstractProduct_t>
class AbstractFactory {
public:
	virtual AbstractProduct_t* CreateProduct() = 0;
	virtual ~AbstractFactory(){};
	
};

// ����ģ�幤����
// ģ�������AbstractProduct_t ��Ʒ�����࣬ConcreteProduct_t ��Ʒ������
template <class AbstractProduct_t, class ConcreteProduct_t>
class ConcreteProdyct : public AbstractFactory<AbstractProduct_t> {
public:
	AbstractProduct_t *CreateProduct() {
		return new ConcreteProduct_t();
	}
};

int main() {
	// �����Ϳ�Ь�Ĺ�������
	ConcreteProdyct<Shoes, NikeShoes> concrete;
	// �����Ϳ�Ь����
	Shoes *n_shoes = concrete.CreateProduct();
	// ��ӡ�Ϳ�Ь�����
	n_shoes->show();

	// �������¿��·��Ĺ�������
	ConcreteProdyct<Clothe, UniqloClothe> concrete_prodyct;
	// �������¿��·�����
	Clothe * u_clothe = concrete_prodyct.CreateProduct();
	// ��ӡ���¿�����
	u_clothe->show();
	return 0;
}