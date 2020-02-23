#include<stdio.h>
bool is_prime(int n);
int main(){
    int n;
    int a[10001]={0};
    scanf("%d",&n);
    for(int i=3;i<n;i+=2){
        if(is_prime(i)){
            a[i]=1;
        }
    }
    for(int i=3;2*i<n;i+=2){
        if(a[i]&&a[n-i]){
            printf("%d %d\n",i,n-i);
        }
    }
    return 0;
}
bool is_prime(int n){
    for(int i=3;i*i<n;i+=2){
        if(!(n%i)){
            return false;
        }
    }
    return true;
}