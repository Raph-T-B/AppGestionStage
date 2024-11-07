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

void testAfficherStagesPourvus(void)
{
    int Tab_Ref[]= {5008,2001,8000,5623};
    int Tab_Dep[]= {26,56,80,63};
    int Tab_EtuAcc[]= {0,1,0,-1};
    int Tab_Etu[]={101,124,236,520};
    int Tlog=4;
    afficherStagesPourvus(Tab_Ref,Tab_Dep,Tab_EtuAcc, Tab_Etu, Tlog);
}



void testAfficherStagesNonPourvus(void)
{
    int Tab_Ref[]={5008,2001,8000,5623};
    int Tab_Dep[]={26,56,80,63};
    int Tab_EtuAcc[]={0,1,-1,1};
    int Tlog=4;
    afficherStagesNonPourvus(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tlog);
}

void testAfficherEtudiantsSansStage(void)
{
    int Tab_Etu[]={101,124,236,520};
    int Tab_RSta[]={-1,2001,-1,5623};
    int Tlog=4;
    afficherEtudiantsSansStage(Tab_Etu,Tab_RSta, Tlog);
}


void testAfficherInfoStage(void)
{
    int Tab_Ref[]={5008,2001,8000,5623};
    int Tab_Dep[]={26,56,80,63};
    int Tab_EtuAcc[]={0,1,0,1};
    int Tab_NCand[]={2,0,3,0};
    int Tlog=4;
    int ref=8000;
    afficherInfoStage(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tab_NCand,Tlog,ref);
}

int main(void){
    testRecherche();
    testAfficherStagesPourvus();
    testAfficherStagesNonPourvus();
    testAfficherEtudiantsSansStage();
    testAfficherInfoStage();
    return 0;
}