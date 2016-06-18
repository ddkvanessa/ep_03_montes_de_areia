/*meuep < minhaentrada.txt > minhasaida.txt*/

/*clear && gcc -Wall -ansi -O2 -pedantic ep.c -o ep && ./ep*/

#include <stdio.h>
/* dimensao maxima da matriz*/
#define MAX  128

/*declaracao das variaveis*/

/*aqui comeca as funcoes do programa*/

/*funcoes definidas no enunciado do ep*/

/*esta função coloca zero em todas as posicoes da matriz tab de tamanho nlin x ncol*/
void zere_tabuleiro(int tabuleiro[MAX][MAX], int nlin, int ncol);

/*esta função deve ler os valores da entrada (como descrito na especificação da entrada) e inicializar o tabuleiro e as variáveis (externas) nlin e ncol com os valores correspondentes.*/
void leia_configuracao_inicial(int tabuleiro[MAX][MAX], int *nlin, int *ncol);

/*essa função imprime o tabuleiro no formato utilizado nos exemplos acima*/
void imprima_tabuleiro(int tabuleiro[MAX][MAX], int nlin, int ncol);

int espalhe(int tabuleiro[MAX][MAX], int ativacao[MAX][MAX], int nlin, int ncol, int instante, int *novosativados);

void copie_matriz(int origem[MAX][MAX], int destino[MAX][MAX], int nlin, int ncol);

/*funcoes desenvolvidas*/

/*aqui comeca o programa*/

int main(){
    int tabuleiro[MAX][MAX];/*declaracao do tabuleiro_def ep*/
    return 0;
}