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
                  printf("  %d  +", tabuleiro[nlin][ncol]);
              if(ncol == 0 && tabuleiro[nlin][ncol]/10 != 0)/*elementos da ponta esquerda e maiores que dez*/
                  printf(" %d  +", tabuleiro[nlin][ncol]);
              if(ncol > 0 && ncol < nc-1 && tabuleiro[nlin][ncol]/10 == 0)/*elementos do meio e menores que dez*/
                  printf("  %d  +", tabuleiro[nlin][ncol]);
              if(ncol > 0 && ncol < nc-1 && tabuleiro[nlin][ncol]/10 != 0)/*elementos do meio e maiores que dez*/
                  printf("-%d  +", tabuleiro[nlin][ncol]);
              if(ncol == nc-1 && tabuleiro[nlin][ncol]/10 == 0)/*elementos da ponta direita menores que dez*/
                  printf("  %d  \n", tabuleiro[nlin][ncol]);
              if(ncol == nc-1 && tabuleiro[nlin][ncol]/10 != 0)/*elementos da ponto direita e maiores que dez*/
                  printf(" %d  \n", tabuleiro[nlin][ncol]);
          }
          printf("\n\n");
  }

  void copie_matriz(int origem[MAX][MAX], int destino[MAX][MAX], int nlin, int ncol){
    int nl, nc;
    for(nl = 0; nl < nlin; nl++)
      for(nc = 0; nc < ncol; nc++)
        destino[nl][nc] = origem[nl][nc];
  }

  // Essa função corresponde ao mecanismo central do EP, e será a responsável pela
  // realização dos espalhamentos em cada instante. A matriz ativação (declarada na
  // função main e inicializada com -1's) deve registrar o instante em que cada
  // casa é ativada (fica instável) pela primeira vez. O parâmetro de saída novos
  // ativados deve indicar quantas casas ficaram instáveis pela primeira vez nesse
  // instante, e o valor de retorno da função é a quantidade total de casas
  // instáveis nesse instante.

  void soma_matriz(int a[MAX][MAX], int b[MAX][MAX], int nlin, int ncol){
    int nl, nc;
    for(nl = 0; nl < nlin; nl++)
      for(nc = 0; nc < ncol; nc++)
        a[nl][nc] += b[nl][nc];
  }


int espalhe(int tabuleiro[MAX][MAX], int ativacao[MAX][MAX], int nlin, int ncol, int instante, int *novosativados){
    int nl, nc, alterados_instante;
    int pontos[MAX][MAX];
    zere_tabuleiro(pontos,nlin,ncol);
    int numero_vizinho = 0;
    *novosativados = 0;

    for(nl = 0; nl < nlin; nl++){
        for(nc = 0; nc < ncol; nc++){
            /*conatndo o numero de vizinhos da tabuleiro*/
            numero_vizinho = 0;

            if(nl-1 >= 0){
              numero_vizinho = numero_vizinho + 1;
            }
            if(nl+1 < nlin){
              numero_vizinho = numero_vizinho + 1;
            }
            if(nc-1 >= 0){
              numero_vizinho = numero_vizinho + 1;
            }
            if(nc+1 < ncol){
              numero_vizinho = numero_vizinho + 1;
            }

            if(tabuleiro[nl][nc] >= numero_vizinho){

                if(nl-1 >= 0){
                  pontos[nl][nc]--;
                  pontos[nl-1][nc]++;
                }
                if(nl+1 < nlin){
                  pontos[nl][nc]--;
                  pontos[nl+1][nc]++;
                }
                if(nc-1 >= 0){
                  pontos[nl][nc]--;
                  pontos[nl][nc-1]++;
                }
                if(nc+1 < ncol){
                  pontos[nl][nc]--;
                  pontos[nl][nc+1]++;
                }


                if(ativacao[nl][nc] == -1){
                    novosativados = novosativados + 1;
                    ativacao[nl][nc] = instante;
                }

                alterados_instante = alterados_instante + 1;
            }
        }
    }

    soma_matriz(tabuleiro,pontos,nl,nc);
    return alterados_instante;
}
  /*funcoes desenvolvidas*/
  void preenchido_menos_um(int menos_um[MAX][MAX], int nlin, int ncol){
    int nl, nc;
    for(nl = 0; nl < nlin; nl++)
      for(nc = 0; nc < ncol; nc++)
        menos_um[nl][nc]= -1;
  }

  int nao_infinito(int ativacao[MAX][MAX], int nlin, int ncol){
    int nl, nc;
    for(nl=0; nl<nlin; nl++)
      for(nc=0; nc<ncol; nc++)
        if(ativacao[nl][nc] == -1)
          return 0;
        return 1;
  }
  /*aqui comeca o programa*/

  int main(){
      int ncol, nlin, ne, instante;
      int *novosativados;
      int tabuleiro[MAX][MAX], ativacao[MAX][MAX];/*declaracao do tabuleiro_def ep*/
      zere_tabuleiro(tabuleiro, nlin, ncol);
      leia_configuracao_inicial(tabuleiro, &nlin, &ncol);
      preenchido_menos_um(ativacao, nlin, ncol);
      // ----------------------------------------------------------------------

      for(instante = 0; instante>=0; instante++){
        if(nao_infinito(ativacao, nlin, ncol) == 1)
          break;
        espalhe(tabuleiro, ativacao, nlin, ncol, instante, novosativados);
      }


      return 0;
  }
