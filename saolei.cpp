#define DARWIN_FORCE_BUILTIN
#define DARWIN_DISABLE_LOG
#include "./darwin/headers/darwin.hpp"
#include <string>
#include <cctype>
#include <iostream>
#include <vector>
#include <utility>
#include <random>
#include <ctime>
darwin::picture paint;
darwin::colors cao(int a)
{
	if(a==0)
		return darwin::colors::white;
	if(a==1)
		return darwin::colors::green;
	if(a==-1)
		return darwin::colors::red;
}
char pi(int a)
{
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
		return '#';
	if(a==0)
		return ' ';
}
std::vector<std::pair<char,char>> zhankai(std::vector<std::pair<char,char>> a,std::vector<int> b,unsigned c,unsigned d)
{
	int hhhh=0;
	bool aaa=true;
	while(aaa) {
		int vall=0;
		for(int i=0; i<d;) {
			for(int v=0; v<c; ++v) {
				if(a[i*c+v].second==' ') {
					if(i>=1)
						if(a[(i-1)*c+v].first=='c') {
							a[(i-1)*c+v].first='o';
							a[(i-1)*c+v].second=pi(b[(i-1)*c+v]);
							++vall;
						}
					if(v>=1)
						if(a[i*c+v-1].first=='c') {
							a[i*c+v-1].first='o';
							a[i*c+v-1].second=pi(b[i*c+v-1]);
							++vall;
						}
					if(v>=1&&i>=1)
						if(a[(i-1)*c+v-1].first=='c') {
							a[(i-1)*c+v-1].first='o';
							a[(i-1)*c+v-1].second=pi(b[(i-1)*c+v-1]);
							++vall;
						}
					if(i>=1&&v<(c-1))
						if(a[(i-1)*c+v+1].first=='c') {
							a[(i-1)*c+v+1].first='o';
							a[(i-1)*c+v+1].second=pi(b[(i-1)*c+v+1]);
							++vall;
						}
					if(i<(d-1)&&v>=1)
						if(a[(i+1)*c+v-1].first=='c') {
							a[(i+1)*c+v-1].first='o';
							a[(i+1)*c+v-1].second=pi(b[(i+1)*c+v-1]);
							++vall;
						}
					if(i<(d-1))
						if(a[(i+1)*c+v].first=='c') {
							a[(i+1)*c+v].first='o';
							a[(i+1)*c+v].second=pi(b[(i+1)*c+v]);
							++vall;
						}
					if(v<(c-1))
						if(a[i*c+v+1].first=='c') {
							a[i*c+v+1].first='o';
							a[i*c+v+1].second=pi(b[i*c+v+1]);
							++vall;
						}
					if(i<(d-1)&&v<(c-1))
						if(a[(i+1)*c+v+1].first=='c') {
							a[(i+1)*c+v+1].first='o';
							a[(i+1)*c+v+1].second=pi(b[(i+1)*c+v+1]);
							++vall;
						}
				}
			}
			++i;
		}
		if(hhhh==vall)
			aaa=false;
		hhhh=vall;
	}
	return a;
}
int sf(std::vector<std::pair<char,char>>& a,std::vector<int> b,unsigned c,unsigned d,unsigned e)
{
	int val=0;
	int ll=0;
	for(int i=0; i<d; ++i) {
		for(int v=0; v<c; ++v) {
			if(a[i*c+v].second=='#') {
				for(int y=0; y<d; ++y) {
					for(int x=0; x<c; ++x) {
						if(b[y*c+x]==9) {
							a[y*c+x].first='o';
							a[y*c+x].second='#';
						}
					}
				}
				return -1;
			}
			if(a[i*c+v].second=='s') {
				if(a[i*c+v].second=='s'&&b[i*c+v]==9)
					++ll;
				++val;
				if(ll==e&&val==ll)
					return 1;
			}
		}
	}
	int valll=0;
	for(int i=0; i<c*d; ++i)
		if(a[i].first!='c'&&a[i].first!='s')
			++valll;
	if(valll>=(c*d-e))
		return 1;
	return 0;
}
int saolei(unsigned a,unsigned b,int c)
{
	darwin::runtime.load("./darwin.module");
	auto pic=darwin::runtime.get_drawable();
	darwin::pixel p(' ', true,false, darwin::colors::blue,darwin::colors::white);
	darwin::pixel wz('*', true,false, darwin::colors::blue,darwin::colors::white);
	darwin::pixel die(' ', true,false, darwin::colors::red,darwin::colors::red);
	darwin::pixel win(' ', true,false, darwin::colors::green,darwin::colors::green);
	darwin::sync_clock clock(30);
	unsigned longth(a),weith(b);
	int leishu(0),cao1(0),x(0),y(0),ls(c);
	int xll,yll;
	bool lose=true;
	std::vector<int> bk(longth*weith,0);
	std::vector<std::pair<char,char>> ks(longth*weith);
	std::string str0="Please use \"wsad\" to move";
	std::string str1="\"j\" to open \"k\" to unsign \"l\" to sign";
	for(unsigned i=0; i<(longth*weith); ++i) {
		bk[i]=0;
		ks[i].first='c';//c->close o->open s->sign
		ks[i].second='+';
	}
	while(lose) {
		clock.reset();
		darwin::runtime.fit_drawable();
		for(int i=0; i<weith; ++i) {
			for(int v=0; v<longth; ++v) {
				p.set_char(ks[i*longth+v].second);
				paint.draw_pixel(v,i,p);
			}
		}
		paint.draw_pixel(x,y,wz);
		pic->draw_picture(0.5*(pic->get_width()-paint.get_width()),0.5*(pic->get_height()-paint.get_height()),paint);
		pic->draw_string(0,pic->get_height()-2,str0,darwin::pixel(' ',true,false,darwin::colors::blue,darwin::colors::white));
		pic->draw_string(0,pic->get_height()-1,str1,darwin::pixel(' ',true,false,darwin::colors::blue,darwin::colors::white));
		if(darwin::runtime.is_kb_hit()) {
			switch(std::tolower(darwin::runtime.get_kb_hit())) {
			case'w':
				if(y>0)
					--y;
				break;
			case's':
				if(y+1<weith)
					++y;
				break;
			case'a':
					if(x>0)
						--x;
				break;
			case'd':
					if(x+1<longth)
						++x;
				break;
			case'j':
				xll=x;
				yll=y;
				ks[yll*longth+xll].first='o';
				lose=false;
				break;
			}
		}
		darwin::runtime.update_drawable();
		clock.sync();
	}
	lose=true;
	while(true) {
		int x1,y1;
		x1=darwin::rand<int>(0,longth-1);
		y1=darwin::rand<int>(0,weith-1);
		if(x1==xll&&y1==yll)
			continue;
		if(bk[longth*y1+x1]==0) {
			bk[longth*y1+x1]=9;
			++leishu;
		}
		if(leishu==ls)
			break;
	}
	for(int i=0; i<weith; ++i) {
		for(int v=0; v<longth; ++v) {
			if(bk[i*longth+v]!=9) {
				if(i>=1)
					if(bk[(i-1)*longth+v]==9)
						++bk[i*longth+v];
				if(v>=1)
					if(bk[i*longth+v-1]==9)
						++bk[i*longth+v];
				if(v>=1&&i>=1)
					if(bk[(i-1)*longth+v-1]==9)
						++bk[i*longth+v];
				if(i>=1&&v<(longth-1))
					if(bk[(i-1)*longth+v+1]==9)
						++bk[i*longth+v];
				if(i<(weith-1)&&v>=1)
					if(bk[(i+1)*longth+v-1]==9)
						++bk[i*longth+v];
				if(i<(weith-1))
					if(bk[(i+1)*longth+v]==9)
						++bk[i*longth+v];
				if(v<(longth-1))
					if(bk[i*longth+v+1]==9)
						++bk[i*longth+v];
				if(i<(weith-1)&&v<(longth-1))
					if(bk[(i+1)*longth+v+1]==9)
						++bk[i*longth+v];
			}
		}
	}
	ks[yll*longth+xll].first='o';
	ks[yll*longth+xll].second=pi(bk[yll*longth+xll]);
	while(true) {
		clock.reset();
		darwin::runtime.fit_drawable();
		for(int i=0; i<weith; ++i) {
			for(int v=0; v<longth; ++v) {
				p.set_char(ks[i*longth+v].second);
				paint.draw_pixel(v,i,p);
			}
		}
		if(lose)
			paint.draw_pixel(x,y,wz);
		if(darwin::runtime.is_kb_hit()&&lose) {
			switch(std::tolower(darwin::runtime.get_kb_hit())) {
			case'w':
				if(y>0)
					--y;
				break;
			case's':
				if(y+1<weith)
					++y;
				break;
			case'a':
					if(x>0)
						--x;
				break;
			case'd':
					if(x+1<longth)
						++x;
				break;
			case'j':
				if(ks[y*longth+x].first=='o') {
					int able=0;
					if(y>=1)
						if(ks[(y-1)*longth+x].first=='s')
							++able;
					if(x>=1)
						if(ks[y*longth+x-1].first=='s')
							++able;
					if(x>=1&&y>=1)
						if(ks[(y-1)*longth+x-1].first=='s')
							++able;
					if(y>=1&&x<(longth-1))
						if(ks[(y-1)*longth+x+1].first=='s')
							++able;
					if(y<(weith-1)&&x>=1)
						if(ks[(y+1)*longth+x-1].first=='s')
							++able;
					if(y<(weith-1))
						if(ks[(y+1)*longth+x].first=='s')
							++able;
					if(x<(longth-1))
						if(ks[y*longth+x+1].first=='s')
							++able;
					if(y<(weith-1)&&x<(longth-1))
						if(ks[(y+1)*longth+x+1].first=='s')
							++able;
					if(able==bk[y*longth+x]) {
						if(y>=1)
							if(ks[(y-1)*longth+x].first=='c') {
								ks[(y-1)*longth+x].first='o';
								ks[(y-1)*longth+x].second=pi(bk[(y-1)*longth+x]);
							}
						if(x>=1)
							if(ks[y*longth+x-1].first=='c') {
								ks[y*longth+x-1].first='o';
								ks[y*longth+x-1].second=pi(bk[y*longth+x-1]);
							}
						if(x>=1&&y>=1)
							if(ks[(y-1)*longth+x-1].first=='c') {
								ks[(y-1)*longth+x-1].first='o';
								ks[(y-1)*longth+x-1].second=pi(bk[(y-1)*longth+x-1]);
							}
						if(y>=1&&x<(longth-1))
							if(ks[(y-1)*longth+x+1].first=='c') {
								ks[(y-1)*longth+x+1].first='o';
								ks[(y-1)*longth+x+1].second=pi(bk[(y-1)*longth+x+1]);
							}
						if(y<(weith-1)&&x>=1)
							if(ks[(y+1)*longth+x-1].first=='c') {
								ks[(y+1)*longth+x-1].first='o';
								ks[(y+1)*longth+x-1].second=pi(bk[(y+1)*longth+x-1]);
							}
						if(y<(weith-1))
							if(ks[(y+1)*longth+x].first=='c') {
								ks[(y+1)*longth+x].first='o';
								ks[(y+1)*longth+x].second=pi(bk[(y+1)*longth+x]);
							}
						if(x<(longth-1))
							if(ks[y*longth+x+1].first=='c') {
								ks[y*longth+x+1].first='o';
								ks[y*longth+x+1].second=pi(bk[y*longth+x+1]);
							}
						if(y<(weith-1)&&x<(longth-1))
							if(ks[(y+1)*longth+x+1].first=='c') {
								ks[(y+1)*longth+x+1].first='o';
								ks[(y+1)*longth+x+1].second=pi(bk[(y+1)*longth+x+1]);
							}
						ks=zhankai(ks,bk,longth,weith);
					}
				}
				if(ks[y*longth+x].first=='c')
					ks[y*longth+x].first='o';
				break;
			case'k':
				if(ks[y*longth+x].second=='s')
					ks[y*longth+x].first='c';
				break;
			case'l':
				if(ks[y*longth+x].first=='c')
					ks[y*longth+x].first='s';
				break;
			}
		}
		if(lose) {
			if(ks[y*longth+x].first=='o')
				ks[y*longth+x].second=pi(bk[y*longth+x]);
			if(ks[y*longth+x].first=='s')
				ks[y*longth+x].second='s';
			if(ks[y*longth+x].first=='c')
				ks[y*longth+x].second='+';
			ks=zhankai(ks,bk,longth,weith);
		}
		if(sf(ks,bk,longth,weith,ls)==-1) {
			pic->fill(die);
			lose=false;
			str0="You lose";
			str1="Please \"Ctrl+C\" to exit";
			cao1=-1;
		} else if(sf(ks,bk,longth,weith,ls)==1) {
			pic->fill(win);
			lose=false;
			str0="You win";
			str1="Please \"Ctrl+C\" to exit";
			cao1=1;
		}
		pic->draw_picture(0.5*(pic->get_width()-paint.get_width()),0.5*(pic->get_height()-paint.get_height()),paint);
		pic->draw_string(0,pic->get_height()-2,str0,darwin::pixel(' ',true,false,darwin::colors::blue,cao(cao1)));
		pic->draw_string(0,pic->get_height()-1,str1,darwin::pixel(' ',true,false,darwin::colors::blue,cao(cao1)));
		darwin::runtime.update_drawable();
		clock.sync();
	}
	return 0;
}
int main()
{
	unsigned ls1(10),ls2(10);
	int ls3(10);
	std::cout<<"Please enter length weith leishu"<<std::endl;
	std::cin>>ls1>>ls2>>ls3;
	if(ls1<10)
		ls1=10;
	if(ls2<10)
		ls2=10;
	if(ls1>32)
		ls1=32;
	if(ls2>24)
		ls2=24;
	if(ls3>90)
		ls3=90;
	if(ls3<10)
		ls3=10;
	paint.resize(ls1,ls2);
	saolei(ls1,ls2,ls3);
	return 0;
}