#include<iostream>
#include<string>

int main(){
    std::string str;
    std::cin>>str;
    std::string str_b="",str_m="",str_e="";
    bool count_r;
    while(true){
        str_b="";str_m="";str_e="";
        count_r=false;
        int l=0,r,num=0;
        int i;
        for(r=0;r<str.size();++r){
            if(str[r]==']'){
                count_r=true;
                for(l=r;l>0;--l){
                    if(str[l]=='['){
                        break;
                    }
                }
                break;
            }
        }
        if(!count_r){
            break;
        }
        for(i=1;i<=l&&str[l-i]>='0'&&str[l-i]<='9';++i){
            int temp=1;
            for(int j=1;j<i;++j){
                temp*=10;
            }
            num+=(((str[l-i])-48)*temp);
        }
        str_b=str.substr(0,l-i+1);
        str_m=str.substr(l+1,r-l-1);
        str_e=str.substr(r+1,str.size()-r-1);
        std::string str4="";
        for(i=0;i<num;++i){
            str4=str4+str_m;
        }
        str=str_b+str4+str_e;
    }
    std::cout<<str<<std::endl;
    return 0;
}