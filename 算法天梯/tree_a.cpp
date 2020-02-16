#include<iostream>
class tree{
    public:
    int l=-2;
    int r=-2;
    int root=-2;
    int val;
};
void set(tree t[],int &i){
    if(t[i].l==-2){
        t[i].l=-1;
        return;
    }
    if(t[i].l!=-2&&t[i].r==-2){
        t[i].r=-1;
        return;
    }
    if(t[i].l!=-2&&t[i].r!=-2){
        if(i!=0){
            i=t[i].root;
            set(t,i);
        }
        return;
    }
}
void set_val(tree t[],int& i,int& j,int temp){
    if(t[i].l==-2){
        t[i].l=j;
        t[j].root=i;
        t[j].val=temp;
        i=j;
        j++;
        return;
    }
    if(t[i].l!=-2&&t[i].r==-2){
        t[i].r=j;
        t[j].root=i;
        t[j].val=temp;
        i=j;
        j++;
        return;
    }
    if(t[i].l!=-2&&t[i].r!=-2){
        i=t[i].root;
        set_val(t,i,j,temp);
        return;
    }
}
bool judge(tree t1[],tree t2[],int i,int j){
    if(t1[i].val!=t2[j].val){
        return false;
    }
    if(t1[i].l==-1&&t1[i].r==-1&&t2[j].l==-1&&t2[j].r==-1){
        return true;
    }
    if((t1[i].l==-1&&t2[j].r!=-1)||(t1[i].l!=-1&&t2[j].r==-1)){
        return false;
    }
    if((t1[i].r==-1&&t2[j].l!=-1)||(t1[i].r!=-1&&t2[j].l==-1)){
        return false;
    }
    if(t1[i].l==-1){
        return judge(t1,t2,t1[i].r,t2[j].l);
    }
    if(t1[i].r==-1){
        return judge(t1,t2,t1[i].l,t2[j].r);
    }
    return judge(t1,t2,t1[i].r,t2[j].l)&&judge(t1,t2,t1[i].l,t2[j].r);
}
int main(){
    int temp,n1=1,n2=1;
    char ch;
    tree t1[200];
    tree t2[200];
    std::cin>>temp;
    if(temp!=-1){
        ch=getchar();
        t1[0].val=temp;
        int i=0,j=1;
        while(ch!='\n'&&ch!=EOF){
            std::cin>>temp;
            if(temp!=-1){
                set_val(t1,i,j,temp);
            }
            else{
                set(t1,i);
            }
            ch=getchar();
        }
    }
    else{
        n1=0;
    }
    std::cin>>temp;
    if(temp!=-1){
        ch=getchar();
        t2[0].val=temp;
        int i=0,j=1;
        while(ch!='\n'&&ch!=EOF){
            std::cin>>temp;
            if(temp!=-1){
                set_val(t2,i,j,temp);
            }
            else{
                set(t2,i);
            }
            ch=getchar();
        }
    }
    else{
        n2=0;
    }
    if(n1!=n2){
        std::cout<<"NO"<<std::endl;
    }
    else{
        if(n1==0){
            std::cout<<"YES"<<std::endl;
        }
        else{
            if(judge(t1,t2,0,0)){
                std::cout<<"YES"<<std::endl;
            }
            else{
                std::cout<<"NO"<<std::endl;
            }
        }
    }
    return 0;
}