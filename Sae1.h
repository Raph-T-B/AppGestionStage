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
int ajoutNote(int Tab_Etu[],float Tab_Note[],int Tlog);
void sauvegardeEtu(int Tab_Etu[], int Tab_RSta[],float Tab_Note[],int Tlog);
void sauvegardeOffre(int Tab_Ref[], int Tab_Dep[],int Tab_EtuAcc[],int Tab_NCand[],int Tlog,int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[]);
void afficherStagesPourvus(int Tab_Ref[], int Tab_Dep[], int Tab_EtuAcc[], int Tab_Etu[], int Tlog);
void afficherStagesNonPourvus(int Tab_Ref[], int Tab_Dep[], int Tab_EtuAcc[], int Tlog);
void afficherEtudiantsSansStage(int Tab_Etu[], int Tab_RSta[], int Tlog);
void afficherInfoStage(int Tab_Ref[], int Tab_Dep[], int Tab_EtuAcc[], int Tab_NCand[], int Tlog, int ref);
void afficherStagesParCritere(int Tab_Ref[], int Tab_Dep[], int Tlog, char critere, int valeur);
void afficherCandidaturesEtudiant(int Tab_EtuCandidature[], int Tab_RefCandidature[], int TlogCandidature, int Netu);
void afficherStageAffecte(int Tab_Etu[], int Tab_RSta[], int Tlog, int Netu);
void afficherStagesParDepartement(int Tab_Ref[], int Tab_Dep[], int Tlog, int dept);
void menuResponsable(void);
void menuEtudiant(void);
char menuChoix(void);