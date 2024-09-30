#include <stdio.h>

int print_int(int numero)
{
	numero = 5;
	return (numero);
}

int main(void)
{
	int numero;
	int resposta;

	resposta = print_int(numero);
	printf("%i", resposta);
	return(0);
}



//inteiro  == int
//character == char 
//string == char[100] 