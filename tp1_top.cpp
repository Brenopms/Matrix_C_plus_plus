#include <iostream>
#include "Matriz.h"
using namespace std;

int main() {
    Matriz Y;
    Matriz X(3,1), A(3,3,2), C(3,3,3);
    Matriz W = C;
    Matriz Z(A);
    int numeroLinhas = A.getRows();
    int numeroColunas = A.getCols();
    cout << "\nlin: " << numeroLinhas << "\ncol: " << numeroColunas<< endl;
		cout<< "C:\n"<< C<< endl;

		cout<< "C(2,2) = "<< C.getValue(2,2) << endl;

		C.setValue(2, 2, 0);
		cout<< "C(2,2) = 0:\n"<< C << endl;

		C.ones();
		cout<< "C.ones:\n"<< C<< endl;

    A.zeros(); // modifica todos os elementos de Y para o valor zero
    cout<< "A.zeros:\n"<< A<< endl;
    A.unit(); 	  // inicializa Y com a matriz identidade
    cout<< "A.unit:\n"<< A<< endl;
    C-=A; 	  // Subtração
    cout<< "C-=A:\n"<< C<< endl;
    A+=A; 	  // Soma
    cout<< "A+=A:\n"<< A<< endl;
    cout<< "Z:\n"<< Z<< endl;
    Z*=2; 	  // multiplicação por uma constante
    cout<< "Z*=2:\n"<< Z<< endl;
    C*=Z; 	  // multiplicação de matrizes
    cout<< "C*=Z:\n"<< C<< endl;
    Y=~X; 	  // A é igual a transposta de C
    cout<< "Y=~X:\n"<< Y<< endl;
    C=A+A;       // Soma
    cout<< "C=A+A:\n"<< C<< endl;
    A=C-A;	  // Subtração
    cout<< "A=C-A:\n"<< A<< endl;
    C=A*Z; 	  // multiplicação de matrizes
    cout<< "C=A*Z:\n"<< C<< endl;
    Matriz a(2,2,3), c(a);
    if (a == c)  // verifica a igualdade entre A e C
        cout << "As matrizes sao iguais" << endl;
    if(a != c)   // verifica a desigualdade entre A e C
            cout << "Erro!"<<endl;
    a.ones();
    if(a != c)   // verifica a desigualdade entre A e C
        cout << "As matrizes sao diferentes" << endl;
    if(a == c)   // verifica a desigualdade entre A e C
            cout << "Erro!"<<endl;
    //cin >> Y; 			// leitura de dados para dentro da matriz Y
  return 0;
}
