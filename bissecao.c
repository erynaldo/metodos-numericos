/*
Instituto Federal do Ceara - IFCE
Campus: Tiangua
Disciplina: Calculo Numerico
Professor: Lucas Campos Freitas
Aluno: Erinaldo Cardoso da Silva
 
Descricao: Implementacao do algoritmo do Metodo da Bissecao
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//FUNCAO
float f(float x) {
	return (log(x) + sin(2 * x));
}

//FUNCAO PRINCIPAL
int main(void) {
	float a, b, c, precisao, x, k_estima, erro;
	int k=0, max_i = 100;

	//TITULO DO PROGRAMA
	printf("\n  === METODO DA BISSECAO ===\n");

	//ENTRADA E LEITURA DE DADOS
	printf("\n  Informe o ponto 'a' do intervalo [a , b]: ");
	scanf("%f", &a);

	printf("  Informe o ponto 'b' do intervalo [%.1f , b]: ", a);
	scanf("%f", &b);

	printf("  Informe o valor da precisao: ");
	scanf("%f", &precisao);
    
	printf("\n  Intervalo definido [%.1f , %.1f]", a, b);
	printf("\n  Precisao informada = %f", precisao);

	k_estima = (log(b - a) - log(precisao))/log(2);

	if(f(a) * f(b) < 0){
		c = b - a;
		x = (a + b)/2;
		erro = fabs(f(x));
		
		if(c < precisao){
			// x = (a + b)/2;
			k++;
			
			//SAIDA DE DADOS
			printf("\n\n  --------------------------------------------------------------------------------------------------------------------------------");
	    	printf("\n  | K     | a            | b            | f(a)             | f(b)            | b - a          | x             | f(x)             |");
	    	printf("\n  --------------------------------------------------------------------------------------------------------------------------------");
			printf("\n    k = %d | a = %f | b = %f | f(a) = %f | f(b) = %f | b-a = %f | x%d = %f | f(x%d) = %f", k, a, b, f(a), f(b), c, k, x, k, f(x));
			printf("\n  --------------------------------------------------------------------------------------------------------------------------------");
			printf("\n\n  RAIZ ENCONTRADA = %f", x);
			printf("\n  Funcao f(x%d) = %f", k, f(x));
			printf("\n  Erro = %f", erro);
			printf("\n  Qtd de iteracoes = %d\n\n\n", k);

		} else {
			// k++;
			//SAIDA DE DADOS
			printf("\n  Qtd de iteracoes estimada = %.2f\n", k_estima);
			printf("\n  -----------------------------------------------------------------------------------------------------------------------------------");
	    	printf("\n  | K     | a            | b            | f(a)             | f(b)            | b - a          | x             | f(x)                |");
	    	printf("\n  -----------------------------------------------------------------------------------------------------------------------------------");
			printf("\n    k = %d | a = %f | b = %f | f(a) = %f | f(b) = %f | b-a = %f | x%d = %f | f(x%d) = %f", k, a, b, f(a), f(b), c, k, x, k, f(x));
			printf("\n  -----------------------------------------------------------------------------------------------------------------------------------");

			//ITERACAO
			while (c > precisao) {
			// while (fabs(f(x)) > precisao) {

				//CONDICAO PARA SABER ONDE VAI O VALOR DE X
				if(f(a) * f(x) < 0) {
					b = x;
				} else {
					a = x;
				}
				
				c = b - a;
				x = (a + b)/2;
				erro = fabs(f(x));
				k++;

				printf("\n    k = %d | a = %f | b = %f | f(a) = %f | f(b) = %f | b-a = %f | x%d = %f | f(x%d) = %f", k, a, b, f(a), f(b), c, k, x, k, f(x));
				printf("\n  -----------------------------------------------------------------------------------------------------------------------------------");
					
				//FORÇAR PARADA COM 100 ITERACOES, CASO A CONDICAO PRINCIPAL NAO OCORRA
				if(k >= max_i) {
					break;
				}

   			}
			
			//SAIDA DE DADOS
			printf("\n\n  RAIZ ENCONTRADA = %f", x);
			printf("\n  Funcao f(x%d) = %f", k, f(x));
			printf("\n  Erro = %f", erro);
			printf("\n  Qtd de iteracoes = %d\n\n\n", k);
		}

	} else {
		printf("\n\n  Nao existe raiz nesse intervaldo [%.1f , %.1f]\n\n\n", a, b);
	}

	system("pause");
	return 0;	
}
