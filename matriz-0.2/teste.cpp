/////////////

#include "matriz.h"

int main(int argc, const char** argv)
{   
    Matrix<int> a  =  Matrix<int>(3,3);
    //Matrix<int> b  =  Matrix<int>(3,3);

    a.read("a");
    //b.read("b");

    int troca  =  a.escalona(1);

    cout << "\n\n" << a << "\n\n\n";

    cout << troca << endl;


}