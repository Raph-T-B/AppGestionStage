#include"Sae1.h"

int ChargementEtu(int Tab_Etu[], int Tab_RSta[],int Tab_Note[],int Tmax ){
    int ind=0,Netu,RSta,Note;
    FILE *flot;
    flot=fopen("Etudiant.don","r");
    if (flot==NULL)
        return -1;
    fscanf(flot,"%d%d%d",&Netu,&RSta,&Note);
    while(!feof(flot)){
        if (ind==Tmax){
            fclose(flot);
            return -2;
        }
        Recherche(...);
        DecalerADroite(...);
        DecalerADroite(...);
        DecalerADroite(...);
        Tab_Etu[ind]=Netu;
        Tab_RSta[ind]=RSta;
        Tab_Note[ind]=Note;
        ind=ind+1;
        fscanf(flot,"%d%d%d",&Netu,&RSta,&Note);
    }
    fclose(flot);
    return ind;
}

int ChargementOffre(int Tab_Ref[], int Tab_Dep[],int Tab_EtuAcc[],int Tab_NCand[],int Tmax ){
    int ind=0,Ref,Dep,Etu_acc,nbr_cand;
    FILE *flot;
    flot=fopen("Stage.don","r");
    if (flot==NULL)
        return -1;
    fscanf(flot,"%d%d",&Ref,&Dep);
    while(!feof(flot)){
        if (ind==Tmax){
            fclose(flot);
            return -2;
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

int Recherche(int val);