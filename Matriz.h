#
ifndef TP1_H# define TP1_H

#include <iostream>

using namespace std;#include <cstring>

class Matriz {
  int coluna, linha;
  double ** valor;
  public:
    Matriz(int l = 0, int c = 0,
      const double & v = 0); // contrutor com defout 
  Matriz(const Matriz & ); // contrutor de copia
  ~Matriz(); // detrutor

  Matriz & operator += (const Matriz & ); // soma duas  matrizes por referncia
  const Matriz operator + (const Matriz & ) const; // soma duas matrizes
  Matriz & operator -= (const Matriz & ); // subtrai duas matrizes por referencia
  const Matriz operator - (const Matriz & ) const; // subtrai duas matrizes
  Matriz & operator *= (const Matriz & ); // multiplica duas matrizes por referencia
  const Matriz operator * (const Matriz & ) const; // multiplica duas matrizes
  Matriz & operator *= (const double & ); // multiplica uma matrize  por referencia
  const Matriz operator * (const double & ) const; // multiplica uma matriz por uma constante
  const Matriz operator~() const; // operador para transpor matriz
  const bool operator == (const Matriz & ) const; // testa a igualdade das matrizes
  const bool operator != (const Matriz & ) const; // testa a desigualdade das matrizes

  friend ostream & operator << (ostream & , const Matriz & ); // impriome a matriz por operdor
  friend istream & operator >> (istream & , Matriz & ); // inica a matriz com os valores desejados 
};

Matriz::Matriz(int l, int c,
  const double & v) {
  coluna = c;
  linha = l;
  valor = new double * [linha]; // cria 1 velor linha
  for (int i = 0; i < l; i++) {
    valor[i] = new double[coluna]; // cria os veotre coluna de cada linha 
    for (int j = 0; j < c; j++)
      valor[i][j] = v; // atribui valor aos elemenos da matriz
  }
}

Matriz::Matriz(const Matriz & m) {
  coluna = m.coluna;
  linha = m.linha;
  valor = new double * [linha];; // cria 1 velor linha para a nova matriz
  for (int i = 0; i < linha; i++) {
    valor[i] = new double[coluna]; // cria os veotre coluna de cada linha para a nova matriz 
    for (int j = 0; j < coluna; j++)
      valor[i][j] = m.valor[i][j]; // copia os valor para a nova matriz
  }
}

Matriz::~Matriz() {
  delete[] valor[coluna]; // libera espa�o de memoria alocado
  delete[] valor; // libera espa�o de memoria alocado
}

ostream & operator << (ostream & out,
  const Matriz & ref) {
  for (int i = 0; i < ref.linha; i++) { // anda pela linha da matriz
    for (int j = 0; j < ref.coluna; j++) // anda pela coluna da matriz
      out << "|" << ref.valor[i][j]; // imprime os valores de cada elemento
    out << "|" << endl;
  }
  return out;
}

istream & operator >> (istream & in , Matriz & ref) {
  for (int i = 0; i < ref.linha; i++) { // anda pela linha da matriz
    for (int j = 0; j < ref.coluna; j++) { // anda pela coluna da matriz
      cout << "(" << i + 1 << "," << j + 1 << "): "; in >> ref.valor[i][j]; // atribui os valores arbritarios nos elemos da matriz
    }
  }
}

Matriz & Matriz::operator += (const Matriz & opr) {
  if ((linha != opr.linha) || (coluna != opr.coluna)) {
    cout << "impossive realizar essa opera��o\nas matrizes nao possuem a mesma dimensao" << endl;
    return *this;
  }
  for (int i = 0; i < linha; i++) { // anda pela linha da matriz
    for (int j = 0; j < coluna; j++) // anda pela coluna da matriz
      valor[i][j] += opr.valor[i][j]; // soma os valores dos elemetos das matrizes um a um
  }
  return *this;
}

const Matriz Matriz::operator + (const Matriz & opr) const {
  Matriz m( * this);
  m += opr;
  return m;
}

Matriz & Matriz::operator -= (const Matriz & opr) {
  for (int i = 0; i < linha; i++) { //anda pela linha da matriz
    for (int j = 0; j < coluna; j++)
      valor[i][j] -= opr.valor[i][j]; //subtria os valores dos elemetos das matrizes um a um
  }
  return *this;
}

const Matriz Matriz::operator - (const Matriz & opr) const {
  Matriz m( * this);
  m -= opr;
  return m;
}

Matriz & Matriz::operator *= (const Matriz & opr) {
  Matriz aux(linha, opr.coluna, 0);
  if (coluna != opr.linha) {
    cout << "nao eh possivel realizar a multipla��o\nnumero de colunas diferete do numero de lihas" << endl;
    return *this;
  }
  for (int i = 0; i < linha; i++) { // anda pela linha da matriz	
    for (int j = 0; j < opr.coluna; j++) { // anda pela coluna da matriz
      for (int k = 0; k < opr.linha; k++) // possibilita a multiplica��o linha por coluna
        aux.valor[i][j] += valor[i][k] * opr.valor[k][j]; // guarda soma da multiplica��o dos elementos linha de this pelos elementos coluna de opr	
    }
  }
  * this = aux;
  return *this;
}

const Matriz Matriz::operator * (const Matriz & opr) const {
  Matriz m( * this);
  m *= opr;
  return m;
}

Matriz & Matriz::operator *= (const double & n) {
  for (int i = 0; i < linha; i++) { //anda pela linha da matriz
    for (int j = 0; j < coluna; j++) //anda pela coluna da matriz
      valor[i][j] *= n; //multiplica os valores dos elemetos da matrz um a um
  }
  return *this;
}

const Matriz Matriz::operator~() const {
  Matriz m(coluna, linha);
  cout << m << endl;
  for (int i = 0; i < m.linha; i++) {
    for (int j = 0; j < m.coluna; j++)
      m.valor[i][j] = valor[j][i]; // copia os valores  traspostas para a nova matriz
  }
  cout << m << endl;
  return m;
}

const bool Matriz::operator == (const Matriz & ref) const {
  if ((linha != ref.linha) || (coluna != ref.coluna))
    return false;
  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      if (valor[i][j] != ref.valor[i][j])
        return false;
    }
  }
  return true;
}

const bool Matriz::operator != (const Matriz & ref) const {
  if ((linha != ref.linha) || (coluna != ref.coluna))
    return true;
  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      if (valor[i][j] != ref.valor[i][j])
        return true;
    }
  }
  return false;
}

# endif