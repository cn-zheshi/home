#include <iostream>
int main()
{
	int a=1,b=1;
	while(a<10) {
		b=1;
		while(a>=b) {
			std::cout<<a<<"*"<<b<<"="<<a*b<<"\t";
			++b;
		}
		++a;
		std::cout<<std::endl;
	}
	return 0;
}