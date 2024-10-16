#include"Sae1.h"

int ChargementEtu(int Tab_Etu[], int Tab_RSta[],float Tab_Note[],int Tmax ){
    int ind=0,Netu,RSta,trouve,rech_ind;
    float Note;
    FILE *flot;
    flot=fopen("Etudiant.don","r");
    if (flot==NULL)
        printf("Problème d'ouverture du fichier Etudiant.don");
        return -1;
    fscanf(flot,"%d%d%f",&Netu,&RSta,&Note);
    while(!feof(flot)){
        if (ind==Tmax){
            printf("PB : Nombre d'étudiant à gérer trop grand, le tableau est trop petit");
            fclose(flot);
            return -2;
        }
        rech_ind=Recherche(Tab_Etu,ind,Netu,&trouve);
        if (trouve==1){
            printf("PB : Etudiant %d A plus d'une occurence",Netu);
            fclose(flot);
            return -2;
        }
        DecalerADroiteI(Tab_Etu,rech_ind,ind);
        DecalerADroiteI(Tab_RSta,rech_ind,ind);
        DecalerADroiteF(Tab_Note,rech_ind,ind);
        Tab_Etu[rech_ind]=Netu;
        Tab_RSta[rech_ind]=RSta;
        Tab_Note[rech_ind]=Note;
        ind=ind+1;
        fscanf(flot,"%d%d%f",&Netu,&RSta,&Note);
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

int Inserer(int Tab_Etu[],int Tab_RSta[],int Tab_Note,int val, int *Tlog,int Tmax,int RSta,int Note)
{
    int i=0,trouve;
    i=rechercher(val,Tab_Etu,*Tlog,&trouve);
    if(trouve==1)
        return -1;
    if(*Tlog==Tmax)
        return -2;
    DecalerADroiteI(Tab_Etu,i,*Tlog);
    DecalerAdroiteI(Tab_RSta,i,*Tlog);
    DecalerADroiteF(Tab_Note,i,*Tlog);
    Tab_Etu[i] = val;
    Tab_RSta[i]= RSta;
    Tab_Note[i] = Note;
    *Tlog = *Tlog +1;
    return 0;
}

int Recherche(int tab[],int taille,int val,int *trouve){
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

int DecalerADroiteI(int tab[],int ind,int *tLog){
    int i;
    for (i=*tlog;i=ind;i--){
        tab[i]=tab[i-1];
    }
}

int DecalerADroiteF(float tab[],int ind,int *tLog){
    int i;
    for (i=*tlog;i=ind;i--){
        tab[i]=tab[i-1];
    }
}

