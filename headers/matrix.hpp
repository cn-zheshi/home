#pragma once
#include<deque>
#include<iostream>
//line 表示行数或行号，row表示列数或列号
namespace zheshi{
    class matrix{
        std::deque<std::deque<double>> mat;
        friend void set(unsigned line,unsigned row,double value);
        friend const matrix operator+(const matrix&,const matrix&);
        friend const matrix operator-(const matrix&);
        friend const matrix operator-(const matrix&,const matrix&);
        friend const matrix operator*(const matrix&,const matrix&);
        friend const matrix operator*(const double&,const matrix&) override;
        friend const matrix operator*(const matrix&,const double&) override;
    public:
        matrix(){
            mat.push_back({0});
        }
        matrix(unsigned line,unsigned row,double initial=0){
            std::deque<double> ls;
            for(unsigned i=0;i<row;++i){
                ls.push_back(initial);
            }
            for(unsigned i=0;i<line;++i){
                mat.push_back(ls);
            }
        }
        matrix(std::deque<std::deque<double>> a){
            if(!a.empty()){
                if(!a[0].empty()){
                    mat=a;
                }
                else{
                    mat.push_back({0});
                }
            }
            else{
                mat.push_back({0});
            }
        }
        matrix(const matrix&)=default;
        matrix& operator=(const matrix&)=default;
        ~matrix()=default;
    };
    void set(unsigned line,unsigned row,double value){
        if(line>=(this->mat).size()||row>=(this->mat)[0].size())
            return;
        (this->mat)[line][row]=value;
    }
    const matrix operator+(const matrix& a,const matrix& b){
        matrix d;
        if(a.mat.size()!=b.mat.size()||(a.mat)[0].size()!=(b.mat)[0].size()){
            return d;
        }
        for(unsigned i=0;i<a.mat.size();++i){
            std::deque<double> ls;
            for(unsigned j=0;j<(a.mat)[0].size();++j){
                ls.push_back(a.mat[i][j]+b.mat[i][j]);
            }
            d.mat.push_back(ls);
        }
        return d;
    }
    const matrix operator-(const matrix& a){
        matrix d;
        for(unsigned i=0;i<a.mat.size();++i){
            std::deque<double> ls;
            for(unsigned j=0;j<(a.mat)[0].size();++j){
                ls.push_back(-a.mat[i][j]);
            }
            d.mat.push_back(ls);
        }
        return d;
    }
    const matrix operator-(const matrix& a,const matrix& b){
        matrix d;
        if(a.mat.size()!=b.mat.size()||(a.mat)[0].size()!=(b.mat)[0].size()){
            return d;
        }
        for(unsigned i=0;i<a.mat.size();++i){
            std::deque<double> ls;
            for(unsigned j=0;j<(a.mat)[0].size();++j){
                ls.push_back(a.mat[i][j]-b.mat[i][j]);
            }
            d.mat.push_back(ls);
        }
        return d;
    }
    const matrix operator*(const double& a,const matrix& b){
        matrix d;
        for(unsigned i=0;i<b.mat.size();++i){
            std::deque<double> ls;
            for(unsigned j=0;j<(b.mat)[0].size();++j){
                ls.push_back(b.mat[i][j]*a);
            }
            d.mat.push_back(ls);
        }
        return d;
    }
    const matrix operator*(const matrix& a,const double& b) override{
        return b*a;
    }
    const matrix operator*(const matrix& a,const matrix& b) override{
        matrix d;
        if(a.mat.size()==1&&(a.mat)[0].size()==1){
            return (a.mat)[0][0]*b;
        }
        if(b.mat.size()==1&&(b.mat)[0].size()==1){
            return (b.mat)[0][0]*a;
        }
        if((a.mat)[0].size()!=b.mat.size()){
            return d;
        }
        
    }
}