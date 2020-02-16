#include<iostream>
#include<vector>
#include<deque>
class WTF{
    public:
    int des=-1;
    int length=-1;
};
int main(){
    int n,m;
    std::cin>>n>>m;
    std::vector<WTF> v[2*n];
    int minl[2*n];
    for(int i=0;i<2*n;++i){
        minl[i]=-1;
    }
    minl[0]=minl[n]=0;
    for(int i=0;i<m;++i){
        int p1,p2,l,d;
        std::cin>>p1>>p2>>l>>d;
        d%=2;
        WTF a;
        a.length=l;
        if(d){//1开去p+n
            a.des=p2+n;
            v[p1].push_back(a);
        }
        else{//2开去p 
            a.des=p2;
            v[p1+n].push_back(a);
        }
    }
    std::deque<int> l;
    l.push_back(0);
    l.push_back(n);
    while(!l.empty()){
        int temp=l[0];
        for(int j=0;j<v[temp].size();++j){
            int ls=v[temp][j].des;
            if(minl[ls]==-1){
                minl[ls]=minl[temp]+v[temp][j].length;
                l.push_back(ls);
            }
            if(minl[temp]+v[temp][j].length<minl[ls]){
                minl[ls]=minl[temp]+v[temp][j].length;
                int k;
                for(k=1;k<l.size();++k){
                    if(l[k]==ls){
                        break;
                    }
                }
                if(k==l.size()){
                    l.push_back(ls);
                }
            }
        }
        l.pop_front();
    }
    for(int i=0;i<n;++i){
        if(minl[i]==-1){
            std::cout<<minl[i+n]<<" ";
            continue;
        }
        if(minl[i+n]==-1){
            std::cout<<minl[i]<<" ";
            continue;
        }
        std::cout<<(minl[i]<minl[i+n]?minl[i]:minl[i+n])<<" ";
    }
}