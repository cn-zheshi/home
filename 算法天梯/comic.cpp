#include<iostream>
int main(){
    int n,t;
    std::cin>>n>>t;
    int a[n];
    int min=0,max=0;
    for(int i=0;i<n;++i){
        std::cin>>a[i];
        a[i]--;
        if(a[i]<a[min]){
            min=i;
        }
        if(a[i]>a[max]){
            max=i;
        }
    }
    int s1=1,s2=a[max];
    int s=(s1+s2)/2;
    int count=0;
    while(s!=s1&&s!=s2){
        count=0;
        for(int i=0;i<n;++i){
            count+=(1+a[i]/s);
        }
        if(count>=t){
            s1=s;
        }
        if(count<=t){
            s2=s;
        }
        s=(s1+s2)/2;
    }
    if(s1!=s2){
        count=0;
        for(int i=0;i<n;++i){
            count+=(1+a[i]/s1);
        }
        //对s1来说，不可能小于等于（除非s1是1），如果s1是1且小于则没有问题，如果s1是1且等于将会出现问题
        //处理方法，在后面的count是不是与t相等里加上s是不是0
        if(count<=t){
            s=--s1;
        }
    }
    if(s!=0){
        while(count==t){
            count=0;
            s--;
            for(int i=0;i<n;++i){
                count+=(1+a[i]/s);
            }
        }
    }
    std::cout<<++s<<std::endl;
    return 0;
}