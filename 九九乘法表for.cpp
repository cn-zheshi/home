#include <iostream>
int main()
{
	int b=1;
	for(int a=1; a<=9; ++a) {
		b=1;
		for(; a>=b; ++b) {
			std::cout<<a<<"*"<<b<<"="<<a*b<<"\t";
		}
		std::cout<<std::endl;
	}
	return 0;
}