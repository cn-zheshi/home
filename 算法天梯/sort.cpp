#include<iostream>
void sort(int a[],int b,int e);
int main(){
    int n;
    std::cin>>n;
    int a[n];
    for(int i=0;i<n;++i){
        std::cin>>a[i];
    }
    sort(a,0,n-1);
    for(int i=0;i<n;++i){
        std::cout<<a[i]<<' ';
    }
    return 0;
}
void sort(int a[],int b,int e){
    int i=b,j=e;
    int k=a[b];
    if(b>=e)
        return;
    while(i<j){
        while(a[i]<k&&i<e){
            i++;
        }
        while(a[j]>=k&&j>b){
            j--;
        }
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    sort(a,b,j);
    sort(a,j+1,e);
    return;
}