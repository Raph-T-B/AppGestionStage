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
    printf("--Test de recherche dans un tableau ordonné\n");
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
void testRechercheStag(void){
    int tab[20]={3,7,10,29,33},taille=5,val=8,indice,Tlog=5;
    printf("--Test de recherche dans un tableau quelconque\n");
    printf("tableau donné :\n");
    afficheTabEnt(tab,Tlog);
    indice=rechercheStag(tab,taille,val);
    printf("recherche : 8 résultat attendu :-1 , résultat : %d\n",indice);
    val=1;
    indice=rechercheStag(tab,taille,val);
    printf("recherche : 1 résultat attendu : -1 , résultat : %d\n",indice);
    val=90;
    indice=rechercheStag(tab,taille,val);
    printf("recherche : 90 résultat attendu : -1 , résultat : %d\n",indice);
    val=10;
    indice=rechercheStag(tab,taille,val);
    printf("recherche : 10 résultat attendu : 2, résultat : %d\n",indice);
    val=33;
    indice=rechercheStag(tab,taille,val);
    printf("recherche : 33 résultat attendu : 4, résultat : %d\n",indice);
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
void testajoutNote(void){
    int Tab_Etu[]={2834,4933,4384,2368,1839};
    float Tab_Note[]={-1,-1,-1,-1,-1};
    int cont=0,sort=0,i=0;
    for(i=0;i<5;i++)
        printf("etu : %d note : %.2f\n",Tab_Etu[i],Tab_Note[i]);
    printf("\n");
    printf("--Test Ajout Note \n");
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
void testajoutOffre(void){
    int Tab_Ref[30]={5008,2001,8000,5623};
    int Tab_Dep[30]={26,56,80,63};
    int Tab_EtuAcc[30]={0,1,0,1};
    int Tab_NCand[30]={2,0,3,0};
    int Tlog=5,Tmax=30,i,sort,cont=1;
    printf("\n");
    printf("--Test Ajout stage \n");
    printf("\n");
    afficheTabEnt(Tab_Ref,Tlog);
    afficheTabEnt(Tab_Dep,Tlog);
    afficheTabEnt(Tab_EtuAcc,Tlog);
    afficheTabEnt(Tab_NCand,Tlog);
    printf("\n");
    printf("############### Possibilité d'exécuter une batterire de test ###############\n");
    printf("\n");
    while(cont!=-1){
        sort=ajoutOffre(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tab_NCand,&Tlog,Tmax);
        if (sort==-1)
            printf("Vous êtes bien sortis de la fonction\n");
        if (sort==0)
            printf("La fonction a bien fonctionné ! Affichage du nouveau tableau : \n");
        printf("\n");
        afficheTabEnt(Tab_Ref,Tlog);
        afficheTabEnt(Tab_Dep,Tlog);
        afficheTabEnt(Tab_EtuAcc,Tlog);
        afficheTabEnt(Tab_NCand,Tlog);
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


//VERIFIED !!//
void test_afficherStagesParCritere(void) {
    int Tab_Ref[]= {5008,2001,8000,5623,2388};
    int Tab_Dep[]= {26,56,80,78,26};
    int Tlog = 5;

    printf("--Test de afficherStagesParCritere (par numéro):\n");
    afficherStagesParCritere(Tab_Ref, Tab_Dep, Tlog, 'n', 5623);

    printf("--Test de afficherStagesParCritere (par département):\n");
    afficherStagesParCritere(Tab_Ref, Tab_Dep, Tlog, 'd', 26);
}

//VERIFIED !!// 
void test_afficherCandidaturesEtudiant() {
    int Tab_Ref[]= {5008,2001,8000,5623,2388};
    int Tab_NCand[]={0,0,1,2,3};
    int Tab_Cand1[]={104,0,138,101,870};
    int Tab_Cand2[]={0,104,0,637,101};
    int Tab_Cand3[]={0,0,0,0,90};
    int TlogCand = 5;
    int etu_num = 102;
    printf("Test 1 : Étudiant avec stage affecté\n");
    afficherCandidaturesEtudiant(Tab_Ref,TlogCand,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,etu_num);
    etu_num = 101;
    printf("\nTest 2 : Étudiant sans stage\n");
    afficherCandidaturesEtudiant(Tab_Ref,TlogCand,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,etu_num);
    etu_num = 104;
    printf("\nTest 3 : Étudiant non existant\n");
    afficherCandidaturesEtudiant(Tab_Ref,TlogCand,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,etu_num);
}

//VERIFIED !!// 
void testSupprimeCandidature(void){
    int Tab_Ref[]= {5008,2001,8000,5623,2388};
    int Tab_Dep[]= {26,56,80,63,95};
    int Tab_EtuAcc[]= {0,1,0,0,0};
    int Tab_NCand[]={0,0,1,2,3};
    int Tab_Cand1[]={0,0,138,138,870};
    int Tab_Cand2[]={0,0,0,637,94};
    int Tab_Cand3[]={0,0,0,0,458};
    int Tlog=5,ref=5623,ind;
    printf("--Test Supprimer Etudiant \n");
    afficherInfoStage(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,Tlog,ref);
    printf("Supression de l'étudiant 138 dans ce stage\n");
    ind=rechercheStag(Tab_Ref,Tlog,5623);
    SupprimeCandidature(Tab_Ref,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,Tlog,138,ind);
    afficherInfoStage(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,Tlog,ref);
}

//VERIFIED !!// 
void testAccepteEtu(void){
    int Tab_Etu[]={101,124,236,520};
    float Tab_Note[]={-1,-1,-1,-1};
    int Tab_RSta[]={-1,-1,-1,-1};
    int Tab_Ref[]= {5008,2001,8000,5623,2388};
    int Tab_Dep[]= {26,56,80,63,95};
    int Tab_EtuAcc[]= {0,1,0,0,0};
    int Tab_NCand[]={0,0,1,2,3};
    int Tab_Cand1[]={0,0,101,138,101};
    int Tab_Cand2[]={0,0,0,101,94};
    int Tab_Cand3[]={0,0,0,0,458};
    int TlogEtu=4,TlogSta=5,ind; 
    printf("--Test Accepté Etudiant\n");
    printf("Table des étudiants :\n");
    afficheTabEnt(Tab_Etu,TlogEtu);
    printf("Table des références de stages associés à l'étudiant\n");
    afficheTabEnt(Tab_RSta,TlogEtu);
    printf("affichage de tous les stages où l'étudiant 101 a fait des demandes :\n");
    afficherInfoStage(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,TlogSta,8000);
    afficherInfoStage(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,TlogSta,5623);
    afficherInfoStage(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,TlogSta,2388);
    printf("Etudiant accepté dans le stage 8000, mise à jour des Stages :\n");
    accepteEtu(Tab_Etu,Tab_RSta,Tab_Ref,Tab_EtuAcc,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,TlogEtu,TlogSta,8000,101);
    afficherInfoStage(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,TlogSta,8000);
    afficherInfoStage(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,TlogSta,5623);
    afficherInfoStage(Tab_Ref,Tab_Dep,Tab_EtuAcc,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,TlogSta,2388);
    printf("Table des références de stages associés à l'étudiant\n");
    afficheTabEnt(Tab_RSta,TlogEtu);
}
/* a refaire
void testajoutCand() {
    int Tab_Etu[5] = {101, 102, 103, 104, 105};  
    int Tab_Cand1[10] = {0,0,0,0,0,0,0,0,0,0};  
    int Tab_Cand2[10] = {0,0,0,0,0,0,0,0,0,0};  
    int Tab_Cand3[10] = {0,0,0,0,0,0,0,0,0,0};  
    int Tab_NCand[10] = {0,0,0,0,0,0,0,0,0,0}; 
    int Tab_Ref[5] = {10, 11, 12, 13, 14};  
    int Tlog = 10;  
    int tailleM = 100;  
    int numEtu, refStage;

    printf("Test 1: Ajout de la candidature pour l'étudiant 101 au stage 10\n");
    numEtu = 101;
    refStage = 10;
    int result = ajoutCand(Tab_Etu, Tab_Cand1, Tab_Cand2, Tab_Cand3, Tlog, Tab_NCand, Tab_Ref, tailleM);
    
    if (result == 0) {
        printf("Test réussi: Candidature ajoutée.\n");
    } else {
        printf("Test échoué: Erreur lors de l'ajout.\n");
    }
    ajoutCand(Tab_Etu, Tab_Cand1, Tab_Cand2, Tab_Cand3, Tlog, Tab_NCand, Tab_Ref, tailleM);
    printf("Tab_Cand1: ");
    for (int i = 0; i < Tlog; i++) {
        printf("%d ", Tab_Cand1[i]);
    }
    printf("\n");

    printf("Test 2: Ajout de la candidature pour l'étudiant 102 au stage 11\n");
    numEtu = 102;
    refStage = 11;
    result = ajoutCand(Tab_Etu, Tab_Cand1, Tab_Cand2, Tab_Cand3, Tlog, Tab_NCand, Tab_Ref, tailleM);

    if (result == 0) {
        printf("Test réussi: Candidature ajoutée.\n");
    } else {
        printf("Test échoué: Erreur lors de l'ajout.\n");
    }

    printf("Tab_Cand1: ");
    for (int i = 0; i < Tlog; i++) {
        printf("%d ", Tab_Cand1[i]);
    }
    printf("\n");

    printf("Test 3: Essayer d'ajouter un étudiant qui a déjà 3 candidatures\n");
    numEtu = 101;
    refStage = 12; 
    result = ajoutCand(Tab_Etu, Tab_Cand1, Tab_Cand2, Tab_Cand3, Tlog, Tab_NCand, Tab_Ref, tailleM);
    
    if (result == 0) {
        printf("Test réussi: Candidature ajoutée.\n");
    } else {
        printf("Test échoué: Erreur lors de l'ajout.\n");
    }
    printf("Tab_Cand1: ");
    for (int i = 0; i < Tlog; i++) {
        printf("%d ", Tab_Cand1[i]);
    }
    printf("\n");

    printf("Tab_Cand2: ");
    for (int i = 0; i < Tlog; i++) {
        printf("%d ", Tab_Cand2[i]);
    }
    printf("\n");

    printf("Tab_Cand3: ");
    for (int i = 0; i < Tlog; i++) {
        printf("%d ", Tab_Cand3[i]);
    }
    printf("\n");

    printf("Test 4: Tester l'ajout d'un étudiant ayant déjà 3 candidatures\n");
    numEtu = 101;
    refStage = 13; 
    result = ajoutCand(Tab_Etu, Tab_Cand1, Tab_Cand2, Tab_Cand3, Tlog, Tab_NCand, Tab_Ref, tailleM);

    if (result == 0) {
        printf("Test réussi: Candidature ajoutée.\n");
    } else {
        printf("Test échoué: Erreur lors de l'ajout.\n");
    }

}
*/
void testMenuChoix() {
    // Initialisation des tableaux et des variables
    int Tab_Ref[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int Tab_EtuAcc[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int Tab_Cand1[10] = {0};
    int Tab_Cand2[10] = {0};
    int Tab_Cand3[10] = {0};
    int Tab_NCand[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int Tab_Dep[10] = {30,64,64,64,02,03,82,92,15,64};
    int Tab_Etu[10] = {101,102, 103, 104, 105, 106, 107, 108, 109, 110};
    int Tab_RSta[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    float Tab_Note[10] = {12.5, 14.3, 11.0, 16.7, 13.5, 10.2, 18.0, 9.3, 15.0, 17.5};

    int TlogCan = 10,TlogEtu=10;
    int tailleM=100;

    // Appel de la fonction menuChoix
    menuChoix(Tab_Ref, Tab_EtuAcc,TlogEtu, TlogCan, Tab_Cand1, Tab_Cand2, Tab_Cand3, Tab_NCand, Tab_Dep, Tab_Etu, Tab_RSta, Tab_Note,tailleM);
}

//pas vérifier
void test_global(void) {
    FILE *flot ;
    flot = fopen("Etudiant.don", "r");
    if (flot!=NULL) {
        printf("Erreur lors de la lecture du fichier Etudiant.don");
        return;
    }
    fclose(flot);
    FILE *fe ;
    fe = fopen("Stage.don", "r");
    if (fe!=NULL) {
        printf("Erreur lors de la lecture du fichier Stage.don");
        return;
    }
    fclose(fe);
    global();
    printf("Test de la fonction 'global' terminé.\n");
}

//pas vérifier
void test_affichageToutStageAvecCandidature(void) {
    int Tab_Ref[]= {5008,2001,8000,5623};
    int Tab_EtuAcc[]= {0,1,0,1};
    int Tab_Cand1[5] = {1, 2, 3, 4, 5};
    int Tab_Cand2[5] = {2, 3, 4, 5, 6};
    int Tab_Cand3[5] = {3, 4, 5, 6, 7};
    int Tab_NCand[5] = {3, 2, 1, 0, 0}; // Nombre de candidatures
    int Tlog = 4;
    printf("Test de la fonction affichageToutStageAvecCandidature:\n");
    affichageToutStageAvecCandidature(Tab_Ref, Tab_EtuAcc, Tlog, Tab_Cand1, Tab_Cand2, Tab_Cand3, Tab_NCand);
}

void testAfficherStagesParDepartement() {
    // Valeurs de test
    int Tab_Ref[] = {5008, 2001, 8000, 5623};
    int Tab_Dep[] = {1, 2, 3, 3};
    int Tlog = 4;  
    printf("Test 1: Département 3\n");
    afficherStagesParDepartement(Tab_Ref, Tab_Dep, Tlog, 3);  // Département 3
    printf("\n");

    printf("Test 2: Département 4 (inexistant)\n");
    afficherStagesParDepartement(Tab_Ref, Tab_Dep, Tlog, 4);  // Département 4 qui n'existe pas
    printf("\n");
}

void test_afficherStageAffecte(void) {
    int Tab_Etu[5] = {1, 2, 3, 4, 5};
    int Tab_RSta[5] = {101, 102, -1, 104, 105};  // -1 signifie aucun stage affecté
    int Tlog = 5;
    int Netu = 3;
    printf("Test de la fonction afficherStageAffecte:\n");
    afficherStageAffecte(Tab_Etu, Tab_RSta, Tlog, Netu);
}

int main(void){
    testMenuChoix();
    testAccepteEtu();
    /*
    testajoutCand();
    testRecherche();
    printf("\n\n");
    testRechercheStag();
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
    testajoutNote();
    printf("\n\n");
    testSupprimeCandidature();
    printf("\n\n");
    testAccepteEtu();
    printf("\n\n");
    test_afficherCandidaturesEtudiant();
    printf("\n\n");
    test_afficherStagesParCritere();
    printf("\n\n");
    testajoutOffre();
    test_global();
    printf("\n1\n");
    test_affichageToutStageAvecCandidature();
    test_afficherStageAffecte();
    */
    testAfficherStagesParDepartement();
    
    return 0;
}