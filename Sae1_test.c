#include"Sae1.h"


void testRecherche(void){
    int tab[20]={3,7,10,29,33},taille=5,val=8,trouve,indice;
    indice=recherche(tab,taille,val,&trouve);
    printf("résultat attendu : 2 et 0, résultat : %d %d\n",indice,trouve);
    val=1;
    indice=recherche(tab,taille,val,&trouve);
    printf("résultat attendu : 0 et 0, résultat : %d %d\n",indice,trouve);
    val=90;
    indice=recherche(tab,taille,val,&trouve);
    printf("résultat attendu : 5 et 0, résultat : %d %d\n",indice,trouve);
    val=10;
    indice=recherche(tab,taille,val,&trouve);
    printf("résultat attendu : 2 et 1, résultat : %d %d\n",indice,trouve);
    val=33;
    indice=recherche(tab,taille,val,&trouve);
    printf("résultat attendu : 4 et 1, résultat : %d %d\n",indice,trouve);
}

int main(void){
    testRecherche();
    return 0;
}