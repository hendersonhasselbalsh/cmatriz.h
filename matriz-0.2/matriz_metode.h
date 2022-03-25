////////

#include "matriz_classe.h"

#ifndef MATRIZ_METODO_H_INCLUDED
#define MATRIZ_METODO_H_INCLUDED

/**
 * @brief inicializa o numero de linas da matriz
 * @param _r Define o numeor de linhas para a matriz
 * @param _c Define o numeor de colunas para a matriz
*/
template<typename T> Matrix<T>::Matrix(int _r, int _c)
{
    this->lin = _r;   this->col = _c;

    this->mat  =  new vector<T> [_r];
    for(int i = 0; i < _r; i++) { this->mat[i] = vector<T>(_c); }
}


/**
 *  construtor 
 * @param mat_type tipo da matriz, use 0 pra matriz nula, 1 para matriz identidade
*/
template<typename T> Matrix<T>::Matrix(int _r, int _c, int mat_type)
{
    this->lin = _r;   this->col = _c;
    this->mat  =  new vector<T> [_r];
    for(int i = 0; i < _r; i++) { this->mat[i] = vector<T>(_c); }

    if( mat_type == MAT_ZERO )
    {
        for(int i = 0; i < _r; i++)
        {
            for(int j = 0; j < _c; j++)
            {
                this->mat[i][j] = 0;
            }
        }
    }
    else if( mat_type == MAT_IDENTIDADE )
    {
        for(int i = 0; i < _r; i++)
        {
            for(int j = 0; j < _c; j++)
            {
                (i == j) ? this->mat[i][j] = 1  : this->mat[i][j] = 0;
            }
        }
    }
}


/**
 * @brief construtor para nicializar os elementos da matriz
 * @param data um array contendo os elementos da matriz
*/
template<typename T> Matrix<T>::Matrix(int _r, int _c, T* data)
{
    this->lin = _r;   this->col = _c;
    this->mat  =  new vector<T> [_r];
    for(int i = 0; i < _r; i++) { this->mat[i] = vector<T>(_c); }

    int index = 0;
    for(int i = 0; i < _r; i++)
    {
        for(int j = 0; j < _c; j++)
        {
            this->mat[i][j] = data[ index ];   index++;
        }
    }
}



template<typename Tp> ostream& operator<<(ostream& out, Matrix<Tp> m)
{
    for(int i = 0; i < m.rows; i++)
    {
        for(int j = 0; j < m.cols; j++)
        {
            out << setw(4) << m.mat[i][j] << "  ";
        }
        
        out << endl;
    }

    out << endl;

 return out;
}


/**
 * @brief função para inserir os elementos na matriz; 
 * lembre de digitar todos os elemento, se for um 3x3 deverá ser digitado 9 elementos
 * @param mensagem a mensagem será mostrada antes de se ler os elementos da matriz
*/
template<typename T> void Matrix<T>::read(const char* mensagem)
{
    if( mensagem ) { cout << mensagem << endl; }

    for(int i = 0; i < this->rows; i++)
    {
        for(int j = 0; j < this->cols; j++)
        {
            cin >> this->operator[](i)[j];
        }
    }
}


/**
 * @brief função para mostrar os elementos na matriz
 * @param message a mensagem será mostrada antes de se mostrar os elementos da matriz
*/
template<typename T> void Matrix<T>::print(const char* message)
{
    if( message ) { cout << message << endl; }
    
    for(int i = 0; i < this->rows; i++)
    {
        for(int j = 0; j < this->cols; j++)
        {
            cout << setw(4) << this->mat[i][j] << "  ";
        }
        
        cout << endl;
    } 
    cout << endl << endl; 
}


/**
 * @brief função para inserir os elementos na matriz; 
 * lembre de digitar todos os elemento, se for um 3x3 deverá ser digitado 9 elementos
*/
template<typename Tp> istream& operator>>(istream& in, Matrix<Tp> m)
{
    for(int i = 0; i < m.rows; i++)
    {
        for(int j = 0; j < m.cols; j++)
        {
            in >> m.mat[i][j];
        }
    }
 return in;
}


/**
 * @brief é usado para acessar uma linha especifica
 * por exemplo:
 *     Matrix<double>  m   =  Matrix<double>(3, 3);
 *     cout << m[1][2];   <-  retorna o elemento da linha 1 coluna 2; 
 * @param _r linha onde esta o elemento
*/
template<typename T> vector<T>& Matrix<T>::operator[](int _r)
{
    return this->mat[_r];
}


/**
 * @brief soma duas matrizes,elas devem ser do mesmo tipo, e retornará uma 
 * nova matriz 
*/
template<typename Tp> Matrix<Tp> operator+(Matrix<Tp> a, Matrix<Tp> b)
{
    if( a.rows != b.rows || a.cols != b.cols) { cerr << "ERRO!!! dimensoes incompativeis" << endl; }

    Matrix<Tp> result  =  Matrix<Tp>(a.rows, a.cols);

    for(int i = 0; i < a.rows; i++)
    {
        for(int j = 0; j < a.cols; j++)
        {
            result[i][j]  =  a[i][j] + b[i][j];
        }
    }

 return result;
}


/**
 * @brief iguala duas matriz 
*/
template<typename T> void Matrix<T>::operator=(Matrix<T> a)
{
    //if( typeid(this->mat) !=  typeid(a.mat)) { cout<<"ERRO!!! tipos incompativeis\n"; exit(-1); }
    this->lin = a.lin;   this->col = a.cols;

    for(int i = 0; i < a.rows; i++)
    {
        for(int j = 0; j < a.cols; j++)
        {
            this->operator[](i)[j]  =  a[i][j];
        }
    }
    
}


/**
 * 
*/
template<typename Tp> void operator+=(Matrix<Tp> a, Matrix<Tp> b)
{
    a = a + b;
}


/**
 * @brief subtrai duas matrizes
*/
template<typename Tp> Matrix<Tp> operator-(Matrix<Tp> a, Matrix<Tp> b)
{
    if( a.rows != b.rows || a.cols != b.cols) { cerr << "ERRO!!! dimensoes incompativeis" << endl; }

    Matrix<Tp> result  =  Matrix<Tp>(a.rows, a.cols);

    for(int i = 0; i < a.rows; i++)
    {
        for(int j = 0; j < a.cols; j++)
        {
            result[i][j]  =  a[i][j] - b[i][j];
        }
    }

 return result;
}


/**
 * 
*/
template<typename Tp> void operator-=(Matrix<Tp> a, Matrix<Tp> b)
{
    a = a - b;
}


/**
 * produto matricial
*/
template<typename Tp> Matrix<Tp> operator*(Matrix<Tp> a, Matrix<Tp> b)
{
    if(a.cols != b.rows) { cerr << "ERRO!!! dimensoes invalidas\n"; }

    Matrix<Tp> result  =  Matrix<Tp>(a.rows, b.cols);
    for(int i = 0; i < a.rows; i++)
    {
        for(int j = 0; j < b.cols; j++)
        {
            Tp soma = (Tp)0;
            for(int k = 0; k < a.cols; k++)
            {
                soma += a[i][k] * b[k][j];
            }
            result[i][j] = soma;
        }
    }
    
 return result;
}


/**
 * produto por escalar
*/
template<typename Tp, typename Tp2> Matrix<Tp> operator*(Matrix<Tp> a, Tp2 b)
{
    Matrix<Tp> result  =  Matrix<Tp>(a.rows, a.cols);

    for(int i = 0; i < a.rows; i++)
    {
        for(int j = 0; j < a.cols; j++)
        {
            result[i][j] = a[i][j] * b;
        }
    }

 return result;
}


/**
 * 
*/
template<typename Tp, typename Tp2> Matrix<Tp> operator*(Tp2 b, Matrix<Tp> a)
{
    return a * b;
}


/**
 * 
*/
template<typename T> T* Matrix<T>::data()
{
    vector<T> dado;

    for(int i =0; i < this->rows; i++)
    {
        for(int j = 0; j < this->cols; j++)
        {
            dado.push_back( this->mat[i][j] );
        }
    }

 return dado.data();
}


/**
 * 
*/
template<typename Tp> bool operator==(Matrix<Tp> a, Matrix<Tp> b)
{
    if( a.rows != b.rows  ||  a.cols != b.cols ) { return false; }

    for(int i = 0; i < a.rows; i++)
    {
        for(int j = 0; j < a.cols; j++)
        {
            if( a[i][j] != b[i][j] ) { return false; }
        }
    }

 return true;
}


template<typename Tp, typename Tp2> Matrix<Tp> operator/(Matrix<Tp> a, Tp2 b)
{
    Matrix<Tp> result  =  Matrix<Tp>(a.rows, a.cols);

    for(int i = 0; i < a.rows; i++)
    {
        for(int j = 0; j < a.cols; j++)
        {
            result[i][j] = a[i][j] / b;
        }
    }

 return result;
}


template<typename Tp, typename Tp2> Matrix<Tp> operator/(Tp2 b, Matrix<Tp> a)
{
    return (a / b);
}



template<typename T> int Matrix<T>::escalona(int type)
{
    int cont = 0;

    if(type == 0){

        for(int i = 0; i < this->rows - 1; i++)
        {
            if(this->mat[i][i] == 0)  // ve se os elementos da diagonal principal é zero
            {
                for(int k = i + 1; k < this->rows; k++) // budcar linha que não soa zero
                {
                    if(this->mat[k][k] != 0)
                    {
                        for(int j = 0; j < this->cols; j++)
                        {
                            T aux = this->mat[i][j];
                            this->mat[i][j] = this->mat[k][j];
                            this->mat[k][j] = aux;
                        }
                        cont++;
                    }
                }
            }

            if(this->mat[i][i] != 0)
            {
                for(int j = i + 1; j < this->rows; j++)
                {
                    double factor = (-1.0) * this->mat[j][i] / this->mat[i][i];

                    for(int k = i; k < this->cols; k++)
                    {
                        this->mat[j][k] = this->mat[j][k] + (factor * this->mat[i][k]);
                    }
                }
            }
        }
    }
    
    else if(type == 1)
    {

        for(int i = this->rows - 1; i > 0; i--)
        {
            if(this->mat[i][i] == 0)  // ve se os elementos da diagonal principal é zero
            {
                for(int k = i - 1; k >= 0; k--) // budcar linha que não soa zero
                {
                    if(this->mat[k][k] != 0)
                    {
                        for(int j = 0; j < this->cols; j++)
                        {
                            T aux = this->mat[i][j];
                            this->mat[i][j] = this->mat[k][j];
                            this->mat[k][j] = aux;
                        }
                        cont++;
                    }
                }
            }

            if(this->mat[i][i] != 0)
            {
                for(int j = i; j > 0; j--)
                {
                    double factor = (-1.0) * this->mat[j][i] / this->mat[i][i];

                    for(int k = i; k < this->cols; k++)
                    {
                        this->mat[j][k] += (factor * this->mat[i][k]);
                    }

                    {
                        ////////
                        cout << "fator: " << factor << endl;//////
                        for(int i = 0; i < 3; i++)
                        {
                            for(int j = 0; j < 3; j++)
                            {
                                cout << this->mat[i][j] << "  ";
                            }
                            cout << endl;
                        }
                        ////////
                        
                    }
                }

            }

        }

    }

 return cont;
}












#endif