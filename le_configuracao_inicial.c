/*clear && gcc le_configuracao_inicial.c -o ep3 && ./ep3 < teste.txt*/
#include<stdio.h>
int main(){
int ncol = 3;/*teste, depois eu pego da funcao leia configuração inicial*/
int p_coluna = 0;/*para contador(só ta usando no print)*/
printf("---------%d-+", p_coluna);/*espeço que tem na frente do primeiro simbolo*/
int count_nc;
int count_pc;

scanf("%d", &ncol);/*pega elemento do txt e da coordenada da linha*/

count_nc = ncol;
count_pc = p_coluna;


while(ncol>1){
    
    p_coluna = p_coluna + 1;/*0+1=1 (acho que não precisa definir na declaração de variavel)*/
    
    if(p_coluna  <= 9)
        printf("-%d-+", p_coluna);
    if(p_coluna >= 10 && p_coluna <= 99)
        printf("-%d-+", p_coluna);
    if(p_coluna >= 100 && p_coluna <= 999)
        printf("-%d-", p_coluna);
    
    ncol = ncol - 1;
    
    }
    
    printf("\n--------");
    
    while(count_nc > 0){
    
    count_pc = count_pc +1;
    
    if(count_pc <=10)
        printf("---+");
    if(count_pc >= 11 && count_pc <= 100)
        printf("----+");
    if(count_pc >= 101 && count_nc <= 1001)
        printf("-----+");
    
    count_nc = count_nc - 1;
    // printf("%d\n", count_pc);
    
    }

    return 0;
}