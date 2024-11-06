#include"Sae1.h"

void testChargementEtu(void) {
    int Tab_Etu={101,124,236,520};
    int Tab_RSta={-1,2001,-1,5623};
    float Tab_Note={-1.0,-1.0,-1.0,-1.0};
    int Tmax=20;
    chargementEtu(Tab_Etu, Tab_RSta, Tab_Note, Tmax);
}


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