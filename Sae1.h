#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int ChargementEtu(int Tab_Etu[], int Tab_RSta[],int Tab_Note[],int Tmax );
int ChargementOffre(int Tab_ref[], int Tab_Dep[],int Tmax );
int Inserer(int Tab_Etu[],int Tab_RSta[],int Tab_Note,int val, int *Tlog,int Tmax,int RSta,int Note);
int Recherche(int tab[],int taille,int val,int *trouve);
int DecalerADroiteI(int tab[],int ind,int *tLog);
int DecalerADroiteF(float tab[],int ind,int *tLog);