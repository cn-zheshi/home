#include<iostream>
#include<string>
int answer=-1;
int n;
std::string a[20];
int use[20];
int p(std::string s1,std::string s2){
    int l1=s1.size(),l2=s2.size();
    bool temp;//是否重合
    for(int i=1;i<(l1<l2?l1:l2);++i){
        temp=true;
        for(int j=i;j>0;--j){
            if(s1[l1-j]!=s2[i-j]){
                temp=false;
            }
        }
        if(temp){
            return i;
        }
    }
    return 0;
}
int dfs(int k,int max){
    for(int i=0;i<n;++i){
        int length=p(a[k],a[i]);//重合长度
        if(length==a[k].size()||length==a[i].size()||length==0||use[i]>=2){
            continue;
        }
        ++use[i];
        max=max+a[i].size()-length;
        dfs(i,max);
        if(max>answer){
            answer=max;
        }
        --use[i];
        max=max-a[i].size()+length;
    }
    return max;
}
int main(){
    std::cin>>n;
    for(int i=0;i<n;++i){
        std::cin>>a[i];
        use[i]=0;
    }
    char head;
    std::cin>>head;
    for(int i=0;i<n;++i){
        if(head==a[i][0]){
            use[i]=1;
            int temp=dfs(i,a[i].size());
            if(temp>answer){
                answer=temp;
            }
            use[i]=0;
        }
    }
    std::cout<<answer<<std::endl;
    return 0;
}