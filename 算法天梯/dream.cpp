#include<iostream>
void sort(int a[],int b,int e);
int main(){
    int n,add;
    std::cin>>n>>add;
    int a[n];
    for(int i=0;i<n;++i){
        std::cin>>a[i];
    }
    int count=0;
    for(int i=n-1;i>0&&count<add;--i){
        if(a[i-1]<a[i]){
            int min=i;
            for(int j=i;j<n;++j){
                if(a[j]<a[min]&&a[j]>a[i-1]){
                    min=j;
                }
            }
            int temp=a[i-1];
            a[i-1]=a[min];
            a[min]=temp;
            sort(a,i,n-1);
            ++count;
            i=n;
        }
    }
    for(int i=0;i<n-1;++i){
        std::cout<<a[i]<<" ";
    }
    std::cout<<a[n-1]<<std::endl;
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