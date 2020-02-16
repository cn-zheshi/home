#include<iostream>
bool wtf(int a1,int b1,int c1,int a2,int b2,int c2,int a3,int b3,int c3){
    for(int i=1;i<=9;++i){
        if(!(a1==i||a2==i||a3==i||b1==i||b2==i||b3==i||c1==i||c2==i||c3==i)){
            return false;
        }
    }
    return true;
}
int main(){
    int a1,b1,c1;
    int a2,b2,c2;
    int a3,b3,c3;
    for(a1=1;a1<=3;++a1){
        for(b1=1;b1<=9;++b1){
            for(c1=1;c1<=9;++c1){
                c2=(2*c1)%10;
                b2=(2*b1+2*c1/10)%10;
                a2=2*a1+2*b1/10;
                c3=(3*c1)%10;
                b3=(3*b1+3*c1/10)%10;
                a3=3*a1+(3*b1+3*c1/10)/10;
                if(wtf(a1,a2,a3,b1,b2,b3,c1,c2,c3)){
                    std::cout<<a1<<b1<<c1<<" "<<a2<<b2<<c2<<" "<<a3<<b3<<c3<<std::endl;
                }
            }
        }
    }
    return 0;
}