#include<iostream>
#include<deque>
int main(){
    int n,m;
    std::cin>>n>>m;
    int a[n];
    std::deque<int> b;//a表示火车驶出顺序，b表示调度站内火车；
    int now=0;//当前驶入火车
    for(int i=0;i<n;++i){
        std::cin>>a[i];
    }
    bool res=true;
    for(int i=0;i<n;){
        if(a[i]>now){
            if(b.size()<m){
                b.push_back(now);
                ++now;
            }
            else{
                res=false;
                break;
            }
        }
        if(a[i]<now){
            if(!b.empty()&&b[0]==a[i]){
                b.pop_front();
                ++i;
            }
            else{
                res=false;
                break;
            }
        }
        if(a[i]==now){
            ++now;
            ++i;
        }
    }
    std::cout<<(res?"YES":"NO")<<std::endl;
    return 0;
}