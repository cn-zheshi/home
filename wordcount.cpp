#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <cstddef>
#include <fstream>
int main()
{
	std::string s,v,t,sl;
	std::map<std::string,std::size_t> m;
	std::cin>>t;
	std::ifstream fire(t);
	while(std::getline(fire,s)) {
		for(auto &c:s) {
			c=tolower(c);
			if(std::ispunct(c)) {
				c='\t';
			}
		}
		sl=sl+s;
	}
	s=sl;
	int a(0);
	do {
		while(a!=s.size()&&std::isspace(s[a]))
			++a;
		int b=a;
		while(b!=s.size()&&!std::isspace(s[b]))
			++b;
		if(a!=b) {
			v=s.substr(a,b-a);
			++m[v];
		}
		a=b;
	} while(a!=s.size());
	int max(0);
	for(auto &d:m) {
		while(d.second>max) {
			max=d.second;
		}
	}
	for(int min(0); min<=max; ++min) {
		for(auto &x:m) {
			if(x.second==min) {
				std::cout<<x.first<<"\t"<<x.second<<std::endl;
			}
		}
	}
	return 0;
}