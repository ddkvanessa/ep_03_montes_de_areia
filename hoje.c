#include<stdio.h>
int main(){
    int nlin, ncol, nc, nl, tabuleiro[nl][nc];
    scanf("%d", &nlin);
    scanf("%d", &ncol);
    for(nlin=0; nlin<nl; nlin++)
        for(ncol=0; nlin<nc; ncol++)
            printf("%d", tabuleiro[nl][nc]);
    return 0;
}