#include <iostream>
#include "Matriz.h"
using namespace std;

int main() {
	Matriz Y;
	Matriz X(3,3,1);
	Matriz A(3,7,2);
	Matriz C(3,3,2);
	//A(3,3,2), C(3,3,1);
	Matriz W = C;
	Matriz Z(A);

	cout << A << "\n\nW =\n" << W << endl;
    int numeroLinhas = A.getRows();
	int numeroColunas = A.getCols();
	cout << "\nlin: " << numeroLinhas << "\ncol: " << numeroColunas<< endl;
	//Y.unit(); // inicializa Y com a matriz identidade
	//A(2,1)=10; // altera o valor de uma posi��o de A
	//Y.zeros(); // modifica todos os elementos de Y para o valor zero
	//C+=C; // Soma
	cout<< "C:\n"<< C<< endl;
	C.ones();
	cout<< "C:\n"<< C<< endl;
	//C-=A; // Subtra��o
	//cout<< "C:\n"<< C<< endl;
	//A=C-A; // Subtra��o
	//cout<< "A:\n"<< A<< endl;
	//A+=A; // Soma
	//cout<< "A:\n"<< A<< endl;
  //A=~Z; // A � igual a transposta de C
  //cout<< "A:\n"<< A<< endl;
	//X.ones(); // modifica todos os elementos de X com 1s
	//X*=2; // multiplica��o por uma constante
	//cout<< "X:\n"<< X<< endl;
	//C=A*X; // multiplica��o de matrizes
	//cout<< "C:\n"<< C<< endl;
	//C*=X; // multiplica��o de matrizes
  //if (A == C) // verifica a igualdade entre A e C
	//cout<<"1\n";
	//if(X != Y) // verifica a desigualdade entre A e C
  //cout<<"2\n";
	//cout<< "C:\n"<< C<< endl; // Impress�o de matrizes
  //cin>>Y; // leitura de dados para dentro da matriz Y
  return 0;
}
