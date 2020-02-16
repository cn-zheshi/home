#include <typeinfo>
class base_container {
public:
    base_container()=default;
    base_container(const base_container&)=default;
    virtual ~base_container()=default;
    virtual const std::type_info& get_type() const noexcept=0;
    virtual base_container* clone()=0;
};
template<typename T> class data:public base_container{
    T d;
public:
    data()=default;
    data(const T& val):d(val){}
    virtual base_container* clone() override{
       return new data<T>(d);
    }
    virtual ~data()=default;
    virtual const std::type_info& get_type() const noexcept override{
        return typeid(T);
    }
    T& get_val(){
        return d;
    }
};
class any{
    base_container *b=nullptr;
public:
    any()=default;
    any(const any& val){
       b=(*(val.b)).clone();
    }
    template <typename T>any(const T& val){
        b=new data<T>(val);
    }
    any& operator = (const any& val) {
        if(this->b==val.b)
            return *this;
        if(val.b==nullptr)
            b=nullptr;
        delete b;
        b=(*(val.b)).clone();
    }
    const std::type_info& type() const{
        return (*b).get_type();
    }
    template <typename T>
    T& get(){
        if(typeid(T)==(*b).get_type())
            return static_cast<data<T>*>(b)->get_val();
    }
};