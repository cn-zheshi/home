#include<iostream>
int main(){
    int n;
    std::cin>>n;
    int a[n+1][3]={{0,0,0},{0,0,0}};
    for(int i=1;i<=n;++i){
        std::cin>>a[i][0]>>a[i][1];
        if(a[i][0]!=-1)
            a[a[i][0]][2]=a[i][2]+1;
        if(a[i][1]!=-1)
            a[a[i][1]][2]=a[i][2]+1;
    }
    for(int i=1;i<n;++i)
        if(a[i][2]>a[i-1][2]||a[i][2]<a[i+1][2])
            std::cout<<i<<" ";
    std::cout<<n;
    return 0;
}