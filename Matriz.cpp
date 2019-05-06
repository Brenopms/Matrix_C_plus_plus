#include "Matriz.h"

/*Construtor da classe, chamado por Matriz X(3,3,1),
 onde o primeiro valor e o numero de linhas,
 o segundo e numero de colunas
 e o terceiro e o valor de cada elemento
*/
Matriz::Matriz(int l, int c,
			   const double &v)
{
	coluna = c;
	linha = l;
	valor = new double *[linha]; // cria 1 velor linha
	for (int i = 0; i < l; i++)
	{
		valor[i] = new double[coluna]; // cria os veotre coluna de cada linha
		for (int j = 0; j < c; j++)
			valor[i][j] = v; // atribui valor aos elemenos da matriz
	}
}

// Construtor da classe que recebe uma matriz por referencia e faz uma copia de seus valores
Matriz::Matriz(const Matriz &m)
{
	coluna = m.coluna;
	linha = m.linha;
	valor = new double *[linha];
	// cria 1 velor linha para a nova matriz
	for (int i = 0; i < linha; i++)
	{
		valor[i] = new double[coluna]; // cria os veotre coluna de cada linha para a nova matriz
		for (int j = 0; j < coluna; j++)
			valor[i][j] = m.valor[i][j]; // copia os valor para a nova matriz
	}
}

//Destrutor da classe. Libera o espaco alocado da matriz
Matriz::~Matriz()
{
	delete[] valor[coluna]; // libera espa�o de memoria alocado
	delete[] valor;			// libera espa�o de memoria alocado
}

//Retorna  o numero de linhas da matriz
const int& Matriz::getRows(){
    return linha;
}

//Retorna  o numero de colunas da matriz
const int& Matriz::getCols(){
    return coluna;
}

//Faz com que a matriz seja igual uma matriz identidade
void Matriz::unit(){
    if(linha != coluna)
        cout << "\nFormato invalido!\nA matriz identidade deve ter o mesmo numero de linhas e colunas." << endl;
    else{
        for (int i = 0; i < linha; i++)
        {										// anda pela linha da matriz
            for (int j = 0; j < coluna; j++)	// anda pela coluna da matriz
                valor[i][j] = 0;

            valor[i][i] = 1;
        }
    }
}

//Substitui todos os valores da matriz por zero
void Matriz::zeros(){
    for (int i = 0; i < linha; i++)
	{										// anda pela linha da matriz
		for (int j = 0; j < coluna; j++)	// anda pela coluna da matriz
			valor[i][j] = 0;
	}
}

//Substitui todos os valores da matriz por 1
void Matriz::ones(){
    for (int i = 0; i < linha; i++)
	{										// anda pela linha da matriz
		for (int j = 0; j < coluna; j++)	// anda pela coluna da matriz
			valor[i][j] = 1;
	}
}

//Sobrecarga do operador de saida, fazendo com que a matriz seja impressa formatada na tela
ostream &operator<<(ostream &out, const Matriz &ref)
{
	for (int i = 0; i < ref.linha; i++)
	{										 // anda pela linha da matriz
		for (int j = 0; j < ref.coluna; j++) // anda pela coluna da matriz
			out << "|" << ref.valor[i][j];   // imprime os valores de cada elemento
		out << "|" << endl;
	}
	return out;
}

//Sobrecarga do operador de entrada, substituindo os valores da matriz
istream &operator>>(istream &in, Matriz &ref)
{
	for (int i = 0; i < ref.linha; i++)
	{ // anda pela linha da matriz
		for (int j = 0; j < ref.coluna; j++)
		{ // anda pela coluna da matriz
			cout << "(" << i + 1 << "," << j + 1 << "): ";
			in >> ref.valor[i][j]; // atribui os valores arbritarios nos elemos da matriz
		}
	}
	return in;
}

//Sobrecarga do operador de +=, fazendo com o que os valores da matriz sejam somados e igualados
Matriz &Matriz::operator+=(const Matriz &opr)
{
	if ((linha != opr.linha) || (coluna != opr.coluna))
	{
		cout << "impossivel realizar essa operacao\nAs matrizes nao possuem a mesma dimensao" << endl;
		return *this;
	}
	for (int i = 0; i < linha; i++)
	{										// anda pela linha da matriz
		for (int j = 0; j < coluna; j++)	// anda pela coluna da matriz
			valor[i][j] += opr.valor[i][j]; // soma os valores dos elemetos das matrizes um a um
	}
	return *this;
}

// Sobrecarga do operador de soma, fazendo com o que o a soma ocorra em cada uma das posicoes da matriz
const Matriz Matriz::operator+(const Matriz &opr) const
{
	Matriz m(*this);
	m += opr;
	return m;
}

//Sobrecarga do operador de -=, fazendo com que os valores da matriz sejam subtraidos e igualados
Matriz &Matriz::operator-=(const Matriz &opr)
{
	for (int i = 0; i < linha; i++)
	{ //anda pela linha da matriz
		for (int j = 0; j < coluna; j++)
			valor[i][j] -= opr.valor[i][j]; //subtria os valores dos elemetos das matrizes um a um
	}
	return *this;
}

//Sobrecarga do operador de subtracao, fazendo com o que o a subtracao ocorra em cada uma das posicoes da matriz
const Matriz Matriz::operator-(const Matriz &opr) const
{
	Matriz m(*this);
	m -= opr;
	return m;
}

//Sobrecarga do operador de *=, fazendo com que ocorra uma multiplicacao de matrizes 
Matriz &Matriz::operator*=(const Matriz &opr)
{
	Matriz aux(linha, opr.coluna, 0);
	if (coluna != opr.linha)
	{
		cout << "nao e possivel realizar a multiplicacao\nnumero de colunas diferete do numero de linhas" << endl;
		return *this;
	}
	for (int i = 0; i < linha; i++)
	{ // anda pela linha da matriz
		for (int j = 0; j < opr.coluna; j++)
		{														  // anda pela coluna da matriz
			for (int k = 0; k < opr.linha; k++)					  // possibilita a multiplica��o linha por coluna
				aux.valor[i][j] += valor[i][k] * opr.valor[k][j]; // guarda soma da multiplica��o dos elementos linha de this pelos elementos coluna de opr
		}
	}
	*this = aux;
	return *this;
}

//Sobrecarga do operador de subtracao, fazendo com o que o a multiplicacao ocorra em cada uma das posicoes da matriz
const Matriz Matriz::operator*(const Matriz &opr) const
{
	Matriz m(*this);
	m *= opr;
	return m;
}

//Sobrecarga  do operador *=, que permite a multiplicacao de todos os valores da matriz por uma constante
Matriz &Matriz::operator*=(const double &n)
{
	for (int i = 0; i < linha; i++)
	{									 //anda pela linha da matriz
		for (int j = 0; j < coluna; j++) //anda pela coluna da matriz
			valor[i][j] *= n;			 //multiplica os valores dos elemetos da matrz um a um
	}
	return *this;
}

// Operador para realizar a transposicao das matrizes
const Matriz Matriz::operator~() const
{
	Matriz m(coluna, linha);
	for (int i = 0; i < m.linha; i++)
	{
		for (int j = 0; j < m.coluna; j++)
			m.valor[i][j] = valor[j][i]; // copia os valores  traspostas para a nova matriz
	}
	return m;
}

//Sobrecarga do operador de igualdade, checando a igualdade de cada um dos elementos das duas matrizes
const bool Matriz::operator==(const Matriz &ref) const
{
	if ((linha != ref.linha) || (coluna != ref.coluna))
		return false;
	for (int i = 0; i < linha; i++)
	{
		for (int j = 0; j < coluna; j++)
		{
			if (valor[i][j] != ref.valor[i][j])
				return false;
		}
	}
	return true;
}

//Sobrecarga do operador de diferenca, checando a igualdade de cada um dos elementos das duas matrizes
const bool Matriz::operator!=(const Matriz &ref) const
{
	if ((linha != ref.linha) || (coluna != ref.coluna))
		return true;
	for (int i = 0; i < linha; i++)
	{
		for (int j = 0; j < coluna; j++)
		{
			if (valor[i][j] != ref.valor[i][j])
				return true;
		}
	}
	return false;
}
