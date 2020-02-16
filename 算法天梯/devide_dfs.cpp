#include<iostream>
int s[20001];
int n;
class destory{
    public:
    int x=0,y=0;
    int des=0;
};
void sort(destory a[],int b,int e){
    int i=b,j=e;
    int k=a[b].des;
    if(b>=e)
        return;
    while(i<j){
        while(a[i].des<k&&i<e){
            i++;
        }
        while(a[j].des>=k&&j>b){
            j--;
        }
        if(i<j){
            destory temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    sort(a,b,j);
    sort(a,j+1,e);
    return;
}
int dfs(destory d[],int index,int med){
    int store[n+1];
    if(med==1){
        s[d[index].x]=1;
        s[d[index].y]=2;
    }
    else{
        s[d[index].x]=2;
        s[d[index].y]=1;
    }
    for(int i=index-1;i>=0;--i){
        if(s[d[i].x]==0&&s[d[i].y]==0){
            for(int i=0;i<=n;++i){
                store[i]=s[i];
            }
            int temp1=dfs(d,i,1);
            for(int i=0;i<=n;++i){
                s[i]=store[i];
            }
            int temp2=dfs(d,i,2);
            for(int i=0;i<=n;++i){
                s[i]=store[i];
            }
            return temp1<temp2?temp1:temp2;
        }
        else if(s[d[i].y]==s[d[i].x]){
            return d[i].des;
        }
        if(s[d[i].x]==0&&s[d[i].y]!=0){
            s[d[i].x]=s[d[i].y]%2+1;
        }
        if(s[d[i].y]==0&&s[d[i].x]!=0){
            s[d[i].y]=s[d[i].x]%2+1;
        }
    }
    return 0;
}
int main(){
    int m,max=0;
    std::cin>>n>>m;
    int store[n+1];
    if(m==0||m==1){
        std::cout<<0;
        return 0;
    }
    destory d[m];
    for(int i=0;i<=n;++i){
        s[i]=0;
    }
    for(int i=0;i<m;++i){
        std::cin>>d[i].x>>d[i].y>>d[i].des;
    }
    sort(d,0,m-1);
    s[d[m-1].x]=1;
    s[d[m-1].y]=2;
    for(int i=m-2;i>=0;--i){
        if(s[d[i].x]==0&&s[d[i].y]==0){
            for(int i=0;i<=n;++i){
                store[i]=s[i];
            }
            int temp1=dfs(d,i,1);
            for(int i=0;i<=n;++i){
                s[i]=store[i];
            }
            int temp2=dfs(d,i,2);
            std::cout<<(temp1<temp2?temp1:temp2)<<std::endl;
            return 0;
        }
        else if(s[d[i].y]==s[d[i].x]){
            std::cout<<d[i].des<<std::endl;
            return 0;
        }
        if(s[d[i].x]==0&&s[d[i].y]!=0){
            s[d[i].x]=s[d[i].y]%2+1;
        }
        if(s[d[i].y]==0&&s[d[i].x]!=0){
            s[d[i].y]=s[d[i].x]%2+1;
        }
    }
    std::cout<<0;
    return 0;
}