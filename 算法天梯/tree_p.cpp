#include<iostream>
class tree{
    public:
    int val;
    tree* left;
    tree* right;
    tree()=default;
    ~tree(){
        delete(left);
        delete(right);
    }
    void tree_in(){
        int i;
        std::cin>>i;
        if(i==-1){
            this->val=i;
            return;
        }
        else{
            this->val=i;
            this->left=new tree();
            (this->left)->tree_in();
            this->right=new tree();
            (this->right)->tree_in();
        }
    }
    bool ref(tree* t1){
        if(this->val!=t1->val){
            return false;
        }
        if(this->val==-1&&t1->val==-1){
            return true;
        }
        else{
            return this->right->ref(t1->left)&&this->left->ref(t1->right);
        }
    }
};
int main(){
    tree* t1=new tree();
    tree* t2=new tree();
    t1->tree_in();
    t2->tree_in();
    if(t1->ref(t2)){
        std::cout<<"YES"<<std::endl;
    }
    else{
        std::cout<<"NO"<<std::endl;
    }
    return 0;
}