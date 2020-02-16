#include<iostream>
#include<string>
class bignum{
    int d[110];
    int k;
public:
    const bignum operator*(const bignum& b){
        bignum c;
        c.k=this->k+b.k;
        for(int i=0;i<c.k;++i){
            c.d[i]=0;
        }
        for(int i=0;i<this->k;++i){
			for(int j=0;j<b.k;++j){
				(c.d)[i+j]+=((this->d)[i])*((b.d)[j]);
			}
		}
		for(int i=0; i<c.k; ++i) {
            if(c.d[i]>=10){
                if(i!=c.k-1){
                    c.d[i+1]+=c.d[i]/10;
                }
                else{
                    c.d[i+1]=c.d[i]/10;
                    c.k++;
                }
                c.d[i]%=10;
            }
		}
        while(c.d[c.k-1]==0){
            c.k--;
        }
		return c;
    }
    bignum()=default;
    bignum(const bignum &ch)=default;
	~bignum()=default;
	bignum& operator=(const bignum&)=default;
    bignum(char a[]){
        int i;
        for(i=0;a[i]!='\0';++i);
        k=i;
        for(i=0;i<k;++i){
            d[i]=a[k-1-i]-48;
        }
    }
    void print(){
        for(int i=this->k-1;i>=0;--i){
            std::cout<<(this->d)[i];
        }
        std::cout<<std::endl;
    }
};
int main(){
    int n;
    std::cin>>n;
    char a[n][100];
    bignum b[n+1];
    b[n]="1";
    for(int i=0;i<n;++i){
        std::cin>>a[i];
        b[i]=a[i];
    }
    for(int i=0;i<n;++i){
        b[n]=b[i]*b[n];
    }
    b[n].print();
    return 0;
}