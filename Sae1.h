#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/// @brief Fonction servant à charger le fichier des etudiants
/// @param Tab_Etu : Tableau contenant les numéros etudiants
/// @param Tab_RSta : Tableau contenant la référence de stage des etudiants
/// @param Tab_Note : Tableau contenant les notes des etudiants
/// @param Tmax : Taille max des tableaux
/// @return : La taille logique des tableaux
int chargementEtu(int Tab_Etu[], int Tab_RSta[],float Tab_Note[],int Tmax,FILE *fich );
/// @brief Fonction servant à charger le fichier des Offres
/// @param Tab_Ref : Tableau contenant les références des stages
/// @param Tab_Dep : Tableau contenant les Départements des stages
/// @param Tab_EtuAcc : Tableau contenant si un stage a accépté un étudiant
/// @param Tab_NCand : Tableau contenant le nombre de candidature d'étudiants
/// @param Tab_Cand1 : Contient le premier numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand2 : Contient le deuxième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand3 : Contient le troisième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tmax : Taille maximum des tableau
/// @return -1 s'il y a un problème, la taille logique du tableau sinon
int chargementOffre(int Tab_Ref[], int Tab_Dep[],int Tab_EtuAcc[],int Tab_NCand[],int Tmax,int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[],FILE *fich);
/// @brief Fonction servant à insérer un nouvel étudiant
/// @param Tab_Etu : Table contenant les étudiants
/// @param Tab_RSta : Table contenant les références de stage pour les etudiants
/// @param Tab_Note : Table contenant les notes de fin de stage
/// @param NEtu : Numéro de l'étudiant à ajouter
/// @param Tlog : Taille logique des tables
/// @param Tmax : Taille physique(max) des tables (Tb_Etu Tab_Rsta Tab_Note)
/// @return : -1 s'il y a un problème et 0 sinon
int inserer_etu(int Tab_Etu[],int Tab_RSta[],float Tab_Note[],int NEtu, int *Tlog,int Tmax);
/// @brief Recherche d'un variable dans un tableau d'entiers trié
/// @param tab : Tableau dans lequel la recherche va être effectué
/// @param taille : La taille logique du tableau
/// @param val : la valeur à rechercher
/// @param trouve : Pour savoir si la valeur est trouvé dans le tableau
/// @return : l'indice où l'on va insérer la valeur (1 si trouvé, 0 sinon)
int recherche(int tab[],int taille,int val,int *trouve);
/// @brief Recherche dans une valeur unique dans le tableau tab 
/// @param tab tab dans lequel la valeur est recherché
/// @param taille taille logique du tableau
/// @param val valeur à recherché
/// @return l'indice de la valeur val dans le tableau tab, -1 si pas trouvé
int rechercheStag(int tab[],int taille,int val);
/// @brief Décale le contenu du tableau d'entiers d'une case vers la droite
/// @param tab : Tableau dans lequel le décalage va être effectué
/// @param tailleM : taille max du tableau 
/// @param ind : indice à partir duquel le tableau va être décalé
/// @param tLog : taille logique du tableau
/// @return : 0 si pas de problème, et -1 si la taille max du tableau est dépassé
int decalerADroiteI(int tab[],int tailleM,int ind,int *tLog);
/// @brief Décale le contenu du tableau de float d'une case vers la droite
/// @param tab : Tableau dans lequel le décalage va être effectué
/// @param tailleM : taille max du tableau 
/// @param ind : indice à partir duquel le tableau va être décalé
/// @param tLog : taille logique du tableau
/// @return : 0 si pas de problème, et -1 si la taille max du tableau est dépassé
int decalerADroiteF(float tab[],int tailleM,int ind,int *tLog);
/// @brief Affiche le contenu d'un tableau d'entier en format tableau :[,,,]
/// @param tab table à afficher
/// @param Tlog taille logique du tableau
void afficheTabEnt(int tab[],int Tlog);
/// @brief Affiche le contenu d'un tableau de float en format tableau :[,,,]
/// @param tab table à afficher
/// @param Tlog taille logique du tableau
void afficheTabFlo(float tab[],int Tlog);
/// @brief  Fonction d'affichage des infos d'un stage donné en argument
/// @param Tab_Ref : Tableau contenant les références des stages
/// @param Tab_Dep : Tableau contenant les Départements des stages
/// @param Tab_EtuAcc : Tableau contenant si un stage a accépté un étudiant
/// @param Tab_Etu : Table contenant les étudiants
/// @param Tab_RSta : Table contenant les références de stage pour les etudiants
/// @param Tlog : taille logique du tableau
void afficherStagesPourvus(int Tab_Ref[], int Tab_Dep[], int Tab_EtuAcc[], int Tab_Etu[],int Tab_RSta[], int Tlog);
/// @brief  Fonction d'affichage des stages non pourvus d'étudiants
/// @param Tab_Ref : Tableau contenant les références des stages
/// @param Tab_Dep : Tableau contenant les Départements des stages
/// @param Tab_EtuAcc : Tableau contenant si un stage a accépté un étudiant
/// @param Tlog : taille logique du tableau
void afficherStagesNonPourvus(int Tab_Ref[], int Tab_Dep[], int Tab_EtuAcc[], int Tlog);
/// @brief Fonction d'affichage des etudiants sans stage
/// @param Tab_Etu : Table contenant les étudiants
/// @param Tab_RSta : Table contenant les références de stage pour les etudiants
/// @param Tlog : taille logique du tableau
void afficherEtudiantsSansStage(int Tab_Etu[], int Tab_RSta[], int Tlog);
/// @brief Fonction d'affichage des infos d'un stage donné en argument
/// @param Tab_Ref : Tableau contenant les références des stages
/// @param Tab_Dep : Tableau contenant les Départements des stages
/// @param Tab_EtuAcc : Tableau contenant si un stage a accépté un étudiant
/// @param Tab_NCand : Tableau contenant les Départements des stages
/// @param Tab_Cand1 : Contient le premier numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand2 : Contient le deuxième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand3 : Contient le troisième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tlog : taille logique du tableau
/// @param ref : référence de stage pour lequel on cherche des informations
void afficherInfoStage(int Tab_Ref[], int Tab_Dep[], int Tab_EtuAcc[], int Tab_NCand[],int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[], int Tlog, int ref);
/// @brief Affiche les stages en fonction d'un critère donné (numéro de stage ou département)
/// @param Tab_Ref : Tableau des références de stages
/// @param Tab_Dep : Tableau des départements des stages
/// @param Tlog : Taille logique des tableaux
/// @param critere : Critère de recherche : numéro de stage ou département
/// @param valeur : Valeur à rechercher pour le critère
void afficherStagesParCritere(int Tab_Ref[], int Tab_Dep[], int Tlog, char critere, int valeur);
/// @brief Ajout d'une cadnidature a un stage si les conditions sont remplis.
/// @param Tab_Etu : Tableau contenant les numéros etudiants
/// @param Tab_Cand1 : Contient le premier numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe).
/// @param Tab_Cand2  : Contient le deuxieme numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe).
/// @param Tab_Cand3 : Contient le troisieme numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe).
/// @param Tlog : Contient la taille logique du tableau.
/// @param Tab_NCand : Tableau contenant le nombre de candidature pour un stage.
/// @param Tab_Ref : Tableau contenant la référence pour chaque stage.
/// @param tailleM : Contient la taille max du tableau
/// @return : -1 si le programme a été arrété, 0 s'il a fontionné.
void affichageToutStageAvecCandidature(int Tab_Ref[], int Tab_EtuAcc[], int Tlog, int Tab_Cand1[], int Tab_Cand2[], int Tab_Cand3[], int Tab_NCand[]);
/// @brief Affiche tous les stages auxquels un étudiant donné a candidaté.
/// @param Tab_RefCand : Tableau des références des stages pour chaque candidature.
/// @param TlogCand : Taille logique du tableau de candidatures.
/// @param Tab_NCand : Tableau contenant les Départements des stages
/// @param Tab_Cand1 : Contient le premier numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand2 : Contient le deuxième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand3 : Contient le troisième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Netu : Numéro de l'étudiant à rechercher.
void afficherCandidaturesEtudiant(int Tab_RefCand[], int TlogCand,int Tab_NCand[],int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[], int Netu);
/// @brief Affiche le stage affecté à un étudiant donné, s'il y a lieu.
/// @param Tab_Etu : Tableau des étudiants.
/// @param Tab_RSta : Tableau des stages affectés à chaque étudiant.
/// @param Tlog : Taille logique des tableaux.
/// @param Netu : Numéro de l'étudiant à rechercher.
void afficherStageAffecte(int Tab_Etu[], int Tab_RSta[], int Tlog, int Netu);
/// @brief Affiche tous les stages d'un département donné.
/// @param Tab_Ref : Tableau contenant les références des stages
/// @param Tab_Dep : Tableau des départements associés à chaque stage.
/// @param Tlog : Taille logique des tableaux.
/// @param dept : Numéro du département à rechercher.
void afficherStagesParDepartement(int Tab_Ref[], int Tab_Dep[], int Tlog, int dept);
/// @brief Fonction pour accepter un étudiant donné à un stage
/// @param Tab_Etu : Tableau contenant les numéros etudiants
/// @param Tab_RSta : Tableau contenant la référence de stage des etudiants
/// @param Tab_Ref : Tableau contenant les références des stages
/// @param Tab_EtuAcc : Tableau contenant si un stage a accépté un étudiant
/// @param Tab_NCand : Tableau contenant les Départements des stages
/// @param Tab_Cand1 : Contient le premier numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand2 : Contient le deuxième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand3 : Contient le troisième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param TlogEtu : Taille logique des tableaux Etu/RSta
/// @param TlogSta : Taille logique des tableaux Ref/NCand/Cand1/Cand2/Cand3
/// @param refStage : Référence du stage à changer
/// @param num_Etu : Numéro d'étudiant accepté
void accepteEtu(int Tab_Etu[],int Tab_Rsta[],int Tab_Ref[],int Tab_EtuAcc[],int Tab_NCand[],int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[],int TlogEtu,int TlogSta,int refStage, int num_Etu);
/// @brief Fonction qui supprime un candidat
/// @param Tab_Ref : Tableau contenant les références des stages
/// @param Tab_NCand : Tableau contenant les Départements des stages
/// @param Tab_Cand1 : Contient le premier numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand2 : Contient le deuxième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand3 : Contient le troisième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tlog : Taille logique des tableaux
/// @param etu : numéro de l'étudiant à supprimer
/// @param stage : l'indice du stage où l'étudiant est supprimé
void SupprimeCandidature(int Tab_Ref[],int Tab_NCand[],int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[],int Tlog,int etu,int ind);
/// @brief Fonction pour ajouter une note à un étudiant
/// @param Tab_Etu : Tableau contenant les numéros etudiants
/// @param Tab_RSta : Tableau contenant les références des stages attribué aux étudiants
/// @param Tab_Note : Tableau contenant les notes des etudiants
/// @param Tlog : Taille logique du tableau
/// @return : -1 si le programme a été arrété, 0 s'il a fontionné
int ajoutNote(int Tab_Etu[],int Tab_RSta[],float Tab_Note[],int Tlog);
//Non vérifiée
int ajoutCand(int Tab_Etu[], int Tab_Cand1[], int Tab_Cand2[], int Tab_Cand3[], int TlogEtu,int TlogCan, int Tab_NCand[],int Tab_Ref[],int tailleM);
/// @brief Fonction pour ajouter une offre
/// @param Tab_Ref : Tableau contenant les références des stages
/// @param Tab_Dep : Tableau contenant les départements des stages
/// @param Tab_EtuAcc : Tableau contenant si un stage a accépté un étudiant: 
/// @param Tab_NCand : Tableau contenant le nombre de candidats aux stage 
/// @param Tlog : Taille logique des tableau
/// @return : -1 si le programme a été arrété, 0 s'il a fontionné
int ajoutOffre(int Tab_Ref[],int Tab_Dep[],int Tab_EtuAcc[],int Tab_NCand[],int *Tlog,int Tmax);
/// @brief Fonction de sauvegarde des tables Tab_Etu/Rsta/Note dans le fichier Etudiant.don
/// @param Tab_Etu Table contenant les Numéros des étudiants
/// @param Tab_RSta Table contenant les Références du stage où les étudiants ont été acceptés 
/// @param Tab_Note Table contenant les Notes des etudiants reçue durant leur stage
/// @param Tlog Taille logique de ces tableaux
void sauvegardeEtu(int Tab_Etu[], int Tab_RSta[],float Tab_Note[],int Tlog,FILE *fich);
/// @brief Fonction de sauvegarde des tables Tab_Ref/Dep/EtuAcc/NCand/Cand1/Cand2/Cand3 dans le fichier Stage.don
/// @param Tab_Ref Tableau contenant les Références des stages
/// @param Tab_Dep Tableau contenant les Départements des stages
/// @param Tab_EtuAcc Tableau contenant si un stage a accépté un étudiant
/// @param Tab_NCand Tableau contenant le nombre de candidature d'étudiants
/// @param Tlog Taille logique de ces tableaux
/// @param Tab_Cand1 Contient le premier numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand2 Contient le deuxième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand3 Contient le troisième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
void sauvegardeOffre(int Tab_Ref[], int Tab_Dep[],int Tab_EtuAcc[],int Tab_NCand[],int Tlog,int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[],FILE *fich);
/// @brief Menu responsable qui lui affiche les différentes action réalisable.
/// @param Tab_Ref Tableau contenant les Références des stages
/// @param Tab_EtuAcc Tableau contenant si un stage a accépté un étudiant
/// @param TlogEtu Taille logique des ableaux associès aux etudiants
/// @param TlogCan Taille logique des tableaux associès aux stages
/// @param Tab_Cand1 Contient le premier numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand2 Contient le deuxieme numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand3 Contient le troisieme numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_NCand Tableau contenant le nombre de candidature d'étudiants
/// @param Tab_Dep Tableau contenant le departement des stages
/// @param Tab_Etu Table contenant les Numéros des étudiants
/// @param Tab_RSta Table contenant les Références du stage où les étudiants ont été acceptés 
/// @param Tab_Note Table contenant les Notes des etudiants reçue durant leur stage
/// @param Netu Numéro etudiant
/// @param tailleM Taille maximal des tableaux.
void menuResponsable(int Tab_Ref[], int Tab_EtuAcc[], int TlogEtu, int TlogCan, int Tab_Cand1[], int Tab_Cand2[], int Tab_Cand3[], int Tab_NCand[],int Tab_Dep[],int Tab_Etu[],int Tab_RSta[], float Tab_Note[],int tailleM,int Netu,int *quit);
/// @brief Menu etudiant qui lui affiche les différentes action réalisable.
/// @param Tab_Ref Tableau contenant les Références des stages
/// @param Tab_Dep Tableau contenant le departement des stages
/// @param Tab_EtuAcc Tableau contenant si un stage a accépté un étudiant
/// @param TlogEtu Taille logique des ableaux associès aux etudiants
/// @param TlogCan Taille logique des tableaux associès aux stages
/// @param Netu Numéro etudiant
/// @param Tab_Etu Table contenant les Numéros des étudiants
void menuEtudiant(int Tab_Ref[], int Tab_Dep[], int Tab_EtuAcc[], int TlogEtu, int TlogCan,int Netu, int Tab_Etu[],int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[],int Tab_NCand[],int tailleM,int *quit);
/// @brief Lit le fichier .mdpRespo pour avoir le mdp
/// @return le mdp décrypté
int OuvrmdpRespo(void);
/// @brief Met le mot de passe du respo dans le fichier .mdpRespo et le crypte
/// @param motdp : mdp à changer
void SauvmdpRespo(int motdp);
/// @brief Fonction de changement du mdp respo 
void changerMDP(void);
/// @brief Menu qui permet de designer si nous sommes un etudiant ou un responsable de stage.
/// @param Tab_Ref Tableau contenant les Références des stages
/// @param Tab_EtuAcc Tableau contenant si un stage a accépté un étudiant
/// @param TlogEtu Taille logique des ableaux associès aux etudiants
/// @param TlogCan Taille logique des tableaux associès aux stages
/// @param Tab_Cand1 Contient le premier numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand2 Contient le deuxieme numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand3 Contient le troisieme numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_NCand Tableau contenant le nombre de candidature d'étudiants
/// @param Tab_Dep Tableau contenant le departement des stages
/// @param Tab_Etu Table contenant les Numéros des étudiants
/// @param Tab_RSta Table contenant les Références du stage où les étudiants ont été acceptés 
/// @param Tab_Note Table contenant les Notes des etudiants reçue durant leur stage
/// @param tailleM Taille maximal des tableaux.
/// @return 1 si Etudiant et 2 si responsable
int menuChoix(int Tab_Ref[], int Tab_EtuAcc[], int TlogEtu,int TlogCan, int Tab_Cand1[], int Tab_Cand2[], int Tab_Cand3[], int Tab_NCand[],int Tab_Dep[],int Tab_Etu[],int Tab_RSta[], float Tab_Note[],int tailleM);
/// @brief Fonction permettant la mise en relation de toute les autres fonction.
void global(void);