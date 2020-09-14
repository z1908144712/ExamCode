#include <iostream>

using namespace std;

//基类鞋子
class Shoes {
public:
	virtual void show() = 0;
	virtual ~Shoes(){};
};

//耐克鞋子
class NikeShoes : public Shoes {
public:
	void show () {
		cout << "我是耐克球鞋，我的广告语：Just do it" << endl;
	}
};

//基类衣服
class Clothe {
public:
	virtual void show() = 0;
	virtual ~Clothe(){};
};

//优衣库衣服
class UniqloClothe : public Clothe {
public:
	void show() {
		std::cout << "我是优衣库衣服，我的广告语：I am Uniqlo" << std::endl;	
	}
};

// 抽象模板工厂类
// 模板参数：AbstractProduct_t 产品抽象类
template <class AbstractProduct_t>
class AbstractFactory {
public:
	virtual AbstractProduct_t* CreateProduct() = 0;
	virtual ~AbstractFactory(){};
	
};

// 具体模板工厂类
// 模板参数：AbstractProduct_t 产品抽象类，ConcreteProduct_t 产品具体类
template <class AbstractProduct_t, class ConcreteProduct_t>
class ConcreteProdyct : public AbstractFactory<AbstractProduct_t> {
public:
	AbstractProduct_t *CreateProduct() {
		return new ConcreteProduct_t();
	}
};

int main() {
	// 构造耐克鞋的工厂对象
	ConcreteProdyct<Shoes, NikeShoes> concrete;
	// 创建耐克鞋对象
	Shoes *n_shoes = concrete.CreateProduct();
	// 打印耐克鞋广告语
	n_shoes->show();

	// 构造优衣库衣服的工厂对象
	ConcreteProdyct<Clothe, UniqloClothe> concrete_prodyct;
	// 创建优衣库衣服对象
	Clothe * u_clothe = concrete_prodyct.CreateProduct();
	// 打印优衣库广告语
	u_clothe->show();
	return 0;
}