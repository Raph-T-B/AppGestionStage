#include"Sae1.h"

//VERIFIED !!// 
void test_decalageD_Float(void){
    printf("--Test affichage decalage tableau float\n");
    float tab[6]={12.5,18,9.5};
    int taille=3,i=0,tmax=6,pb;
    printf("affichage tableau de taille max 6\n");
    afficheTabFlo(tab,taille);
    printf("décalage élément indice 0 + association du nombre 1.00\n");
    pb=decalerADroiteF(tab,tmax,0,&taille);
    tab[0]=1;
    taille=taille+1;
    printf("affichage tableau\n");
    afficheTabFlo(tab,taille);
    printf("décalage élément indice 2 + association du nombre 2.00\n");
    pb=decalerADroiteF(tab,tmax,2,&taille);
    tab[2]=2;
    taille=taille+1;
    printf("affichage tableau\n");
    afficheTabFlo(tab,taille);
    printf("décalage élément indice 5 + association du nombre 3.00\n");
    pb=decalerADroiteF(tab,tmax,5,&taille);
    tab[5]=3;
    taille=taille+1;
    printf("affichage tableau\n");
    afficheTabFlo(tab,taille);
    printf("décalage élément indice 2 + pas d'association car pb de taille normalement\n");
    pb=decalerADroiteF(tab,tmax,2,&taille);
    printf("\n");
}

//VERIFIED !!// 
void test_decalageD_Int(void){
    printf("\n\n");
    printf("--Test affichage decalage tableau entier\n");
    int tab[6]={12,18,9};
    int taille=3,i=0,tmax=6,pb;
    printf("affichage tableau de taille max 6\n");
    afficheTabEnt(tab,taille);
    printf("décalage élément indice 0 + association du nombre 1\n");
    pb=decalerADroiteI(tab,tmax,0,&taille);
    tab[0]=1;
    taille=taille+1;
    printf("affichage tableau\n");
    afficheTabEnt(tab,taille);
    printf("décalage élément indice 2 + association du nombre 2\n");
    pb=decalerADroiteI(tab,tmax,2,&taille);
    tab[2]=2;
    taille=taille+1;
    printf("affichage tableau\n");
    afficheTabEnt(tab,taille);
    printf("décalage élément indice 5 + association du nombre 3\n");
    pb=decalerADroiteI(tab,tmax,5,&taille);
    tab[5]=3;
    taille=taille+1;
    printf("affichage tableau\n");
    afficheTabEnt(tab,taille);
    printf("décalage élément indice 2 + pas d'association car pb de taille normalement\n");
    pb=decalerADroiteI(tab,tmax,2,&taille);
    printf("\n");
}

//VERIFIED !!// 
void testRecherche(void){
    int tab[20]={3,7,10,29,33},taille=5,val=8,trouve,indice,Tlog=5;
    printf("tableau donné :\n");
    afficheTabEnt(tab,Tlog);
    indice=recherche(tab,taille,val,&trouve);
    printf("recherche : 8 résultat attendu : 2 et 0, résultat : %d %d\n",indice,trouve);
    val=1;
    indice=recherche(tab,taille,val,&trouve);
    printf("recherche : 1 résultat attendu : 0 et 0, résultat : %d %d\n",indice,trouve);
    val=90;
    indice=recherche(tab,taille,val,&trouve);
    printf("recherche : 90 résultat attendu : 5 et 0, résultat : %d %d\n",indice,trouve);
    val=10;
    indice=recherche(tab,taille,val,&trouve);
    printf("recherche : 10 résultat attendu : 2 et 1, résultat : %d %d\n",indice,trouve);
    val=33;
    indice=recherche(tab,taille,val,&trouve);
    printf("recherche : 33 résultat attendu : 4 et 1, résultat : %d %d\n",indice,trouve);
}

//VERIFIED !!// 
void testAfficherStagesPourvus(void)
{
    int Tab_Ref[]= {5008,2001,8000,5623};
    int Tab_Dep[]= {26,56,80,63};
    int Tab_EtuAcc[]= {0,1,0,1};
    int Tab_Etu[]={101,124,236,520};
    int Tab_RSta[]={2001,-1,5623,-1};
    int Tlog=4;
    printf("--Test Afficher Stages Pourvus\n");
    printf("--Doit renvoyer : 2001 pour l'étudiant 101, 5623 pour l'étudiant 236  \n");
    afficherStagesPourvus(Tab_Ref,Tab_Dep,Tab_EtuAcc, Tab_Etu, Tab_RSta,Tlog);
}

//VERIFIED !!//  
void testAfficherStagesNonPourvus(void)
{
    int Tab_Ref[]={5008,2001,8000,5623};
    int Tab_Dep[]={26,56,80,63};
    int Tab_EtuAcc[]={0,1,0,1};
    int Tlog=4;
    printf("--Test Afficher Stages Pourvus \n");
    printf("--Doit renvoyer : 5008 et 8000 \n");
    afficherStagesNonPourvus(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tlog);
}

//VERIFIED !!// 
void testAfficherEtudiantsSansStage(void)
{
    int Tab_Etu[]={101,124,236,520};
    int Tab_RSta[]={-1,2001,-1,5623};
    int Tlog=4;
    printf("--Test Afficher Etudiants sans stage \n");
    printf("--Doit renvoyer : 101 et 236 \n");
    afficherEtudiantsSansStage(Tab_Etu,Tab_RSta, Tlog);
}

//VERIFIED !!// 
void testAfficherInfoStage(void){
    int Tab_Ref[]={5008,2001,8000,5623};
    int Tab_Dep[]={26,56,80,63};
    int Tab_EtuAcc[]={0,1,0,1};
    int Tab_NCand[]={2,0,3,0};
    int Tab_Cand1[]={101,-1,23,-1};
    int Tab_Cand2[]={30,-1,210,-1};
    int Tab_Cand3[]={-1,-1,39,-1};
    int Tlog=4;
    int ref=8000;
    printf("--Test Afficher info stage \n");
    printf("--Doit renvoyer : ref : 8000, dep : 80, pas pourvu, 3 candidats,le 23,210,39 \n");
    afficherInfoStage(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,Tlog,ref);
}

//VERIFIED !!// 
void testajout(void){
    int Tab_Etu[]={2834,4933,4384,2368,1839};
    float Tab_Note[]={-1,-1,-1,-1,-1};
    int cont=0,sort=0,i=0;
    for(i=0;i<5;i++)
        printf("etu : %d note : %.2f\n",Tab_Etu[i],Tab_Note[i]);
    printf("\n");
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

//VERIFIED !!// 
void testSauvegarderEtu(void){
    int Tab_Etu[]={101,124,236,520};
    float Tab_Note[]={-1,13.5,19.5,10};
    int Tab_RSta[]={-1,2001,-1,5623};
    int Tlog=4;
    printf("--Test Sauvegarder Etudiant \n");
    sauvegardeEtu(Tab_Etu,Tab_RSta,Tab_Note,Tlog,stdout);
}

//VERIFIED !!// 
void testSauvegarderOffre(void){
    int Tab_Ref[]= {5008,2001,8000,5623,2388};
    int Tab_Dep[]= {26,56,80,63,95};
    int Tab_EtuAcc[]= {0,1,0,0,0};
    int Tab_Ncand[]={0,0,1,2,3};
    int Tab_Cand1[]={0,0,138,138,870};
    int Tab_Cand2[]={0,0,0,637,94};
    int Tab_Cand3[]={0,0,0,0,458};
    int Tlog=5;
    printf("--Test Sauvegarder Stage \n");
    sauvegardeOffre(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tab_Ncand,Tlog,Tab_Cand1,Tab_Cand2,Tab_Cand3,stdout);
}


/*
void test_afficherStagesParCritere(void) {
    int Tab_Ref[] = {101, 102, 103};
    int Tab_Dep[] = {10, 20, 10};
    int Tlog = 3;

    printf("\nTest de afficherStagesParCritere (par numéro):\n");
    afficherStagesParCritere(Tab_Ref, Tab_Dep, Tlog, 'n', 101);

    printf("\nTest de afficherStagesParCritere (par département):\n");
    afficherStagesParCritere(Tab_Ref, Tab_Dep, Tlog, 'd', 10);
}

void test_afficherCandidaturesEtudiant() {
    int Tab_Etu[] = {101, 102, 103};
    int Tab_RSta[] = {-1, 5008, 1061};
    int Tlog = 3;
    int etu_num = 102;

    printf("Test 1 : Étudiant avec stage affecté\n");
    afficherCandidaturesEtudiant(Tab_Etu, Tab_RSta, Tlog, etu_num);

    etu_num = 101;
    printf("\nTest 2 : Étudiant sans stage\n");
    afficherCandidaturesEtudiant(Tab_Etu, Tab_RSta, Tlog, etu_num);

    etu_num = 104;
    printf("\nTest 3 : Étudiant non existant\n");
    afficherCandidaturesEtudiant(Tab_Etu, Tab_RSta, Tlog, etu_num);
}
*/
void testSupprimeCandidature(void){
    int Tab_Ref[]= {5008,2001,8000,5623,2388};
    int Tab_Dep[]= {26,56,80,63,95};
    int Tab_EtuAcc[]= {0,1,0,0,0};
    int Tab_NCand[]={0,0,1,2,3};
    int Tab_Cand1[]={0,0,138,138,870};
    int Tab_Cand2[]={0,0,0,637,94};
    int Tab_Cand3[]={0,0,0,0,458};
    int Tlog=5,ref=5623;
    printf("--Test Sauvegarder Etudiant \n");
    afficherInfoStage(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,Tlog,ref);
    printf("Supression de l'étudiant 138 dans ce stage\n");
    SupprimeCandidature(Tab_Ref,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,Tlog,138,5623);
    afficherInfoStage(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,Tlog,ref);
}

int main(void){
    /*
    testRecherche();
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
    test_decalageD_Float();
    printf("\n\n");
    test_decalageD_Int();
    printf("\n\n");
    testajout();
    printf("\n\n");
    */
    testSupprimeCandidature();
    return 0;
}