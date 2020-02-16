#include<iostream>
int main(){
    int n;
    int count=0;
    std::cin>>n;
    int a[n],b[n],c[n],d[n];
    int ab[n*n],abcount[n*n];
    int cd[n*n],cdcount[n*n];
    for(int i=0;i<n*n;++i){
        ab[i]=0;cd[i]=0;abcount[i]=0;cdcount[i]=0;
    }
    for(int i=1;i<=4;++i){
        for(int j=0;j<n;++j){
            if(i==1){
                std::cin>>a[j];
            }
            if(i==2){
                std::cin>>b[j];
            }
            if(i==3){
                std::cin>>c[j];
            }
            if(i==4){
                std::cin>>d[j];
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int k;
            for(k=0;ab[k]!=0&&k<n*n;++k){
                if(ab[k]==a[i]+b[j]){
                    break;
                }
            }
            ab[k]=a[i]+b[j];
            abcount[k]++;
            for(k=0;cd[k]!=0&&k<n*n;++k){
                if(cd[k]==c[i]+d[j]){
                    break;
                }
            }
            cd[k]=c[i]+d[j];
            cdcount[k]++;
        }
    }
    for(int i=0;ab[i]!=0&&i<n*n;++i){
        for(int j=0;cd[j]!=0&&j<n*n;++j){
            if(ab[i]+cd[j]==10000){
                count+=(abcount[i]*cdcount[j]);
            }
        }
    }
    std::cout<<count<<std::endl;
    return 0;
}