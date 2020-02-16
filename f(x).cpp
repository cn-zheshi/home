#include <iostream>
#include <cmath>
int main()
{
	double a,b,c,d,e,f;
	std::cin>>a>>b>>c>>d>>e>>f;
	std::cout<<"Please enter a,b,c (start,end) and step \n a,b,c is the a,b,c in ax^2+bx+c "<<std::endl;
	for(; d<=e; d+=f) {
		std::cout<<a*d*d+b*d+c<<std::endl;
	}
	return 0;
}