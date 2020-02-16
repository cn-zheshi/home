#include<iostream>
#include<vector>
class WTF{
public:
    int bef=0;
    std::vector<int> v;
};
int main(){
    int n,m;
    int t1,t2,count=0;
    std::cin>>n>>m;
    WTF a[n];
    for(int i=0;i<m;++i){
        std::cin>>t1>>t2;
        a[t1].v.push_back(t2);
        a[t2].bef++;
    }
    for(int i=0;i<n;++i){
        if(a[i].bef==0){
            std::cout<<i<<(count!=n-1?" ":"");
            ++count;
            a[i].bef=-1;
            int temp=i;
            for(int j=0;j<a[i].v.size();++j){
                if(--a[a[i].v[j]].bef==0&&a[i].v[j]<temp){
                    temp=a[i].v[j];
                }
            }
            i=temp-1;
        }
    }
}