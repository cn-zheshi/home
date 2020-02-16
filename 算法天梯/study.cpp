#include<iostream>
int main(){
    int n,cnt_s=0,temp,max=0;
    scanf("%d",&n);
    int v[n+1];
    int t[2*n+1];
    v[0]=0;
    for(int i=0;i<=n;++i){
        t[i]=-1;
        t[n+i]=0;
    }
    for(int i=1;i<n+1;++i){
        std::cin>>temp;
        if(temp>8){
            ++cnt_s;
        }
        v[i]=2*cnt_s-i;
        for(int j=2*cnt_s-i+n+1;j<=2*n&&t[j]==-1;++j){
            t[j]=i;
        }
    }
    for(int i=1;i<n+1;++i){
        if(t[v[i]+n]!=-1&&i-t[v[i]+n]>max){
            max=i-t[v[i]+n];
        }
    }
    std::cout<<max;
}