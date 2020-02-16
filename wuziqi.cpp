#include <iostream>
#include <array>
#include <string>
#include <cctype>
char p(int a)
{
	if(a==0)
		return '0';
	if(a==1)
		return '1';
	if(a==2)
		return '2';
	if(a==3)
		return '3';
	if(a==4)
		return '4';
	if(a==5)
		return '5';
	if(a==6)
		return '6';
	if(a==7)
		return '7';
	if(a==8)
		return '8';
	if(a==9)
		return '9';
	if(a==10)
		return '0';
	if(a==11)
		return '1';
	if(a==12)
		return '2';
	if(a==13)
		return '3';
	if(a==14)
		return '4';

}
int main()
{
	std::cout<<"Please enter (x,y)"<<std::endl;
	std::array<char,225> arr;
	for(int a=0; a<225; ++a) {
		arr.at(a)='+';
	}
	for(int y=0; y<15; ++y) {
		for(int x=0; x<15; ++x) {
			if((x==0)&&(!(y==0||y==14))) {
				arr.at(y*15+x)=p(y);
			}
			if((x==14)&&(!(y==0||y==14))) {
				arr.at(y*15+x)='|';
			}
			if((y==0)&&(!(x==14))) {
				arr.at(y*15+x)=p(x);
			}
			if((y==14)&&(!(x==0||x==14))) {
				arr.at(y*15+x)='-';
			}
			if(y==0&&x==14) {
				arr.at(y*15+x)='x';
			}
			if(y==14&&x==0) {
				arr.at(y*15+x)='y';
			}
			if(y==14&&x==14) {
				arr.at(y*15+x)='#';
			}
			std::cout<<arr.at(y*15+x);
		}
		std::cout<<std::endl;
	}
	int x,y;
	int count=0;
	std::cout<<"P1 enter (x,y)"<<std::endl;
	while(count<169) {
		if(std::cin>>x>>y) {
			if(x<14&&x>0&&y<14&&y>0) {
				if(arr.at(y*15+x)=='+') {
					++count;
					if(count%2==1) {
						arr.at(y*15+x)='X';
					} else {
						arr.at(y*15+x)='O';
					}
					for(int y=0; y<15; ++y) {
						for(int x=0; x<15; ++x) {
							std::cout<<arr.at(y*15+x);
						}
						std::cout<<std::endl;
					}
				} else {
					if(count%2==0) {
						std::cout<<"P1 enter (x,y) again"<<std::endl;
					} else {
						std::cout<<"P2 enter (x,y) again"<<std::endl;
					}
					continue;
				}
			} else {
				if(count%2==0) {
					std::cout<<"P1 enter (x,y) again"<<std::endl;
				} else {
					std::cout<<"P2 enter (x,y) again"<<std::endl;
				}
				continue;
			}
			int a(0),b(0),d(0),e(0);
			while(y-a>=0&&y+b<15) {
				if(x-a>=0&&x+b<15) {
					if(a!=0) {
						if(((y-a==0||x-a==0)&&arr.at((y-a)*15+(x-a))==arr.at(y*15+x))) {
							++d;
						}
					}
					if(b!=0) {
						if((y+b==14||x+b==14)&&arr.at((y+b)*15+(x+b))==arr.at(y*15+x)) {
							++d;
						}
					}
					if(arr.at((y-a)*15+(x-a))==arr.at(y*15+x)&&y-a!=0&&x-a!=0) {
						++a;
					}
					if(arr.at((y+b)*15+(x+b))==arr.at(y*15+x)&&y+b!=14&&x+b!=14) {
						++b;
					}
					if(a+b+d>5) {
						if(count%2==1) {
							std::cout<<"P1 win"<<std::endl;
							return 0;
						} else {
							std::cout<<"P2 win"<<std::endl;
							return 0;
						}
					}
					if(e==20) {
						break;
					}
					++e;
				}
			}
			a=0;
			b=0;
			e=0;
			d=0;
			while(y-a>=0&&y+b<15) {
				if(x-a>=0&&x+b<15) {
					if(a!=0) {
						if(((y-a==0||x+a==14)&&arr.at((y-a)*15+(x-a))==arr.at(y*15+x))) {
							++d;
						}
					}
					if(b!=0) {
						if((y+b==14||x-b==0)&&arr.at((y+b)*15+(x-b))==arr.at(y*15+x)) {
							++d;
						}
					}
					if(arr.at((y-a)*15+(x+a))==arr.at(y*15+x)&&y-a!=0&&x+a!=14) {
						++a;
					}
					if(arr.at((y+b)*15+(x-b))==arr.at(y*15+x)&&y+b!=14&&x-b!=0) {
						++b;
					}
					if(a+b+d>5) {
						if(count%2==1) {
							std::cout<<"P1 win"<<std::endl;
							return 0;
						} else {
							std::cout<<"P2 win"<<std::endl;
							return 0;
						}
					}
					if(e==20) {
						break;
					}
					++e;
				}
			}
			a=0;
			b=0;
			e=0;
			d=0;
			while(y-a>=0&&y+a<15) {
				if(a!=0) {
					if((y-a==0&&arr.at((y-a)*15+x)==arr.at(y*15+x))) {
						++d;
					}
				}
				if(b!=0) {
					if(y+b==14&&arr.at((y+b)*15+x)==arr.at(y*15+x)) {
						++d;
					}
				}
				if(arr.at((y-a)*15+x)==arr.at(y*15+x)&&y-a!=0) {
					++a;
				}
				if(arr.at((y+b)*15+x)==arr.at(y*15+x)&&y+b!=14) {
					++b;
				}
				if(a+b+d>5) {
					if(count%2==1) {
						std::cout<<"P1 win"<<std::endl;
						return 0;
					} else {
						std::cout<<"P2 win"<<std::endl;
						return 0;
					}
				}
				if(e==20) {
					break;
				}
				++e;
			}
			a=0;
			b=0;
			d=0;
			e=0;
			while(x-a>=0&&x+a<15) {
				if(a!=0) {
					if((x-a==0&&arr.at(y*15+x-a)==arr.at(y*15+x))) {
						++d;
					}
				}
				if(b!=0) {
					if(x+b==14&&arr.at(y*15+x+b)==arr.at(y*15+x)) {
						++d;
					}
				}
				if(arr.at(y*15+x-a)==arr.at(y*15+x)&&x-a!=0) {
					++a;
				}
				if(arr.at(y*15+x+b)==arr.at(y*15+x)&&x+b!=14) {
					++b;
				}
				if(a+b+d>5) {
					if(count%2==1) {
						std::cout<<"P1 win"<<std::endl;
						return 0;
					} else {
						std::cout<<"P2 win"<<std::endl;
						return 0;
					}
				}
				if(e==20) {
					break;
				}
				++e;
			}
			if(count%2==1) {
				std::cout<<"P2 enter (x,y)"<<std::endl;
			} else {
				std::cout<<"P1 enter (x,y)"<<std::endl;
			}
		} else {
			if(count%2==0) {
				std::cout<<"P1 enter (x,y) again"<<std::endl;
			} else {
				std::cout<<"P2 enter (x,y) again"<<std::endl;
			}
		}
	}
	std::cout<<"No Player Can Win"<<std::endl;
	return 0;
}