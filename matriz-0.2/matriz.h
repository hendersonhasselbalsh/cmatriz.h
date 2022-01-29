///////

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "linha.h"

using namespace std;


#ifndef CMATRIZ_H_INCLUDED
#define CMATRIZ_H_INCLUDED

template<typename Tp = double> 
class Matrix {

    private:
        int l = 0;
        int c = 0;
         
    
    public:
        Tp** mat = NULL;
        Matrix() {};
        Matrix(int rows, int cols);

        const int& rows = l;
        const int& cols = c;

        template<typename T> friend ostream& operator<<(ostream& out, Matrix<T> m);
        void read(const char* mensagem);
        ROW<Tp> operator[](int _r);
};

template<typename Tp> Matrix<Tp>::Matrix(int _r, int _c)
{
    this->l = _r; this->c = _c;
    this->mat = new Tp* [_r];
    for(int i = 0; i < _r; i++) { this->mat[i] = new Tp [_c]; }
}

template<typename T> ostream& operator<<(ostream& out, Matrix<T> m)
{
    for(int i = 0; i < m.rows; i++)
    {
        for(int j = 0; j < m.cols; j++)
        {
            out << setw(4) << m.mat[i][j] << "  ";
        }
        
        out << endl;
    }

    out << endl << endl;

 return out;
}

template<typename Tp> void Matrix<Tp>::read(const char* mensagem)
{
    if( mensagem ) { cout << mensagem << endl; }

    for(int i = 0; i < this->rows; i++)
    {
        for(int j = 0; j < this->cols; j++)
        {
            cin >> this->mat[i][j];
        }
    }
}

template<typename Tp> ROW<Tp> Matrix<Tp>::operator[](int _r)
{
    
}












#endif

#define MatDouble  Matrix<double>
#define MatInt     Matrix<int>
#define MatChar    Matrix<char>
#define MatFloat   Matrix<float>
#define MatLong    Matrix<long>