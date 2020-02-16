#include <iostream>
#include <array>
int main()
{
	std::array<char,9> a;
	for(int i=0; i<9; ++i) {
		a.at(i)='+';
	}
	for(int y=0; y<=2; ++y) {
		for(int x=0; x<=2; ++x) {
			std::cout<<a.at(3*y+x);
		}
		std::cout<<std::endl;
	}
	int x,y,count=0;
	while(count<9) {
		std::cin>>x>>y;
		if(x<=2&&y<=2) {
			if(a.at(y*3+x)=='+') {
				if(count%2==0)
					a.at(y*3+x)='X';
				else {
					if(count%2==1)
						a.at(y*3+x)='O';
					else
						continue;
				}
				++count;
			}
			for(int i=0; i<=2; ++i) {
				for (int v=0; v<=2; ++v) {
					std::cout<<a.at(i*3+v);
				}
				std::cout<<std::endl;
			}
			if((a.at(0)==a.at(3)&&a.at(3)==a.at(6)&&a.at(0)=='X')||(a.at(0)==a.at(1)&&a.at(1)==a.at(2)&&a.at(0)=='X')||(a.at(3)==a.at(4)&&a.at(4)==a.at(5)&&a.at(3)=='X')||(a.at(1)==a.at(4)&&a.at(4)==a.at(7)&&a.at(1)=='X')||(a.at(6)==a.at(7)&&a.at(7)==a.at(8)&&a.at(6)=='X')||(a.at(2)==a.at(5)&&a.at(5)==a.at(8)&&a.at(2)=='X')||(a.at(2)==a.at(4)&&a.at(4)==a.at(6)&&a.at(2)=='X')||(a.at(0)==a.at(4)&&a.at(4)==a.at(8)&&a.at(0)=='X')) {
				std::cout<<"player 1 win"<<std::endl;
				while(true){}
				return 0;
			}
			if((a.at(0)==a.at(3)&&a.at(3)==a.at(6)&&a.at(0)=='O')||(a.at(0)==a.at(1)&&a.at(1)==a.at(2)&&a.at(0)=='O')||(a.at(3)==a.at(4)&&a.at(4)==a.at(5)&&a.at(3)=='O')||(a.at(1)==a.at(4)&&a.at(4)==a.at(7)&&a.at(1)=='O')||(a.at(6)==a.at(7)&&a.at(7)==a.at(8)&&a.at(6)=='O')||(a.at(2)==a.at(5)&&a.at(5)==a.at(8)&&a.at(2)=='O')||(a.at(2)==a.at(4)&&a.at(4)==a.at(6)&&a.at(2)=='O')||(a.at(0)==a.at(4)&&a.at(4)==a.at(8)&&a.at(0)=='O')) {
				std::cout<<"player 2 win"<<std::endl;
				while(true){}
				return 0;
			}
		}
	}
	std::cout<<"no one win"<<std::endl;
	while(true){}
	return 0;
}