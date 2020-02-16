#include<iostream>
#include<vector>
class tree{
    public:
    int l=-1;
    int r=-1;
    int root=-1;
};
int length(tree t[],int i,int j){
    std::vector<int> v1,v2;
    while(i){
        v1.push_back(i);
        i=t[i].root;
    }
    while(j){
        v2.push_back(j);
        j=t[j].root;
    }
    for(i=0;i<v1.size();++i){
        for(j=0;j<v2.size();++j){
            if(v1[i]==v2[j]){
                return i+j;
            }
        }
    }
    return i+j;
}
int main(){
    int l,r,n;
    std::cin>>n;
    tree t[n];
    std::vector<int> v1,v2;
    for(int i=0;i<n;++i){
        std::cin>>l>>r;
        t[i].l=l;
        t[i].r=r;
        if(l!=-1){
            t[l].root=i;
        }
        if(r!=-1){
            t[r].root=i;
        }
    }
    int max=0;
    for(int i=0;i<n;++i){
        if(t[i].l==-1&&t[i].r==-1){
            int j=i+1;
            for(;j<n;++j){
                if(t[j].l==-1&&t[j].r==-1){
                    int temp=length(t,i,j);
                    max=(max<temp?temp:max);
                }
            }
        }
    }
    if(max!=0){
        std::cout<<2*(n-1)-max;
    }
    else{
        std::cout<<n-1;
    }
    return 0;
}