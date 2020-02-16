#include<iostream>
#include<vector>
#include<ctime>
class mc {
public:
	int cnt = 0;//表示100内的分解种类数
	std::vector<int> v;//表示其对应的x+y的可能值
};
int main() {
	time_t current = clock();
	int p[25] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,91,97 };//100以内质数的集合
	int s[200] = { 0 };//下标表示x+y的可能值
	mc m[9901];//下标表示xy的可能值
	//排除质数之和得到一个集合a
	for (int i = 0; i < 25; ++i) {
		for (int j = i + 1; j < 25; ++j) {
			s[p[i] + p[j]] = 1;
		}
	}
	//判断一个数在100内的分解数目
	for (int i = 2; i <= 100; ++i) {
		for (int j = i + 1; j <= 100; ++j) {
			++m[i * j].cnt;
		}
	}
	//计算a中数的分解的积可以表示哪些数，我们只需要只能被唯一表示的数的集合b
	for (int i = 7; i < 200; ++i) {//i<6的情况事实上不用考虑
		if (!s[i]) {
			for (int j = 2; 2 * j < i; ++j) {
				m[j * (i - j)].v.push_back(i);
			}
		}
	}
	for (int i = 0; i < 200; ++i) {
		s[i] = 0;
	}
	//只有当数集a能表示的数中只有唯一的数在数b中才满足题意
	for (int i = 0; i < 9901; ++i) {
		if (m[i].v.size() == 1) {
			s[m[i].v[0]]++;
		}
	}
	for (int i = 0; i < 200; ++i) {
		if (s[i] == 1) {
			for (int j = 0; j < 9901; ++j) {
				if (m[j].cnt != 1 && m[j].v.size() == 1 && m[j].v[0] == i) {
					std::cout << i << " " << j << std::endl;
				}
			}
		}
	}
	current = clock() - current;
	std::cout << (double)current / CLOCKS_PER_SEC;
	//得到数x+y为17
	//对应的xy为52
	//所以答案为x+y=17,xy=52,x=4,y=13
}