#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>

using namespace std;


#ifndef CMATRIZ_H_INCLUDED
#define CMATRIZ_H_INCLUDED


class matriz{


    public:

        int row = 0;
        int column = 0;
        vector<double> linha;

        matriz(int _row, int _column);
        matriz(int ordem);
        matriz(){}

        friend matriz operator+(matriz& a, matriz& b);
        friend void operator+=(matriz& a, matriz& b);
        friend matriz operator-(matriz& a, matriz& b);
        friend void operator-=(matriz& a, matriz& b);
        friend matriz operator*(double c, matriz b);
        friend matriz operator*(matriz b, double c);
        friend void operator*=(matriz& b, double c);
        friend matriz operator*(matriz& a, matriz& b);
        friend matriz operator/(matriz b, double c);
        friend bool operator==(matriz a, matriz b);
        friend ostream& operator<<(ostream& os, const matriz m);
        friend istream& operator>>(istream& os, matriz& m);
        void operator=(const matriz a);
        void operator=(double* l);
        vector<double> operator[](int _row);
        

        void print(const char* mensage = NULL);
        void read(const char* mensage = NULL);
        int escalonar();
        double det();
        matriz t();
        matriz inversa();
        int triangular();
        int posto();
        matriz cof();
        matriz adj();
        
 
    private:

        double** m;
        //vector<double> linha;

        friend void troca(double& a, double& b);
        void escalona__();

};

//--------------- construtor ------------------

matriz::matriz(int _row, int _column)
{
    this->row = _row; this->column = _column;

    m = new double* [_row];
    for(int i = 0; i < _row; i++){ m[i] = new double [_column];  }
}

matriz::matriz(int ordem)
{
   this->row = ordem; this->column = ordem;

    m = new double* [ordem];
    for(int i = 0; i < ordem; i++){ m[i] = new double [ordem];  } 
}


//------------  operadores ------------------

matriz operator+(matriz& a, matriz& b)
{
    if(a.row != b.row  &&  a.column != b.column)
    { cout << "dimensoes invalido para operacao soma!!!" << endl; exit(1); }

    matriz aux(a.row, a.column);

    for(int i = 0; i < a.row; i++)
    {
        for(int j = 0; j < a.column; j++)
        {
            aux.m[i][j] = a.m[i][j] + b.m[i][j];
        }
    }

 return aux;
}

void operator+=(matriz& a, matriz& b)
{
    if(a.row != b.row  &&  a.column != b.column)
    { cout << "dimensoes invalido para operacao soma!!!" << endl; exit(1); }

    for(int i = 0; i < a.row; i++)
    {
        for(int j = 0; j < a.column; j++)
        {
            a.m[i][j] = a.m[i][j] + b.m[i][j];
        }
    }

}

matriz operator-(matriz& a, matriz& b)
{
    if(a.row != b.row  &&  a.column != b.column)
    { cout << "dimensoes invalido para operacao subtracao!!!" << endl; exit(1); }

    matriz aux(a.row, a.column);

    for(int i = 0; i < a.row; i++)
    {
        for(int j = 0; j < a.column; j++)
        {
            aux.m[i][j] = a.m[i][j] - b.m[i][j];
        }
    }

 return aux;
}

void operator-=(matriz& a, matriz& b)
{
    if(a.row != b.row  &&  a.column != b.column)
    { cout << "dimensoes invalido para operacao subtracao!!!" << endl; exit(1); }

    for(int i = 0; i < a.row; i++)
    {
        for(int j = 0; j < a.column; j++)
        {
            a.m[i][j] = a.m[i][j] - b.m[i][j];
        }
    }
}

matriz operator*(double c, matriz b)
{
    matriz aux(b.row, b.column);


    for(int i = 0; i < b.row; i++)
    {
        for(int j = 0; j < b.column; j++)
        {
            aux.m[i][j] = c * b.m[i][j];
        }
    }
 
 return aux;
}

matriz operator*(matriz b, double c)
{
    matriz aux(b.row, b.column);

    for(int i = 0; i < b.row; i++)
    {
        for(int j = 0; j < b.column; j++)
        {
            aux.m[i][j] = c * b.m[i][j];
        }
    }
 
 return aux;
}

void operator*=(matriz& b, double c)
{
    for(int i = 0; i < b.row; i++)
    {
        for(int j = 0; i < b.column; j++)
        {
            b.m[i][j] = c * b.m[i][j];
        }
    }
}

matriz operator*(matriz& a, matriz& b)
{
    if(a.column != b.row) {cout << "dimensoes incompativeis para operacao multiplicacao" << endl; exit(1);}

    matriz ans(a.row, b.column);

    for(int i = 0; i < a.row; i++)
    {
        for(int j = 0; j < b.column; j++)
        {
            double soma = 0.0;
            for(int k = 0; k < a.column; k++)
            {
                soma += a.m[i][k] * b.m[k][j];
            }
            ans.m[i][j] = soma;
        }
    }

 return ans;
}

matriz operator/(matriz b, double c)
{
    matriz aux(b.row, b.column);

    for(int i = 0; i < b.row; i++)
    {
        for(int j = 0; j < b.column; j++)
        {
            aux.m[i][j] = b.m[i][j] / c;
        }
    }
 
 return aux;
}

void troca(double& a, double& b)
{
    double aux = a;     a = b;    b = aux;
}

bool operator==(matriz a, matriz b)
{
    if(a.column!=b.column || a.row!=b.row) {return false;}

    for(int i = 0; i < a.row; i++)
    {
        for(int j = 0; j < a.column; j++)
        {
            if(a.m[i][j] != b.m[i][j]) {return false;}
        }
    }
 return true;
}

void matriz::operator=(const matriz a)
{
    this->row = a.row;  this->column = a.column;
    
    this->m = new double* [a.row];
    for(int i = 0; i < a.row; i++) {this->m[i] = new double [a.row];}

    for(int i = 0; i < a.row; i++)
    {
        for(int j = 0; j < a.column; j++)
        {
            this->m[i][j] = a.m[i][j];
        }
    }
}

void matriz::operator=(double* l)
{
    if(this->row==0 && this->column==0) {cout << "matriz sem dimensoes" << endl; exit(1);}

    int c = 0;
    for(int i = 0; i < this->row; i++)
    {
        for(int j = 0; j < this->column; j++)
        {
            this->m[i][j] = l[c];
            c++;
        }
    }

}

ostream& operator<<(ostream& os, const matriz m)
{
    for(int i = 0; i < m.row; i++)
    {
        for(int j = 0; j < m.column; j++)
        {
            os << setw(4) << m.m[i][j] << "  ";
        }
        
        os << endl;
    }

    os << endl << endl;

 return os;
}

istream& operator>>(istream& os, matriz& m)
{
    double val;
    for(int i = 0; i < m.row; i ++)
    {
        for(int j = 0; j < m.column; j++)
        {
            os >> val;
            m.m[i][j]  =  val;
        }
    }
 return os;
}

vector<double> matriz::operator[](int _row)
{
    for(int i = 0; i < this->column; i++){
        this->linha.push_back( this->m[_row][i] );
    }

 return this->linha;
}


//-------------- funcoues membros -------------------

void matriz::print(const char* mensagem)
{
    if( mensagem ) { cout << mensagem << endl; }
    
    for(int i = 0; i < this->row; i++)
    {
        for(int j = 0; j < this->column; j++)
        {
            cout << setw(4) << m[i][j] << "  ";
        }
        
        cout << endl;
    } 
    cout << endl << endl; 
}

void matriz::read(const char* mensagem)
{
    if( mensagem ) { cout << mensagem << endl; }

    for(int i = 0; i < this->row; i++)
    {
        for(int j = 0; j < this->column; j++)
        {
            cin >> this->m[i][j];
        }
    }
}

int matriz::escalonar()
{
    int cont = 0;
    for(int i = 0; i < this->row - 1; i++)
    {
        if(this->m[i][i] == 0)  // ve se os elementos da diagonal principal é zero
        {
            for(int k = i + 1; k < this->row; k++) // budcar linha que não soa zero
            {
                if(this->m[k][k] != 0)
                {
                    for(int j = 0; j < this->column; j++)
                    {
                        troca(this->m[i][j], this->m[k][j]);
                    }
                    cont++;
                }
            }
        }

        if(this->m[i][i] != 0)
        {
            for(int j = i + 1; j < this->row; j++)
            {
                double factor = (-1.0) * this->m[j][i] / this->m[i][i];

                for(int k = i; k < this->column; k++)
                {
                    this->m[j][k] = this->m[j][k] + (factor * this->m[i][k]);
                }
            }
        }
    }

 return cont;
}

int matriz::triangular()
{
    int cont = 0;

    for(int i = 0; i < this->column - 1; i++)
    {
        if(this->m[i][i] == 0)
        {
            for(int j = i + 1; j < this->column; j++)
            {
                if(this->m[j][j])
                {
                    for(int k = 0; k < this->row; k++)
                    {
                        troca(this->m[k][j], this->m[k][i]);
                    }
                    cont++;
                }
            }
        }

        if(this->m[i][i] != 0)
        {
            for(int j = i + 1; j < this->column; j++)
            {
                double factor = (-1.0) * this->m[i][j] / this->m[i][i];

                for(int k = i; k < this->column; k++)
                {
                    this->m[k][j] = this->m[k][j] + ( factor * this->m[k][i] );
                }
            }
        }
    }

 return cont;
}

void matriz::escalona__()
{
    for(int i = this->row - 1; i > 0; i--)
    {
        for(int k = i - 1; k >= 0; k--)
        {
            double fator = (-1) * this->m[k][i] / this->m[i][i];

            for(int j = i; j < 2 * this->row; j++)
            {
                this->m[k][j] = this->m[k][j] + (fator * this->m[i][j] );
            }
        }
    }

    for(int i = 0; i < this->row; i++)
    {
        if(this->m[i][i] != 1) // && m[i][i] != 0 
        {
            double fator = 1.0 / this->m[i][i];

            for(int k = 0; k < this->column; k++)
            {
                this->m[i][k] = this->m[i][k] * fator;
            }
        }
    }
}

double matriz::det()
{
    if(this->column != this->row){ cout << "a matriz nao eh quadrada" << endl; exit(1);}
    
    matriz aux(this->column);

    for(int i= 0; i < this->column; i++)
    {
        for(int j = 0; j < this->column; j++)
        {
            aux.m[i][j] = this->m[i][j];
        }
    }

    int troca = aux.escalonar();

    double product = 1.0;
    for(int i = 0; i < this->row; i++)
    {
        product = product * aux.m[i][i];
    }
    
 return (troca % 2 == 0) ? product : -1 * product;
}

matriz matriz::t()
{
    matriz aux(this->column, this->row);

    for(int i = 0; i < this->column; i++)
    {
        for(int j = 0; j < this->row; j++)
        {
            aux.m[i][j] = this->m[j][i];
        }
    }    

 return aux;
}

matriz matriz::inversa()
{
    if(this->column != this->row ){ cout << "matriz nao eh quadrada!!!" << endl; exit(1);}

    matriz aux(this->row, 2 * this->column);

    for(int i = 0; i < this->row; i++)
    {
        for(int j = 0; j < 2 * this->column; j++)
        {
            if(j < this->column)
            {
                aux.m[i][j] = this->m[i][j];
            }
            else{
                aux.m[i][j] = (j - this->column != i) ? 0 : 1;
            }
        }
    }

    aux.escalonar();
    aux.escalona__();

    matriz resp(this->row);

    for(int i = 0; i < this->row; i++)
    {
        for(int j = 0; j < this->column; j++)
        {
            resp.m[i][j] = aux.m[i][j + this->column];
        }
    }

 return resp;   /// return resp;
}

int matriz::posto()
{
    if(this->row != this->column) {cout << "a matriz nao eh quadrada" << endl; exit(1);}

    this->escalonar();
    this->triangular();

    this->print("teste 001:");

    int cont = 0;
    for(int i = 0; i < this->column; i++) { if(this->m[i][i] != 0) { cont++; } }

    this->print("teste 001:");

 return cont;
}

double** corta_matriz(double** m, int ordem, int row, int column) 
{   
    double** m2 = new double* [ordem-1];
    for(int i = 0; i < ordem-1; i++){ m2[i] = new double [ordem-1]; }

    int l = 0, c = 0;
    for(int i = 0; i < ordem; i++)
    {
        for(int j = 0; j < ordem; j++)
        {
            if(i != row && j != column)
            {
                *( *(m2 + l) + c) = m[i][j];
                c++;
            }

            if(c == ordem-1){
                l++;
                c = 0;
            }
        }

    }

 return m2;
}

matriz matriz::cof()
{
    if(this->row != this->column) { cout << "ERRO!!!" << endl; exit(1);}

    matriz resp(this->row, this->column);
    matriz aux(this->row-1, this->column-1);
    matriz aux2(this->row, this->column);
    

    for(int i = 0; i < this->row; i++)
    {
        for(int j = 0; j < this->column; j++)
        {
            aux2.m[i][j] = this->m[i][j];
        }
    }


    for(int i = 0; i < this->row; i++)
    {
        for(int j = 0; j < this->column; j++)
        {
            aux.m = corta_matriz(aux2.m, this->row, i, j);
           
            double det = aux.det();
            
            resp.m[i][j] = ( !((i+j+2) % 2) ) ? det : (-1.0) * det; 
        }
    }

 return resp;
}

matriz matriz::adj()
{
    matriz aux = this->cof();
    aux = aux.t();

 return aux;
}

#endif