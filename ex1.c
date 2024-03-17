#include <stdio.h>
#include <string.h>

void Selecao(int lista[], int n){

    int i, aux, minIdx;

    for(i = 0; i < n - 1; i++){
        minIdx = i;
        for(int j = i+1; j < n; j++){
            printf("C %d %d\n", minIdx, j);
            if(lista[j] < lista[minIdx]){
                minIdx = j;
            }
        }
        if (minIdx != i){
            printf("T %d %d\n", i, minIdx);
            aux = lista[i];
            lista[i] = lista[minIdx];
            lista[minIdx] = aux;
}}}

void Bolha(int lista[], int n){

    int i, pass, aux, swapped;

    for(pass = n-1; pass >= 1; pass = swapped){
        swapped = -1;
        for(i = 0; i < pass; i++){
            printf("C %d %d\n", i, i+1);
            if(lista[i] > lista[i+1]){
                printf("T %d %d\n", i, i+1);
                swapped = i;
                aux = lista[i];
                lista[i] = lista[i+1];
                lista[i+1] = aux;
}}}}

int main(){
    char escolha[10];
    int n, i;
    
    scanf("%s", escolha);
    scanf("%d", &n);

    int listaOriginal[n];

    for (i = 0; i < n; i++) 
    scanf("%d", &listaOriginal[i]);

    if (strcmp(escolha, "selecao") == 0) {
        Selecao(listaOriginal, n);
    } else if (strcmp(escolha, "bolha") == 0) {
        Bolha(listaOriginal, n);
    }

    for (i = 0; i<n; i++) 
    printf("%d ", listaOriginal[i]);

    return 0;
}
