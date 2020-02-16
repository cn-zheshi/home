#include<iostream>
class people{
    public:
    int h=0;
    int w=0;
    bool operator<(const people &a){
        if(this->h<a.h&&this->w<a.w){
            return true;
        }
        else{
            return false;
        }
        
    }
};
void sort(people a[],int b,int e){
    int i=b,j=e;
    int k=a[b].h;
    if(b>=e)
        return;
    while(i<j){
        while(a[i].h<k&&i<e){
            i++;
        }
        while(a[j].h>=k&&j>b){
            j--;
        }
        if(i<j){
            people temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    sort(a,b,j);
    sort(a,j+1,e);
    return;
}
int main(){
    int n,max=0;
    std::cin>>n;
    people p[n];
    int length[n];
    for(int i=0;i<n;++i){
        std::cin>>p[i].h>>p[i].w;
        length[i]=0;
    }
    sort(p,0,n-1);
    for(int i=0;i<n;++i){
        for(int j=0;j<i;++j){
            if(p[j]<p[i]){
                length[i]=(length[j]>length[i]?length[j]:length[i]);
            }
        }
        ++length[i];
        max=(max>length[i]?max:length[i]);
    }
    std::cout<<max<<std::endl;
}