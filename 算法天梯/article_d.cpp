#include<iostream>
#include<string>
void print_str(std::string str,int start,int end){
    int rep=0;
    while(start<=end){
        if(str[start]>='a'&&str[start]<='z'){
            std::cout<<str[start];
        }
        if(str[start]>='0'&&str[start]<='9'){
            rep=10*rep+str[start]-48;
        }
        if(str[start]=='['){
            int count=0;
            int temp;
            for(temp=start;temp<end;++temp){
                if(str[temp]=='['){
                    ++count;
                }
                if(str[temp]==']'){
                    --count;
                }
                if(count==0){
                    break;
                }
            }
            for(int i=1;i<rep;++i){
                print_str(str,start,temp);
            }
            rep=0;
        }
        ++start;
    }
}
int main(){
    std::string str;
    std::cin>>str;
    print_str(str,0,str.size()-1);
    return 0;
}