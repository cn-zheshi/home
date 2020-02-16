#include <iostream>
#include <cmath>
#include <string>
int p()
{
	double a(0.0),b(0.0);
	std::string c;
	std::cout<<"Please enter number sign number"<<std::endl;
	std::cin>>a>>c>>b;
	if(c=="+")
		std::cout<<a+b<<std::endl;
	if(c=="-")
		std::cout<<a-b<<std::endl;
	if(c=="*")
		std::cout<<a*b<<std::endl;
	if(c=="/")
		std::cout<<a/b<<std::endl;
	if(c=="^")
		std::cout<<std::pow(a,b)<<std::endl;
	if(c=="sin")
		std::cout<<a*std::sin(b)<<std::endl;
	if(c=="cos")
		std::cout<<a*std::cos(b)<<std::endl;
	if(c=="tan")
		std::cout<<a*std::tan(b)<<std::endl;
	return 0;
}
int main()
{
	char a;
	while(true) {
		p();
	}
}