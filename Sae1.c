#include"Sae1.h"

int chargementEtu(int Tab_Etu[], int Tab_RSta[],float Tab_Note[],int Tmax ){
    int ind=0,Netu,RSta,trouve,rech_ind;
    float Note;
    FILE *flot;
    flot=fopen("Etudiant.don","r");
    if (flot==NULL)
        printf("Problème d'ouverture du fichier 'Etudiant.don'");
        return -1;
    fscanf(flot,"%d%d%f",&Netu,&RSta,&Note);
    while(!feof(flot)){
        if (ind==Tmax){
            printf("PB : Nombre d'étudiant à gérer trop grand, le tableau est trop petit");
            fclose(flot);
            return -2;
        }
        rech_ind=recherche(Tab_Etu,ind,Netu,&trouve);
        if (trouve==1){
            printf("PB : Etudiant %d A plus d'une occurence",Netu);
            fclose(flot);
            return -2;
        }
        decalerADroiteI(Tab_Etu,rech_ind,&ind);
        decalerADroiteI(Tab_RSta,rech_ind,&ind);
        decalerADroiteF(Tab_Note,rech_ind,&ind);
        Tab_Etu[rech_ind]=Netu;
        Tab_RSta[rech_ind]=RSta;
        Tab_Note[rech_ind]=Note;
        ind=ind+1;
        fscanf(flot,"%d%d%f",&Netu,&RSta,&Note);
    }
    fclose(flot);
    return ind;
}

/// @brief Fonction servant à charger le fichier des Offres
/// @param Tab_Ref : Tableau contenant les références de stage
/// @param Tab_Dep : Tableau contenant les Départements des stages
/// @param Tab_EtuAcc : Tableau contenant si un stage à accépté un étudiant
/// @param Tab_NCand : Tableau contenant le nombre de candidature d'étudiants
/// @param Tmax : Taille maximum des tableau
/// @return -1 s'il y a un problème, la taille logique du tableau sinon
int chargementOffre(int Tab_Ref[], int Tab_Dep[],int Tab_EtuAcc[],int Tab_NCand[],int Tmax){
    int ind=0,Ref,Dep,Etu_acc,nbr_cand;
    FILE *flot;
    flot=fopen("Stage.don","r");
    if (flot==NULL){
        printf("Problème d'ouverture du fichier 'Stage.don'");
        return -1;
    }
    fscanf(flot,"%d%d",&Ref,&Dep);
    while(!feof(flot)){
        if (ind==Tmax){
            fclose(flot);
            printf("PB: Nombre d'offre à gérer trop grand, tableau trop petit");
            return -1;
        }
        Tab_Ref[ind]=Ref;
        Tab_Dep[ind]=Dep;
        fscanf(flot,"%d",&Etu_acc);
        Tab_EtuAcc[ind]=Etu_acc;
        if (Etu_acc==0)
            fscanf(flot,"%d",&nbr_cand);
            Tab_NCand[ind]=nbr_cand;
        
        ind=ind+1;
        fscanf(flot,"%d%d",&Ref,&Dep);
    }
    fclose(flot);
    return ind;
}

/// @brief Fonction servant à insérer un nouvel étudiant
/// @param Tab_Etu : Table contenant les étudiants
/// @param Tab_RSta : Table contenant les références de stage
/// @param Tab_Note : Table contenant les notes de fin de stage
/// @param NEtu : Numéro de l'étudiant à ajouter
/// @param Tlog : Taille logique des tables
/// @param Tmax : Taille physique(max) des tables
/// @return : -1 s'il y a un problème et 0 sinon
int inserer(int Tab_Etu[],int Tab_RSta[],float Tab_Note[],int NEtu, int *Tlog,int Tmax)
{
    int i=0,trouve;
    i=recherche(Tab_Etu,*Tlog,NEtu,&trouve);
    if(trouve==1){
        printf("PB: Etudiant déjà existant");
        return -1;
    }
    if(*Tlog==Tmax){
        printf("PB: Tableau trop petit");
        return -1;
    }
    decalerADroiteI(Tab_Etu,i,Tlog);
    decalerADroiteI(Tab_RSta,i,Tlog);
    decalerADroiteF(Tab_Note,i,Tlog);
    Tab_Etu[i] = NEtu;
    Tab_RSta[i]= -1;
    Tab_Note[i] = -1;
    *Tlog = *Tlog +1;
    return 0;
}

/// @brief Recherche d'un variable dans un tableau d'entiers
/// @param tab 
/// @param taille 
/// @param val 
/// @param trouve 
/// @return 

int recherche(int tab[],int taille,int val,int *trouve){
    int ind=0;
    for (ind=0;ind<taille;ind++){
        if (tab[ind]>=val){
            if (tab[ind]==val)
                *trouve=1;
            else *trouve=0;
            return ind;
        }
    }
    *trouve=0;
    return taille;
}

int decalerADroiteI(int tab[],int ind,int *tLog){
    int i;
    for (i=*tLog;i=ind;i--){
        tab[i]=tab[i-1];
    }
}

int decalerADroiteF(float tab[],int ind,int *tLog){
    int i;
    for (i=*tLog;i=ind;i--){
        tab[i]=tab[i-1];
    }
}

