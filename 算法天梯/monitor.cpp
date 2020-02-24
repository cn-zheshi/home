#include<iostream>
int main(){
    int n,k,m;
    std::cin>>n>>k>>m;
    int a[n+1];
    for(int i=0;i<=n;++i){
        a[i]=i;
    }
    int sh=0,ni=n+1;
    int counts,countn,count=0;
    while(true){
        counts=0;
        countn=0;
        int i,j;
        //counts统计顺时针数的时候中间被踢掉的人，保证到最后数出的确实是k个人
        for(i=1;i<=k+counts;++i){
            int temp=sh+i>n?((sh+i)%n==0?n:(sh+i)%n):sh+i;
            if(a[temp]==0){
                ++counts;
            }
        }
        sh=sh+k+counts>n?((sh+k+counts)%n==0?n:(sh+k+counts)%n):sh+k+counts;
        //countn统计逆时针数的时候中间被踢掉的人，保证到最后数出的确实是m个人
        for(int j=1;j<=m+countn;++j){
            int temp=ni-j<=0?(ni-j)%n+n:ni-j;
            if(a[temp]==0){
                ++countn;
            }
        }
        ni=ni-m-countn<=0?(ni-m-countn)%n+n:ni-m-countn;
        if(sh==ni){
            std::cout<<a[ni]<<std::endl;
            break;
        }
        else{
            std::cout<<a[sh]<<" "<<a[ni];
            a[sh]=0;
            a[ni]=0;
            count+=2;
            if(count!=n){
                std::cout<<" ";
            }
            else{
                std::cout<<std::endl;
                break;
            }
        }
    }
    return 0;
}