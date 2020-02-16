#include<iostream>
#include<string>
#include<vector>
std::vector<int> v;
int n;
int judge[51]={0};
bool try_to(std::string str,int index,int cnt){
    if(index>=str.size()){
        return true;
    }
    v.push_back(cnt);
    int store[51];
    int temp=(cnt==1?str[index]-48:10*(str[index]-48)+str[index+1]-48);
    if(temp>n||judge[temp]!=0){
        v.pop_back();
        return false;
    }
    else{
        judge[temp]=1;
    }
    for(int i=0;i<=50;++i){
        store[i]=judge[i];
    }
    if(try_to(str,index+cnt,1)){
        return true;
    }
    for(int i=0;i<=50;++i){
        judge[i]=store[i];
    }
    if(try_to(str,index+cnt,2)){
        return true;
    }
    for(int i=0;i<=50;++i){
        judge[i]=store[i];
    }
    judge[temp]=0;
    v.pop_back();
    return false;
}
int main(){
    std::string s;
    std::cin>>s;
    if(s.size()<9){
        n=s.size();
    }
    else{
        n=9+(s.size()-9)/2;
    }
    if(try_to(s,0,1)){
        int index=0;
        for(int i=0;i<v.size()-1;++i){
            for(int j=0;j<v[i];++j){
                std::cout<<s[index];
                index++;
            }
            std::cout<<' ';
        }
        for(;index<s.size();++index){
            std::cout<<s[index];
        }
        return 0;
    }
    for(int i=0;i<=50;++i){
        judge[i]=0;
    }
    if(try_to(s,0,2)){
        int index=0;
        for(int i=0;i<v.size()-1;++i){
            for(int j=0;j<v[i];++j){
                std::cout<<s[index];
                index++;
            }
            std::cout<<' ';
        }
        for(;index<s.size();++index){
            std::cout<<s[index];
        }
        return 0;
    }
}