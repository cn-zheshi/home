#include<iostream>
#include<vector>
#include<ctime>
class mc {
public:
	int cnt = 0;//��ʾ100�ڵķֽ�������
	std::vector<int> v;//��ʾ���Ӧ��x+y�Ŀ���ֵ
};
int main() {
	time_t current = clock();
	int p[25] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,91,97 };//100���������ļ���
	int s[200] = { 0 };//�±��ʾx+y�Ŀ���ֵ
	mc m[9901];//�±��ʾxy�Ŀ���ֵ
	//�ų�����֮�͵õ�һ������a
	for (int i = 0; i < 25; ++i) {
		for (int j = i + 1; j < 25; ++j) {
			s[p[i] + p[j]] = 1;
		}
	}
	//�ж�һ������100�ڵķֽ���Ŀ
	for (int i = 2; i <= 100; ++i) {
		for (int j = i + 1; j <= 100; ++j) {
			++m[i * j].cnt;
		}
	}
	//����a�����ķֽ�Ļ����Ա�ʾ��Щ��������ֻ��Ҫֻ�ܱ�Ψһ��ʾ�����ļ���b
	for (int i = 7; i < 200; ++i) {//i<6�������ʵ�ϲ��ÿ���
		if (!s[i]) {
			for (int j = 2; 2 * j < i; ++j) {
				m[j * (i - j)].v.push_back(i);
			}
		}
	}
	for (int i = 0; i < 200; ++i) {
		s[i] = 0;
	}
	//ֻ�е�����a�ܱ�ʾ������ֻ��Ψһ��������b�в���������
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
	//�õ���x+yΪ17
	//��Ӧ��xyΪ52
	//���Դ�Ϊx+y=17,xy=52,x=4,y=13
}