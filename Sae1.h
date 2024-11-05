#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int chargementEtu(int Tab_Etu[], int Tab_RSta[],float Tab_Note[],int Tmax );
int chargementOffre(int Tab_Ref[], int Tab_Dep[],int Tab_EtuAcc[],int Tab_NCand[],int Tmax,int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[]);
int inserer(int Tab_Etu[],int Tab_RSta[],float Tab_Note[],int NEtu, int *Tlog,int Tmax);
int recherche(int tab[],int taille,int val,int *trouve);
int decalerADroiteI(int tab[],int tailleM,int ind,int *tLog);
int decalerADroiteF(float tab[],int tailleM,int ind,int *tLog);
void afficherInfoStage(int Tab_Ref[], int Tab_Dep[], int Tab_EtuAcc[], int Tab_NCand[], int Tlog, int ref);
void afficherStagesPourvus(int Tab_Ref[], int Tab_Dep[], int Tab_EtuAcc[], int Tab_Etu[], int Tlog);
void afficherStagesNonPourvus(int Tab_Ref[], int Tab_Dep[], int Tab_EtuAcc[], int Tlog);
void afficherEtudiantsSansStage(int Tab_Etu[], int Tab_RSta[], int Tlog);

