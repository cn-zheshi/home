#include <cstdlib>
#include <cstddef>
#include <vector>
#include <cstdint>
class base{
    std::size_t length;
    bool isgc=true;
    uint8_t* link;
    friend class memory_pool;
public:
    ~base(){
        delete link;
    }
};
class memory_pool{
    std::vector<base> v;
    void* raw=std::malloc(100000);
    std::size_t remind=100000;
public:
    void* malloc(std::size_t size){
        if(remind<size){
            throw "It is full";
        }
        if(!v.empty()){
            for(int i=0;i<v.size();++i){
                if(v[i].isgc&&v[i].length>=size){
                    if(v[i].length==size)
                        return v[i].link;
                    v[i].isgc=false;
                    base b;
                    bool a=false;
                    b.length=v[i].length-size;
                    b.isgc=true;
                    b.link=v[i].link+v[i].length;
                    for(int ls=0;ls<v.size();++ls){
                        if(b.link+b.length==v[ls].link&&v[ls].isgc){
                            b.length+=v[ls].length;
                            v[ls]=b;
                            a=true;
                        }
                        if(v[ls].link+v[ls].length==b.link&&v[ls].isgc){
                            v[ls].length+=b.length;
                            a=true;
                        }
                    }
                    if(!a)
                        v.push_back(b);
                    return reinterpret_cast<void*> v[i].link;
                }
            }
        }
        remind=remind-size;
        base b;
        b.length=size;
        b.isgc=false;
        b.link=raw+remind;
        v.push_back(b);
        return reinterpret_cast<void*> b.link;
    }
    void free(void* p){
        for(int i=0;i<v.size();++i){
            if(p==v[i].link){
                v[i].isgc=true;
                remind+=v[i].length;
                for(int ls=0;ls<v.size();++ls){
                    if(v[i].link+v[i].length==v[ls].link&&v[ls].isgc){
                        v[i].length+=v[ls].length;
                        v.erase(v.begin()+ls);
                        if(i>ls)
                            --i;
                        --ls;
                    }
                    if(v[ls].link+v[ls].length==v[i].link&&v[ls].isgc){
                        v[ls].length+=v[i].length;
                        v.erase(v.begin()+i);
                        if(i>ls)
                            --i;
                        --ls;
                    }
                }
            }
        }
        throw "Cannot free the pointer which is not in this memory_pool";
    }
    ~memory_pool(){
        std::free(raw);
    }
};