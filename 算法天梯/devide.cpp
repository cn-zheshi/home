#include<iostream>
#include<algorithm>
#include<vector>
class destory{
    public:
    int x=0,y=0;
    int des=0;
};
class WTF{
    public:
    int index=-1;//能合作就连线，能连线（包括经过别人连线）的index相同
    int g=-1;//分的组
};
bool cmp(destory a,destory b){
    return a.des<b.des;
}
int main(){
    int n,m;
    std::cin>>n>>m;
    WTF s[n+1];//下标表示编号
    if(m==0||m==1){
        std::cout<<0;
        return 0;
    }
    std::vector<std::vector<int>> v;
    destory d[m];
    for(int i=0;i<m;++i){
        std::cin>>d[i].x>>d[i].y>>d[i].des;
    }
    int index=0;
    std::sort(d,d+m,cmp);
    for(int i=m-1;i>=0;--i){
        if(s[d[i].x].g==-1&&s[d[i].y].g==-1){
            s[d[i].x].g=0;
            s[d[i].y].g=1;
            s[d[i].x].index=index;
            s[d[i].y].index=index;
            v.push_back({});
            v[index].push_back(d[i].x);
            v[index].push_back(d[i].y);
            index++;
        }
        if(s[d[i].x].g==-1&&s[d[i].y].g!=-1){
            s[d[i].x].g=!s[d[i].y].g;
            s[d[i].x].index=s[d[i].y].index;
            v[s[d[i].y].index].push_back(d[i].x);
        }
        if(s[d[i].y].g==-1&&s[d[i].x].g!=-1){
            s[d[i].y].g=!s[d[i].x].g;
            s[d[i].y].index=s[d[i].x].index;
            v[s[d[i].x].index].push_back(d[i].y);
        }
        if(s[d[i].x].g!=-1&&s[d[i].y].g!=-1){
            if(s[d[i].x].g==s[d[i].y].g){
                if(s[d[i].x].index==s[d[i].y].index){
                    //同组，已连线，输出
                    std::cout<<d[i].des<<std::endl;
                    return 0;
                }
                else{
                    //同组，未连线，将一条线的组全部反过来，连线
                    int temp=s[d[i].x].index;
                    int ls=s[d[i].y].index;
                    for(int j=0;j<v[ls].size();++j){
                        s[v[ls][j]].index=temp;
                        s[v[ls][j]].g=!s[v[ls][j]].g;
                        v[temp].push_back(v[ls][j]);
                    }
                }
            }
            else{
                //不同组，未连线，连起来
                if(s[d[i].x].index!=s[d[i].y].index){
                    int temp=s[d[i].x].index;
                    int ls=s[d[i].y].index;
                    for(int j=0;j<v[ls].size();++j){
                        s[v[ls][j]].index=temp;
                        v[temp].push_back(v[ls][j]);
                    }
                }
                //不同组已连线不用处理
            }
        }
    }
    std::cout<<0;
    return 0;
}