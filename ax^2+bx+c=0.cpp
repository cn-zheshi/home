#include <iostream>
#include <cmath>
int main()
{
	double a(0.0),b(0.0),c(0.0);
	std::cout<<"Enter a,b,c in ax^2+bx+c=0"<<std::endl;
	std::cin>>a>>b>>c;
	if(a!=0) {
		if(b*b-4*a*c>0) {

			double d=b*b-4*a*c;
			std::cout<<"Two"<<std::endl;
			std::cout<<(-b+d)/(2*a)<<std::endl;
			std::cout<<(-b-d)/(2*a)<<std::endl;
		} else {
			if(b*b-4*a*c==0) {
				std::cout<<"One"<<std::endl;
				std::cout<<(-b)/(2*a)<<std::endl;

			} else {
				std::cout<<"Error"<<std::endl;
			}
		}
	} else {
		std::cout<<"One"<<std::endl;
		std::cout<<(-c)/b<<std::endl;
	}
	return 0;
}