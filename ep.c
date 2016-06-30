/*meuep < minhaentrada.txt > minhasaida.txt*/

/*clear && gcc -Wall -ansi -O2 -pedantic ep.c -o ep && ./ep*/

/*git add . && git commit -am "comentario da etapa" && git push*/

#include <stdio.h>
/* dimensao maxima da matriz*/
#define MAX  128

/*declaracao das variaveis*/

/*aqui comeca as funcoes do programa*/

/*funcoes definidas no enunciado do ep*/

/*esta função coloca zero em todas as posicoes da matriz tab de tamanho nlin x ncol*/
void zere_tabuleiro(int tabuleiro[MAX][MAX], int nlin, int ncol){
    int nl, nc;
    for(nl=0; nl < nlin; nl++)
        for(nc=0; nc < ncol; nc++)
            tabuleiro[nl][nc] =0;
}

/*esta função deve ler os valores da entrada (como descrito na especificação da entrada) e inicializar
o tabuleiro e as variáveis (externas) nlin e ncol com os valores correspondentes.*/
void leia_configuracao_inicial(int tabuleiro[MAX][MAX], int *nlin, int *ncol){
  int nc, nl, ne, contador;
  int cont = 0;

  scanf("%d", nlin); /*pego primeiro elemento do txt e chamo de numero de linhas*/
  scanf("%d", ncol); /*pego o primeiro elemento do txt e chamo de numero de colunas*/

  while(cont>=0){
    scanf("%d", &nl);/*pega elemento do txt e da coordenada da linha*/
    scanf("%d", &nc);/*pega elemento do txt e da coordenada da coluna */
    scanf("%d", &ne);/*pega elemento do txt e chama de preenchimento da linhaxcoluna*/

    cont = cont + 1;/*contador faz o laço existir para quantos elementos tiveram no txt*/
    if(nl<0 || nc<0 || ne<0)/*quebra meu laço quando aparece -1, mesmo se a condicao ainda for verdadeira*/
      break;

    tabuleiro[nl][nc]=ne;/*faço minha matriz*/
  }

}

/*essa função imprime o tabuleiro no formato utilizado nos exemplos acima*/
void imprima_tabuleiro(int tabuleiro[MAX][MAX], int nlin, int ncol){
    int nl, nc;
    nl = nlin;
    nc = ncol;
    /*alinhamento dos elementos da matriz(para elementos com ate 2 digitos)*/
    for(nlin=0; nlin<nl; nlin++)
        for(ncol=0; ncol<nc; ncol++){
            if(ncol == 0 && tabuleiro[nlin][ncol]/10 == 0)/*elementos da ponta esquerda e menores que dez*/
                printf("--%d--+", tabuleiro[nlin][ncol]);
            if(ncol == 0 && tabuleiro[nlin][ncol]/10 != 0)/*elementos da ponta esquerda e maiores que dez*/
                printf("-%d--+", tabuleiro[nlin][ncol]);
            if(ncol > 0 && ncol < nc-1 && tabuleiro[nlin][ncol]/10 == 0)/*elementos do meio e menores que dez*/
                printf("--%d--+", tabuleiro[nlin][ncol]);
            if(ncol > 0 && ncol < nc-1 && tabuleiro[nlin][ncol]/10 != 0)/*elementos do meio e maiores que dez*/
                printf("-%d--+", tabuleiro[nlin][ncol]);
            if(ncol == nc-1 && tabuleiro[nlin][ncol]/10 == 0)/*elementos da ponta direita menores que dez*/
                printf("--%d--\n", tabuleiro[nlin][ncol]);
            if(ncol == nc-1 && tabuleiro[nlin][ncol]/10 != 0)/*elementos da ponto direita e maiores que dez*/
                printf("-%d--\n", tabuleiro[nlin][ncol]);
        }
        printf("\n\n");
}

void copie_matriz(int origem[MAX][MAX], int destino[MAX][MAX], int nlin, int ncol){
  int nl, nc;
  for(nl = 0; nl < nlin; nl++)
    for(nc = 0; nc < ncol; nc++)
      destino[nl][nc]=origem[nl][nc];
      printf("\n\n");
}

// Essa função corresponde ao mecanismo central do EP, e será a responsável pela
// realização dos espalhamentos em cada instante. A matriz ativação (declarada na
// função main e inicializada com -1's) deve registrar o instante em que cada
// casa é ativada (fica instável) pela primeira vez. O parâmetro de saída novos
// ativados deve indicar quantas casas ficaram instáveis pela primeira vez nesse
// instante, e o valor de retorno da função é a quantidade total de casas
// instáveis nesse instante.

int espalhe(int tabuleiro[MAX][MAX], int ativacao[MAX][MAX], int nlin, int ncol, int instante, int *novosativados){

}

/*funcoes desenvolvidas*/
/*aqui comeca o programa*/

int main(){
    int ncol, nlin, ne, instante;
    int *novosativados;
    int tabuleiro[MAX][MAX], ativacao[MAX][MAX];/*declaracao do tabuleiro_def ep*/
    leia_configuracao_inicial(tabuleiro, &nlin, &ncol);
    // ----------------------------------------------------------------------
    espalhe(tabuleiro, ativacao, nlin, ncol, instante, novosativados);



    return 0;
}
