#include<iostream>
#include<vector>
class WTF{
    public:
    int c=-1;//0胜1胜2
    int index=-1;
};
int main(){
    int n,m,count=0;
    std::cin>>n>>m;
    WTF a[n+1];
    std::vector<std::vector<int>> v;
    int kind=0,a1,a2;
    int index=0;
    for(int i=0;i<m;++i){
        std::cin>>kind>>a1>>a2;
        if(a1>n||a2>n){
            ++count;
            continue;
        }
        if(kind==1){
            if(a1==a2){
                continue;
            }
            if(a[a1].c==-1&&a[a2].c==-1){
                v.push_back({});
                v[index].push_back(a1);
                v[index].push_back(a2);
                a[a1].index=index;
                a[a2].index=index;
                a[a1].c=0;
                a[a2].c=0;
                ++index;
                continue;
            }
            if(a[a1].c==-1&&a[a2].c!=-1){
                a[a1].index=a[a2].index;
                v[a[a2].index].push_back(a1);
                a[a1].c=a[a2].c;
                continue;
            }
            if(a[a2].c==-1&&a[a1].c!=-1){
                a[a2].index=a[a1].index;
                v[a[a1].index].push_back(a2);
                a[a2].c=a[a1].c;
                continue;
            }
            if(a[a1].c!=-1&&a[a2].c!=-1){
                if(a[a1].c!=a[a2].c){
                    if(a[a1].index==a[a2].index){
                        ++count;
                        continue;
                    }
                    else{
                        int temp=a[a2].c-a[a1].c;
                        int idx=a[a1].index;
                        int index1=a[a2].index;
                        for(int j=0;j<v[idx].size();++j){
                            a[v[idx][j]].index=index1;
                            a[v[idx][j]].c=(a[v[idx][j]].c+temp+3)%3;
                            v[index1].push_back(v[idx][j]);
                        }
                        v[idx].clear();
                    }
                }
                else{
                    if(a[a1].index==a[a2].index){
                        continue;
                    }
                    else{
                        int idx=a[a1].index;
                        int index1=a[a2].index;
                        for(int j=0;j<v[idx].size();++j){
                            a[v[idx][j]].index=index1;
                            v[index1].push_back(v[idx][j]);
                        }
                        v[idx].clear();
                    }
                }
            }
        }
        else{
            if(a1==a2){
                ++count;
                continue;
            }
            if(a[a1].c==-1&&a[a2].c==-1){
                v.push_back({});
                v[index].push_back(a1);
                v[index].push_back(a2);
                a[a1].index=index;
                a[a2].index=index;
                a[a1].c=0;
                a[a2].c=1;
                ++index;
                continue;
            }
            if(a[a1].c==-1&&a[a2].c!=-1){
                a[a1].index=a[a2].index;
                v[a[a2].index].push_back(a1);
                a[a1].c=(a[a2].c+2)%3;
                continue;
            }
            if(a[a2].c==-1&&a[a1].c!=-1){
                a[a2].index=a[a1].index;
                v[a[a1].index].push_back(a2);
                a[a2].c=(a[a1].c+1)%3;
                continue;
            }
            if(a[a1].c!=-1&&a[a2].c!=-1){
                if((a[a1].c+1)%3!=a[a2].c){
                    if(a[a1].index==a[a2].index){
                        ++count;
                        continue;
                    }
                    else{
                        int temp=a[a1].c-a[a2].c;
                        int idx=a[a2].index;
                        int index1=a[a1].index;
                        for(int j=0;j<v[idx].size();++j){
                            a[v[idx][j]].index=index1;
                            a[v[idx][j]].c=(a[v[idx][j]].c+temp+4)%3;
                            v[index1].push_back(v[idx][j]);
                        }
                        v[idx].clear();
                    }
                }
                else{
                    if(a[a1].index==a[a2].index){
                        continue;
                    }
                    else{
                        int idx=a[a1].index;
                        int index1=a[a2].index;
                        for(int j=0;j<v[idx].size();++j){
                            a[v[idx][j]].index=index1;
                            v[index1].push_back(v[idx][j]);
                        }
                        v[idx].clear();
                    }
                }
            }
        }
    }
    std::cout<<count<<std::endl;
}