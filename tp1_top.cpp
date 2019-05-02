#include <iostream>
#include "Matriz.h"
using namespace std;

int main() {
	Matriz Y;
	Matriz X(3,1,1), A(3,3,2), C(3,3,1);
	Matriz W = C;
	Matriz Z(A);
	
	//int numeroLinhas = A.getRows();
	//int numeroColunas = A.getCols();
	//Y.unit(); // inicializa Y com a matriz identidade
	//A(2,1)=10; // altera o valor de uma posição de A
	//Y.zeros(); // modifica todos os elementos de Y para o valor zero
	//C=A+A; // Soma
	//cout<< "C:\n"<< C<< endl;
	//C-=A; // Subtração
	//cout<< "C:\n"<< C<< endl;
	//A=C-A; // Subtração
	//cout<< "A:\n"<< A<< endl;
	//A+=A; // Soma
	//cout<< "A:\n"<< A<< endl;
  //A=~Z; // A é igual a transposta de C
  //cout<< "A:\n"<< A<< endl;
	//X.ones(); // modifica todos os elementos de X com 1s
	//X*=2; // multiplicação por uma constante
	//cout<< "X:\n"<< X<< endl;
	//C=A*X; // multiplicação de matrizes
	//cout<< "C:\n"<< C<< endl;
	//C*=X; // multiplicação de matrizes
  //if (A == C) // verifica a igualdade entre A e C
	//cout<<"1\n";
	//if(X != Y) // verifica a desigualdade entre A e C
  //cout<<"2\n";
	//cout<< "C:\n"<< C<< endl; // Impressão de matrizes
  //cin>>Y; // leitura de dados para dentro da matriz Y
}
