/*
Instituto Federal do Ceara - IFCE
Campus: Tiangua
Disciplina: Calculo Numerico
Professor: Lucas Campos Freitas
Aluno: Erinaldo Cardoso da Silva
 
Descricao: Implementacao do algoritmo do Metodo da Newton-Raphson
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//FUNCAO
float f(float x) {
	return (log(x) + sin(2 * x));
}

//FUNCAO DERIVADA
float f2(float x) {
	return ((1/x) + (cos(2 * x) * 2));
}

//FUNCAO PRINCIPAL
int main(void) {
	float a, b, precisao, x, x0, erro;
	int k=0, max_i = 100;

	//TITULO DO PROGRAMA
	printf("\n  === METODO DE NEWTON-RAPHSON ===\n");

	//ENTRADA E LEITURA DE DADOS
	printf("\n  Informe o ponto 'a' do intervalo [a , b]: ");
	scanf("%f", &a);

	printf("  Informe o ponto 'b' do intervalo [%.1f , b]: ", a);
	scanf("%f", &b);

	printf("  Informe o valor da precisao: ");
	scanf("%f", &precisao);

    x = (a + b)/2;

	printf("\n  Intervalo definido [%.1f , %.1f]", a, b);
	printf("\n  Aproximacao inicial = %.2f", x);
	printf("\n  Precisao informada = %f\n", precisao);
	
	if((f(a) * f(b)) < 0){
		x0 = f(x);
		erro = fabs(x0 - precisao);
			
		//SAIDA DE DADOS
		printf("\n\n  --------------------------------------------------------------");
    	printf("\n  | K     | x             | f(x)             | erro            |");
    	printf("\n  --------------------------------------------------------------");
		printf("\n    k = %d | x%d = %f | f(x%d) = %f | erro = %f", k, k, x, k, x0, erro);
		printf("\n  --------------------------------------------------------------\n");

		//ITERACAO E CONDICAO DE PARADA
		while (fabs(x0) >= precisao) {
			// x = x - ((log(x) + sin(2 * x))/( (1/x) + (cos(2 * x) * 2)));
			x = x - (f(x)/f2(x));
			x0 = f(x);
			erro = fabs(x0 - precisao);
			k++;

			printf("\n    k = %d | x%d = %f | f(x%d) = %f | erro = %f", k, k, x, k, x0, erro);
			printf("\n  --------------------------------------------------------------");
			
			//FORÇAR PARADA COM 100 ITERACOES, CASO A CONDICAO PRINCIPAL NAO OCORRA
			if(k >= max_i) {
				break;
			}

			}
		
		//SAIDA DE DADOS
		printf("\n\n  RAIZ ENCONTRADA = %f", x);
		printf("\n  Erro = %f", erro);
		printf("\n  Qtd de iteracoes = %d\n", k);

	} else {
		printf("\n\n  Nao existe raiz nesse intervaldo [%.1f , %.1f]\n\n\n", a, b);
	}
	
	printf("\n\n");

	system("pause");
	return 0;	
}