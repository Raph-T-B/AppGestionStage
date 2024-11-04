#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int chargementEtu(int Tab_Etu[], int Tab_RSta[],float Tab_Note[],int Tmax );
int chargementOffre(int Tab_Ref[], int Tab_Dep[],int Tab_EtuAcc[],int Tab_NCand[],int Tmax);
int inserer(int Tab_Etu[],int Tab_RSta[],float Tab_Note[],int NEtu, int *Tlog,int Tmax);
int recherche(int tab[],int taille,int val,int *trouve);
int decalerADroiteI(int tab[],int ind,int *tLog);
int decalerADroiteF(float tab[],int ind,int *tLog);