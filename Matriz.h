#ifndef MATRIZ_H
#define MATRIZ_H


#include <iostream>
#include <cstring>

using namespace std;

class Matriz
{
	int coluna, linha;
	double **valor;

  public:
	Matriz(int l = 0, int c = 0,
		   const double &v = 0); // contrutor com defout
	Matriz(const Matriz &);		 // contrutor de copia
	~Matriz();					 // detrutor

	Matriz &operator+=(const Matriz &);			  // soma duas  matrizes por referncia
	const Matriz operator+(const Matriz &) const; // soma duas matrizes
	Matriz &operator-=(const Matriz &);			  // subtrai duas matrizes por referencia
	const Matriz operator-(const Matriz &) const; // subtrai duas matrizes
	Matriz &operator*=(const Matriz &);			  // multiplica duas matrizes por referencia
	const Matriz operator*(const Matriz &)const;  // multiplica duas matrizes
	Matriz &operator*=(const double &);			  // multiplica uma matrize  por referencia
	const Matriz operator*(const double &)const;  // multiplica uma matriz por uma constante
	const Matriz operator~() const;				  // operador para transpor matriz
	const bool operator==(const Matriz &) const;  // testa a igualdade das matrizes
	const bool operator!=(const Matriz &) const;  // testa a desigualdade das matrizes

	friend ostream &operator<<(ostream &, const Matriz &); // impriome a matriz por operdor
	friend istream &operator>>(istream &, Matriz &);	   // inica a matriz com os valores desejados
};

#endif