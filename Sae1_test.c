#include"Sae1.h"

void test_decalageD_Float(void){
    printf("test affichage decalage tableau float\n");
    float tab[6]={12.5,18,9.5};
    int taille=3,i=0,tmax=6,pb;
    printf("affichage tableau de taille max 6\n");
    for(i=0;i<taille;i++)
        printf("%.2f    ",tab[i]);
    printf("\n\n");
    printf("décalage élément indice 0\n");
    pb=decalerADroiteF(tab,tmax,0,&taille);
    tab[0]=1;
    taille=taille+1;
    printf("affichage tableau\n");
    for(i=0;i<taille;i++)
        printf("%.2f    ",tab[i]);
    printf("\n\n");
    printf("décalage élément indice 2\n");
    pb=decalerADroiteF(tab,tmax,2,&taille);
    tab[2]=2;
    taille=taille+1;
    printf("affichage tableau\n");
    for(i=0;i<taille;i++)
        printf("%.2f    ",tab[i]);
    printf("\n\n");
    printf("décalage élément indice 5\n");
    pb=decalerADroiteF(tab,tmax,5,&taille);
    tab[5]=3;
    taille=taille+1;
    printf("affichage tableau\n");
    for(i=0;i<taille;i++)
        printf("%.2f    ",tab[i]);
    printf("\n\n");
    printf("décalage élément indice 2\n");
    pb=decalerADroiteF(tab,tmax,2,&taille);
    printf("\n");
}

void test_decalageD_Int(void){
    printf("\n\n");
    printf("test affichage decalage tableau entier\n");
    int tab[6]={12,18,9};
    int taille=3,i=0,tmax=6,pb;
    printf("affichage tableau de taille max 6\n");
    for(i=0;i<taille;i++)
        printf("%d    ",tab[i]);
    printf("\n\n");
    printf("décalage élément indice 0\n");
    pb=decalerADroiteI(tab,tmax,0,&taille);
    tab[0]=1;
    taille=taille+1;
    printf("affichage tableau\n");
    for(i=0;i<taille;i++)
        printf("%d    ",tab[i]);
    printf("\n\n");
    printf("décalage élément indice 2\n");
    pb=decalerADroiteI(tab,tmax,2,&taille);
    tab[2]=2;
    taille=taille+1;
    printf("affichage tableau\n");
    for(i=0;i<taille;i++)
        printf("%d    ",tab[i]);
    printf("\n\n");
    printf("décalage élément indice 5\n");
    pb=decalerADroiteI(tab,tmax,5,&taille);
    tab[5]=3;
    taille=taille+1;
    printf("affichage tableau\n");
    for(i=0;i<taille;i++)
        printf("%d    ",tab[i]);
    printf("\n\n");
    printf("décalage élément indice 2\n");
    pb=decalerADroiteI(tab,tmax,2,&taille);
    printf("\n");
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

void testAfficherStagesPourvus(void)
{
    int Tab_Ref[]= {5008,2001,8000,5623};
    int Tab_Dep[]= {26,56,80,63};
    int Tab_EtuAcc[]= {0,1,0,1};
    int Tab_Etu[]={101,124,236,520};
    int Tab_RSta[]={2001,-1,5623,-1};
    int Tlog=4;
    printf("test Afficher Stages Pourvus\n");
    printf("doit renvoyer : 2001 pour l'étudiant 101, 5623 pour l'étudiant 236  \n");
    afficherStagesPourvus(Tab_Ref,Tab_Dep,Tab_EtuAcc, Tab_Etu, Tab_RSta,Tlog);
}

void testAfficherStagesNonPourvus(void)
{
    int Tab_Ref[]={5008,2001,8000,5623};
    int Tab_Dep[]={26,56,80,63};
    int Tab_EtuAcc[]={0,1,0,1};
    int Tlog=4;
    printf("test Afficher Stages Pourvus \n");
    printf("doit renvoyer : 5008 et 8000 \n");
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

void testajout(void){
    int Tab_Etu[]={2834,4933,4384,2368,1839};
    float Tab_Note[]={-1,-1,-1,-1,-1};
    int cont=0,sort=0,i=0;
    for(i=0;i<5;i++)
        printf("etu : %d note : %.2f\n",Tab_Etu[i],Tab_Note[i]);
    printf("############### Possibilité d'exécuter une batterire de test ###############\n");
    printf("\n");
    while(cont!=-1){
        sort=ajoutNote(Tab_Etu,Tab_Note,5);
        if (sort==-1)
            printf("Vous êtes bien sortis de la fonction\n");
        if (sort==0)
            printf("La fonction a bien fonctionné ! Affichage du nouveau tableau : \n");
        printf("\n");
        for(i=0;i<5;i++)
            printf("etu : %d note : %.2f\n",Tab_Etu[i],Tab_Note[i]);
        printf("\n");
        printf("Voulez vous continuer à tester ? : (-1 pour non 0 pour oui) : ");
        scanf("%d",&cont);
    }
    printf("\n");
    printf("Fin test ajout\n");
}

void testSauvegarderEtu(void){
    int Tab_Etu[]={101,124,236,520};
    float Tab_Note[]={-1,13.5,19.5,10};
    int Tab_RSta[]={-1,2001,-1,5623};
    int Tlog=4;
    sauvegardeEtu(Tab_Etu,Tab_RSta,Tab_Note,Tlog);
}

void testSauvegarderOffre(void){
    int Tab_Ref[]= {5008,2001,8000,5623,2388};
    int Tab_Dep[]= {26,56,80,63,95};
    int Tab_EtuAcc[]= {0,1,0,0,0};
    int Tab_Ncand[]={0,0,1,2,3};
    int Tab_Cand1[]={0,0,138,138,870};
    int Tab_Cand2[]={0,0,0,637,94};
    int Tab_Cand3[]={0,0,0,0,458};
    int Tlog=5;
    sauvegardeOffre(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tab_Ncand,Tlog,Tab_Cand1,Tab_Cand2,Tab_Cand3);
}



int main(void){
    /*testRecherche();
    */
    printf("\n\n");
    testAfficherStagesPourvus();
    printf("\n\n");
    testAfficherStagesNonPourvus();
    printf("\n\n");
    testAfficherEtudiantsSansStage();
    printf("\n\n");
    testAfficherInfoStage();
    printf("\n\n");
    testSauvegarderEtu();
    printf("\n\n");
    testSauvegarderOffre();
    printf("\n\n");
    testajout();
    printf("\n\n");
    test_decalageD_Float();
    printf("\n\n");
    test_decalageD_Int();
    printf("\n\n");
    return 0;
}