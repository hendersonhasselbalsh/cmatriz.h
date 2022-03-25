///////////

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <typeinfo>

using namespace std;

#ifndef MATRIZ_CLASSE_H_INCLUDED
#define MATRIZ_CLASSE_H_INCLUDED


#define MAT_ZERO 0
#define MAT_IDENTIDADE 1

template<typename T>
class Matrix{

    private:
        int lin = 0;
        int col = 0;
        vector< T > *mat;

    public:
        const int& rows = lin;      /*!< numero de linhas da matriz*/
        const int& cols = col;      /*!< numero de columas da matriz*/

        Matrix();   /*!< construtor vazio */
        Matrix(int _r, int _c); 
        Matrix(int _r, int _c, int mat_type);
        Matrix(int _r, int _c, T* data);


        template<typename Tp> friend ostream& operator<<(ostream& out, Matrix<Tp> m);
        template<typename Tp> friend istream& operator>>(istream& in, Matrix<Tp> m);
        vector<T>& operator[](int _r);
        void operator=(Matrix<T> a);
        template<typename Tp> friend Matrix<Tp> operator+(Matrix<Tp> a, Matrix<Tp> b);
        template<typename Tp> friend void operator+=(Matrix<Tp> a, Matrix<Tp> b);
        template<typename Tp> friend Matrix<Tp> operator-(Matrix<Tp> a, Matrix<Tp> b);
        template<typename Tp> friend void operator-=(Matrix<Tp> a, Matrix<Tp> b);
        template<typename Tp> friend Matrix<Tp> operator*(Matrix<Tp> a, Matrix<Tp> b);
        template<typename Tp, typename Tp2> friend Matrix<Tp> operator*(Matrix<Tp> a, Tp2 b);
        template<typename Tp, typename Tp2> friend Matrix<Tp> operator*(Tp2 b, Matrix<Tp> a);
        template<typename Tp> friend bool operator==(Matrix<Tp> a, Matrix<Tp> b);
        template<typename Tp, typename Tp2> friend Matrix<Tp> operator*(Matrix<Tp> a, Tp2 b);
        template<typename Tp, typename Tp2> friend Matrix<Tp> operator*(Tp2 b, Matrix<Tp> a);


        void read(const char* mensagem);
        void print(const char* message);
        T* data();
        int escalona(int type);

};


#endif 