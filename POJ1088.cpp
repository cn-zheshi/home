#include<iostream>
#include<algorithm>
class WTF{
public:
    int x=-1,y=-1;
    int h=-1;
    bool operator < (WTF a){
        return (this->h)<a.h;
    }
};
int abs(int x){
    return x>=0?x:-x;
}
int main(){
    int width,length,max=0;
    std::cin>>width>>length;
    WTF a[width*length];
    int l[width*length];
    for(int i=0;i<width;i++){
        for(int j=0;j<length;j++){
            l[i*length+j]=0;
            std::cin>>a[i*length+j].h;
            a[i*length+j].x=j;
            a[i*length+j].y=i;
        }
    }
    std::sort(a,a+width*length);
    for(int i=0;i<width*length;++i){
        for(int j=0;j<i;++j){
            if(a[j]<a[i]&&((a[j].x==a[i].x&&abs(a[j].y-a[i].y)<=1)||(a[j].y==a[i].y&&abs(a[j].x-a[i].x)<=1))){
                if(l[j]>l[i]){
                    l[i]=l[j];
                }
            }
        }
        ++l[i];
    }
    for(int i=0;i<width*length;++i){
        if(l[i]>max){
            max=l[i];
        }
    }
    std::cout<<max<<std::endl;
    return 0;
}