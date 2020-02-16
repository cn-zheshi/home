#include<iostream>
class tree{
    public:
    int left;
    int right;
    int floor;
};
int main(){
    int n;
    std::cin>>n;
    tree a[n+1];
    a[1].floor=0;
    for(int i=1;i<=n;++i){
        std::cin>>a[i].left>>a[i].right;
        if(a[i].left!=-1){
            a[a[i].left].floor=a[i].floor+1;
        }
        if(a[i].right!=-1){
            a[a[i].right].floor=a[i].floor+1;
        }
    }
    std::cout<<"1";
    for(int i=2;i<n;++i){
        if(a[i].floor>a[i-1].floor||a[i].floor<a[i+1].floor){
            std::cout<<" "<<i;
        }
    }
    if(n>1){
        std::cout<<" "<<n;
    }
    return 0;
}