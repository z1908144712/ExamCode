#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^ 
******************************��ʼд����******************************/

int getMax(int num) {
	int t = num, a = 0, b = 0;
	while (((t & 1) == 0) && t !=0 ) {
		a++;
		t >>= 1;
	}
	while (t & 1) {
		b++;
		t >>= 1;
	}
	if (a + b == 31 || a + b == 0) {
		return -1;
	}
	int c = a + b;
	num |= (1<<c);
	num &= ~((1 << c) - 1);
	num |= (1 << (b - 1)) - 1;
	return num;
}

int getMin(int num) {
	int t = num, a = 0, b = 0;
	while (t & 1) {
		b++;
		t >>= 1;
	}
    if (t == 0) {
        return -1;
    }
	while ((t & 1) == 0 && t !=0 ) {
		a++;
		t >>= 1;
	}
	int c = a + b;
	num &= ((~0)<<(c + 1));
	int mask = (1 << (b + 1)) - 1;
	num |= mask << (a - 1);
	return num;
}

vector < int > findNumber(int num) {
    return {getMax(num), getMin(num)};
}
/******************************����д����******************************/


int main() {
    vector < int > res;

    int _num;
    cin >> _num;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    

    res = findNumber(_num);
    for(int res_i=0; res_i < res.size(); res_i++) {
    	cout << res[res_i] << endl;;
    }
    
    return 0;

}