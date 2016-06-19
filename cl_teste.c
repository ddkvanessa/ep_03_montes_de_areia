// gcc cl_teste.c -o cl && ./cl < teste.txt
#include <stdio.h> 
#include <stdlib.h>
#define MAX  128

int main(int argc, char *argv[]) {
int ncol, nlin, nc, nl, ne, contador;
int cont = 0;
int tabuleiro[MAX][MAX];

scanf("%d", &nlin);/*pego primeiro elemento do txt e chamo de numero de linhas*/
scanf("%d", &ncol);/*pego o primeiro elemento do txt e chamo de numero de colunas*/
printf("%d nlin, %d ncol\n", nlin, ncol);/*imprime linha e coluna para eu saber se esta certo*/

while(cont>=0){
scanf("%d", &nl);/*pega elemento do txt e da coordenada da linha*/
scanf("%d", &nc);/*pega elemento do txt e da coordenada da coluna */
scanf("%d", &ne);/*pega elmento do txt e chama de preenchimento da linhaxcoluna*/

cont = cont + 1;/*contador que faz o laço existir para quantos elemntos tiveram no txt*/
if(nl<0 || nc<0 || ne<0)/*quebra meu laço quando aparece -1, mesmo se a condicao ainda for verdadeira*/
break;
printf("%d nl, %d nc, %d ne\n", nl, nc, ne);/*imprime linha coluna e preenchimento para eu saber se esta certo*/

tabuleiro[nl][nc]=ne;/*faço minha matriz*/
}

return 0;
}