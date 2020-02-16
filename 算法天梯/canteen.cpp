#include<iostream>
int t1[10001]={0};
int t2[10001]={0};
int main(){
    int n;
    std::cin>>n;
    int a[4][n];
    for(int i=0;i<4;++i){
        for(int j=0;j<n;++j){
            std::cin>>a[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(a[0][i]+a[1][j]<=10000){
                ++t1[a[0][i]+a[1][j]];
            }
            if(a[2][i]+a[3][j]<=10000){
                ++t2[a[2][i]+a[3][j]];
            }
        }
    }
    int sum=0;
    for(int i=1;i<=10000;++i){
        sum+=(t1[i]*t2[10000-i]);
    }
    std::cout<<sum;
}