////////

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef LINHA_H_INCLUDED
#define LINHA_H_INCLUDED

template<typename T = double, unsigned l = 0> class Vector{

    private:
        unsigned len = l;
        T* vect;

    public:
        Vector() { this->vect = new T [len]; }
        Vector(T* v);

        //Vector zeros();
        T* data() { return vect; }

        //template<typename Tp, unsigned _l> 
        //friend ostream& operator<<(ostream& os, Vector<T, _l> _v);

};

template<typename T, unsigned l> 
Vector<T, l>::Vector(T* v)
{
    this->vect = new T [len];
    for(unsigned i = 0; i < l; i++) { this->vect[i] = v[i]; }
}

/*
template<typename T, unsigned l = 0> 
Vector<T, l> Vector<T, l>::zeros()
{
    for(unsigned i = 0; i < l; i++) { this->vector[i] = 0; }
    Vector<T, l> aux(this->vector);
 return aux;
}*/

/*
template<typename Tp, unsigned _l = 0> 
ostream& operator<<(ostream& os, Vector<Tp, _l> _v)
{
    os << '[';
    for(unsigned i = 0; i < _l; i++) { os << _v.vect[i] << ", "; }
    os << ']';

 return os;
}*/













#endif