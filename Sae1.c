#include"Sae1.h"

/// @brief Fonction servant à charger le fichier des etudiants
/// @param Tab_Etu : Tableau contenant les numéros etudiants
/// @param Tab_RSta : Tableau contenant la référence de stage des etudiants
/// @param Tab_Note : Tableau contenant les notes des etudiants
/// @param Tmax : Taille max des tableaux
/// @return : La taille logique des tableaux
int chargementEtu(int Tab_Etu[], int Tab_RSta[],float Tab_Note[],int Tmax,FILE *fich){
    int ind=0,Netu,RSta,trouve,rech_ind;
    float Note;
    fich=fopen("Etudiant.don","r");
    if (fich==NULL)
        printf("Problème d'ouverture du fichier 'Etudiant.don'");
        return -1;
    fscanf(fich,"%d%d%f",&Netu,&RSta,&Note);
    while(!feof(fich)){
        if (ind==Tmax){
            printf("PB : Nombre d'étudiant à gérer trop grand, le tableau est trop petit");
            fclose(fich);
            return -2;
        }
        rech_ind=recherche(Tab_Etu,ind,Netu,&trouve);
        if (trouve==1){
            printf("PB : Etudiant %d A plus d'une occurence",Netu);
            fclose(fich);
            return -2;
        }
        decalerADroiteI(Tab_Etu,Tmax,rech_ind,&ind);
        decalerADroiteI(Tab_RSta,Tmax,rech_ind,&ind);
        decalerADroiteF(Tab_Note,Tmax,rech_ind,&ind);
        Tab_Etu[rech_ind]=Netu;
        Tab_RSta[rech_ind]=RSta;
        Tab_Note[rech_ind]=Note;
        ind=ind+1;
        fscanf(fich,"%d%d%f",&Netu,&RSta,&Note);
    }
    fclose(fich);
    return ind;
}

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
int chargementOffre(int Tab_Ref[], int Tab_Dep[],int Tab_EtuAcc[],int Tab_NCand[],int Tmax,int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[],FILE *fich){
    int ind=0,Ref,Dep,Etu_acc,nbr_cand,num;
    fich=fopen("Stage.don","r");
    if (fich==NULL){
        printf("Problème d'ouverture du fichier 'Stage.don'");
        return -1;
    }
    fscanf(fich,"%d%d",&Ref,&Dep);
    while(!feof(fich)){
        if (ind==Tmax){
            fclose(fich);
            printf("PB: Nombre d'offre à gérer trop grand, tableau trop petit");
            return -1;
        }
        Tab_Ref[ind]=Ref;
        Tab_Dep[ind]=Dep;
        fscanf(fich,"%d",&Etu_acc);
        Tab_EtuAcc[ind]=Etu_acc;
        if (Etu_acc==0)
        {
            fscanf(fich,"%d",&nbr_cand);
            Tab_NCand[ind]=nbr_cand;
            if(nbr_cand>0){   
                fscanf(fich,"%d",&num);
                Tab_Cand1[ind]= num;
            }
            if(nbr_cand>1)
            {
                fscanf(fich,"%d",&num);
                Tab_Cand2[ind]= num;
            }
            if(nbr_cand>2)
            {
                fscanf(fich,"%d",&num);
                Tab_Cand3[ind]=num;
            }
        }
        ind=ind+1;
        fscanf(fich,"%d%d",&Ref,&Dep);
    }
    fclose(fich);
    return ind;
}

/// @brief Fonction servant à insérer un nouvel étudiant
/// @param Tab_Etu : Table contenant les étudiants
/// @param Tab_RSta : Table contenant les références de stage pour les etudiants
/// @param Tab_Note : Table contenant les notes de fin de stage
/// @param NEtu : Numéro de l'étudiant à ajouter
/// @param Tlog : Taille logique des tables
/// @param Tmax : Taille physique(max) des tables (Tb_Etu Tab_Rsta Tab_Note)
/// @return : -1 s'il y a un problème et 0 sinon
int inserer_etu(int Tab_Etu[],int Tab_RSta[],float Tab_Note[],int NEtu, int *Tlog,int Tmax){
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
    decalerADroiteI(Tab_Etu,Tmax,i,Tlog);
    decalerADroiteI(Tab_RSta,Tmax,i,Tlog);
    decalerADroiteF(Tab_Note,Tmax,i,Tlog);
    Tab_Etu[i] = NEtu;
    Tab_RSta[i]= -1;
    Tab_Note[i] = -1;
    *Tlog = *Tlog +1;
    return 0;
}

/// @brief Recherche d'un variable dans un tableau d'entiers trié
/// @param tab : Tableau dans lequel la recherche va être effectué
/// @param taille : La taille logique du tableau
/// @param val : la valeur à rechercher
/// @param trouve : Pour savoir si la valeur est trouvé dans le tableau
/// @return : l'indice où l'on va insérer la valeur (1 si trouvé, 0 sinon)
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

/// @brief Recherche dans une valeur unique dans le tableau tab 
/// @param tab tab dans lequel la valeur est recherché
/// @param taille taille logique du tableau
/// @param val valeur à recherché
/// @return l'indice de la valeur val dans le tableau tab, -1 si pas trouvé
int rechercheStag(int tab[],int taille,int val){
    int ind=0;
    for(ind=0;ind<taille;ind++){
        if (tab[ind]==val)
            return ind;
    }
    return -1;
}


/// @brief Décale le contenu du tableau d'entiers d'une case vers la droite
/// @param tab : Tableau dans lequel le décalage va être effectué
/// @param tailleM : taille max du tableau 
/// @param ind : indice à partir duquel le tableau va être décalé
/// @param tLog : taille logique du tableau
/// @return : 0 si pas de problème, et -1 si la taille max du tableau est dépassé
int decalerADroiteI(int tab[],int tailleM,int ind,int *tLog){
    int i;
    if (tailleM==*tLog){
        printf("Problème de taille de tableau : trop petit");
        return -1;
    }
    for (i=*tLog;i>ind;i--){
        tab[i]=tab[i-1];
    }
    return 0;
}

/// @brief Décale le contenu du tableau de float d'une case vers la droite
/// @param tab : Tableau dans lequel le décalage va être effectué
/// @param tailleM : taille max du tableau 
/// @param ind : indice à partir duquel le tableau va être décalé
/// @param tLog : taille logique du tableau
/// @return : 0 si pas de problème, et -1 si la taille max du tableau est dépassé
int decalerADroiteF(float tab[],int tailleM,int ind,int *tLog){
    int i;
    if (tailleM==*tLog){
        printf("Problème de taille de tableau : trop petit\n");
        return -1;
    }
    for (i=*tLog;i>ind;i--){
        tab[i]=tab[i-1];
    }
    return 0;
}

/// @brief Affiche le contenu d'un tableau d'entier en format tableau :[,,,]
/// @param tab table à afficher
/// @param Tlog taille logique du tableau
void afficheTabEnt(int tab[],int Tlog){
    int ind;
    printf("[");
    for(ind=0;ind<Tlog-1;ind++)
        printf("%d,",tab[ind]);
    printf("%d]\n",tab[ind]);
}

/// @brief Affiche le contenu d'un tableau de float en format tableau :[,,,]
/// @param tab table à afficher
/// @param Tlog taille logique du tableau
void afficheTabFlo(float tab[],int Tlog){
    int ind;
    printf("[");
    for (ind=0;ind<Tlog-1;ind++){
        printf("%.2f,",tab[ind]);
    }
    printf("%.2f]\n",tab[ind]);
}
/// @brief  Fonction d'affichage des infos d'un stage donné en argument
/// @param Tab_Ref : Tableau contenant les références des stages
/// @param Tab_Dep : Tableau contenant les Départements des stages
/// @param Tab_EtuAcc : Tableau contenant si un stage a accépté un étudiant
/// @param Tab_Etu : Table contenant les étudiants
/// @param Tab_RSta : Table contenant les références de stage pour les etudiants
/// @param Tlog : taille logique du tableau
void afficherStagesPourvus(int Tab_Ref[], int Tab_Dep[], int Tab_EtuAcc[], int Tab_Etu[],int Tab_RSta[], int Tlog) {
    int indnumE;
    printf("Stages pourvus avec étudiants affectés :\n");
    for (int i = 0; i < Tlog; i++) {
        if (Tab_EtuAcc[i] == 1) {  
            indnumE=rechercheStag(Tab_RSta,Tlog,Tab_Ref[i]);
            printf("Stage %d (Département %d) - Étudiant affecté : %d\n", Tab_Ref[i], Tab_Dep[i], Tab_Etu[indnumE]);
        }
    }
}

/// @brief  Fonction d'affichage des stages non pourvus d'étudiants
/// @param Tab_Ref : Tableau contenant les références des stages
/// @param Tab_Dep : Tableau contenant les Départements des stages
/// @param Tab_EtuAcc : Tableau contenant si un stage a accépté un étudiant
/// @param Tlog : taille logique du tableau
void afficherStagesNonPourvus(int Tab_Ref[], int Tab_Dep[], int Tab_EtuAcc[], int Tlog) {
    printf("Stages non pourvus :\n");
    for (int i = 0; i < Tlog; i++) {
        if (Tab_EtuAcc[i] == 0) {
            printf("Stage %d (Département %d) - Non pourvu\n", Tab_Ref[i], Tab_Dep[i]);
        }
    }
}

/// @brief Fonction d'affichage des etudiants sans stage
/// @param Tab_Etu : Table contenant les étudiants
/// @param Tab_RSta : Table contenant les références de stage pour les etudiants
/// @param Tlog : taille logique du tableau
void afficherEtudiantsSansStage(int Tab_Etu[], int Tab_RSta[], int Tlog) {
    printf("Etudiants sans stages :\n");
    for (int i = 0; i < Tlog; i++) {
        if (Tab_RSta[i] == -1) {
            printf("Étudiant %d - Pas de stage affecté\n", Tab_Etu[i]);
        }
    }
}

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
void afficherInfoStage(int Tab_Ref[], int Tab_Dep[], int Tab_EtuAcc[], int Tab_NCand[], int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[],int Tlog, int ref) {
    int trouve = 0;
    for (int i = 0; i < Tlog; i++) {
        if (Tab_Ref[i] == ref) {
            printf("-------------------------------------------\n");
            printf("Informations du stage %d :\n", ref);
            printf("Département : %d\n", Tab_Dep[i]);
            printf("Pourvu : %s\n", Tab_EtuAcc[i] == 1 ? "Oui" : "Non");
            if (Tab_NCand[i]>0){
                printf("Nombre de candidatures : %d\n", Tab_NCand[i]);
                printf("Candidat 1 : %d",Tab_Cand1[i]);
                if (Tab_NCand[i]>1){
                    printf(",\tCandidat 2 : %d",Tab_Cand2[i]);
                    if (Tab_NCand[i]>2){
                        printf(",\tCandidat 3 : %d",Tab_Cand3[i]);
                    }
                }
            printf("\n");
            }
            trouve = 1;
            printf("-------------------------------------------\n");
            break;
        }
    }
    if (trouve==0) {
        printf("Stage %d introuvable.\n", ref);
    }
}
/// @brief Affiche les stages en fonction d'un critère donné (numéro de stage ou département)
/// @param Tab_Ref : Tableau des références de stages
/// @param Tab_Dep : Tableau des départements des stages
/// @param Tlog : Taille logique des tableaux
/// @param critere : Critère de recherche : numéro de stage ou département
/// @param valeur : Valeur à rechercher pour le critère
void afficherStagesParCritere(int Tab_Ref[], int Tab_Dep[], int Tlog, char critere, int valeur){
    int passe=0;
    int i;
    if (critere == 'n') 
        printf("Recherche des stages par numéro = %d :\n", valeur);
    if (critere == 'd')
        printf("Recherche des stages par département = %d :\n", valeur);
    for (i = 0; i < Tlog; i++) {
        if ((critere == 'n' && Tab_Ref[i] == valeur) || (critere == 'd' && Tab_Dep[i] == valeur)) {
            printf("Stage %d (Département %d)\n", Tab_Ref[i], Tab_Dep[i]);
            passe=passe+1;
        }
    }
    if (passe==0)
        printf("Aucun stage trouvé avec ces critères \n");
}
//Non vérifiée
void affichageToutStageAvecCandidature(int Tab_Ref[], int Tab_EtuAcc[], int Tlog, int Tab_Cand1[], int Tab_Cand2[], int Tab_Cand3[], int Tab_NCand[])
{
    int i,passe=0,k=0;
    printf("Stage avec candidature : \n");
    for(i=0;i<Tlog;i++)
        {
            if(Tab_EtuAcc[i]==0){
                if(Tab_NCand[i]>0){
                    printf("Stage num %d,cand 1 : %d",Tab_Ref[i],Tab_Cand1[i]);
                    if(Tab_NCand[i]>1){
                        printf("\t,cand 2 : %d",Tab_Cand2[i]);
                        if(Tab_NCand[i]>2)
                            printf("\t,cand 3 : %d ",Tab_Cand3[i]);   
                    }
                passe=passe+1;
                printf("\n");
                }
            }
        }
    if (passe>0)
        printf("Aucun stage avec des candidatures\n");

}

/// @brief Affiche tous les stages auxquels un étudiant donné a candidaté.
/// @param Tab_RefCand : Tableau des références des stages pour chaque candidature.
/// @param TlogCand : Taille logique du tableau de candidatures.
/// @param Tab_NCand : Tableau contenant les Départements des stages
/// @param Tab_Cand1 : Contient le premier numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand2 : Contient le deuxième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand3 : Contient le troisième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Netu : Numéro de l'étudiant à rechercher.
void afficherCandidaturesEtudiant( int Tab_RefCand[], int TlogCand,int Tab_NCan[],int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[], int Netu) { // C'est pour l'affichage de toutes ses candidatures (pour l'élève)
    printf("Candidatures de l'étudiant %d :\n", Netu);
    int trouve = 0;
    int i;
    for (i = 0; i < TlogCand; i++) {
        if (Tab_NCan[i]>0){
            if (Tab_Cand1[i] == Netu) { 
                printf("Stage %d\n", Tab_RefCand[i]);
                trouve = 1;
            }
        }
        if (Tab_NCan[i]>1){
            if (Tab_Cand2[i] == Netu) {
                printf("Stage %d\n", Tab_RefCand[i]);
                trouve = 1;
            }
        }
        if (Tab_NCan[i]>2){
            if (Tab_Cand3[i] == Netu) {
                printf("Stage %d\n", Tab_RefCand[i]);
                trouve = 1;
            }
        }
    }
    if (trouve==0) {
        printf("Aucune candidature trouvée pour l'étudiant %d.\n", Netu);
    }
}


//Non vérifiée
/// @brief Affiche le stage affecté à un étudiant donné, s'il y a lieu.
/// @param Tab_Etu : Tableau des étudiants.
/// @param Tab_RSta : Tableau des stages affectés à chaque étudiant.
/// @param Tlog : Taille logique des tableaux.
/// @param Netu : Numéro de l'étudiant à rechercher.
void afficherStageAffecte(int Tab_Etu[], int Tab_RSta[], int Tlog, int Netu) {  // fonction pour l'affichage du stage qui est affecté à l'élève
    for (int i = 0; i < Tlog; i++) {
        if (Tab_Etu[i] == Netu) {
            if (Tab_RSta[i] != -1) {
                printf("Étudiant %d est affecté au stage %d\n", Netu, Tab_RSta[i]);
            } else {
                printf("Étudiant %d n'a pas de stage affecté.\n", Netu);
            }
            return;
        }
    }
    printf("Étudiant %d introuvable.\n", Netu);
}
//Non vérifiée
/// @brief Affiche tous les stages d'un département donné.
/// @param Tab_Ref : Tableau contenant les références des stages
/// @param Tab_Dep : Tableau des départements associés à chaque stage.
/// @param Tlog : Taille logique des tableaux.
/// @param dept : Numéro du département à rechercher.
void afficherStagesParDepartement(int Tab_Ref[], int Tab_Dep[], int Tlog, int dept) {
    printf("Stages disponibles dans le département %d :\n", dept);
    int trouve = 0;
    for (int i = 0; i < Tlog; i++) {
        if (Tab_Dep[i] == dept) {
            printf("Stage %d\n", Tab_Ref[i]);
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucun stage trouvé dans le département %d.\n", dept);
    }
}


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
void accepteEtu(int Tab_Etu[],int Tab_Rsta[],int Tab_Ref[],int Tab_EtuAcc[],int Tab_NCand[],int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[],int TlogEtu,int TlogSta,int refStage, int num_Etu){
    int ind,trouve;
    ind=rechercheStag(Tab_Ref,TlogSta,refStage);
    Tab_EtuAcc[ind]=1;
    Tab_NCand[ind]=0;
    for(ind=0;ind<TlogSta;ind++){
        if(Tab_NCand[ind]>0){
            if(Tab_Cand1[ind]==num_Etu){
                SupprimeCandidature(Tab_Ref,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,TlogSta,num_Etu,ind);
            }
        }
        if(Tab_NCand[ind]>1){
            if(Tab_Cand2[ind]==num_Etu){
                SupprimeCandidature(Tab_Ref,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,TlogSta,num_Etu,ind);
            }
        }
        if(Tab_NCand[ind]>2){
            if(Tab_Cand3[ind]==num_Etu){
                SupprimeCandidature(Tab_Ref,Tab_NCand,Tab_Cand1,Tab_Cand2,Tab_Cand3,TlogSta,num_Etu,ind);
            }
        }
    }
    ind=recherche(Tab_Etu,TlogEtu,num_Etu,&trouve);
    Tab_Rsta[ind]=refStage;
}


/// @brief Fonction qui supprime un candidat
/// @param Tab_Ref : Tableau contenant les références des stages
/// @param Tab_NCand : Tableau contenant le nombre de candidats aux stage 
/// @param Tab_Cand1 : Contient le premier numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand2 : Contient le deuxième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand3 : Contient le troisième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tlog : Taille logique des tableaux
/// @param etu : numéro de l'étudiant à supprimer
/// @param ind : l'indice du stage où l'étudiant est supprimé
void SupprimeCandidature(int Tab_Ref[],int Tab_NCand[],int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[],int Tlog,int etu,int ind){
    int i;
    if (Tab_Cand1[ind]==etu){
        if(Tab_NCand[ind]>1)
            Tab_Cand1[ind]=Tab_Cand2[ind];
        if(Tab_NCand[ind]>2)
            Tab_Cand2[ind]=Tab_Cand3[ind];
    }
    if (Tab_Cand2[ind]==etu){
        if(Tab_NCand[ind]>2)
            Tab_Cand2[ind]=Tab_Cand3[ind];
    }
    Tab_NCand[ind]=Tab_NCand[ind]-1;
}

/// @brief Fonction pour ajouter une note à un étudiant
/// @param Tab_Etu : Tableau contenant les numéros etudiants
/// @param Tab_RSta : Tableau contenant les références des stages attribué aux étudiants
/// @param Tab_Note : Tableau contenant les notes des etudiants
/// @param Tlog : Taille logique des tableau
/// @return : -1 si le programme a été arrété, 0 s'il a fontionné
int ajoutNote(int Tab_Etu[],int Tab_RSta[],float Tab_Note[],int Tlog){
    int i=0,numEtu,ind,trouve,verif=0;
    float noteE,noteR,noteS,noteG;
    printf("A quel numéro d'étudiant voulez vous ajouter une note ? (-1 pour quitter) : ");
    scanf("%d",&numEtu);
    ind=recherche(Tab_Etu,Tlog,numEtu,&trouve);
    if(Tab_RSta[ind]==-1){
        printf("Cet etudiant n'a pas de stage associé, il ne peut pas recevoir de note..\n");
        return -1;
    }
    while(trouve==0){
        if(numEtu==-1) 
            return -1;
        printf("L'étudiant n'existe pas ! (-1 pour quitter) Veuillez réessayer : ");
        scanf("%d",&numEtu);
        ind=recherche(Tab_Etu,Tlog,numEtu,&trouve);
    }
    while(verif!=1){
        if(verif==-1)
            return -1;
        printf("Quelle est la note de l'entreprise ? : ");
        scanf("%f",&noteE);
        while (noteE>20||noteE<0){
            printf("La note saisie n'est pas correcte, veuillez la ressaisir : ");
            scanf("%f",&noteE);
        }
        printf("Quelle est la note du rapport ? : ");
        scanf("%f",&noteR);
        while (noteR>20||noteR<0){
            printf("La note saisie n'est pas correcte, veuillez la ressaisir : ");
            scanf("%f",&noteR);
        }
        printf("Quelle est la note soutenance ? : ");
        scanf("%f",&noteS);
        while (noteS>20||noteS<0){
            printf("La note saisie n'est pas correcte, veuillez la ressaisir : ");
            scanf("%f",&noteS);
        }
        noteG=(noteE*2+noteR+noteS)/4;
        printf("\n");
        printf("Notes: entreprise:%.2f rapport:%.2f soutenance:%.2f Globale:%.2f\n",noteE,noteR,noteS,noteG);
        printf("\n");
        printf("Êtes vous sûr de vouloir ajouter la note globale de %.2f à l'élève numéro %d (1 pour oui,-1 pour quitter,autre nombre pour retaper les notes) : ",noteG,numEtu);
        scanf("%d",&verif);
    }
    Tab_Note[ind]=noteG;
    return 0;
}

/// @brief Fonction pour ajouter une offre
/// @param Tab_Ref : Tableau contenant les références des stages
/// @param Tab_Dep : Tableau contenant les départements des stages
/// @param Tab_EtuAcc : Tableau contenant si un stage a accépté un étudiant: 
/// @param Tab_NCand : Tableau contenant le nombre de candidats aux stage 
/// @param Tlog : Taille logique des tableau
/// @return : -1 si le programme a été arrété, 0 s'il a fontionné
int ajoutOffre(int Tab_Ref[],int Tab_Dep[],int Tab_EtuAcc[],int Tab_NCand[],int *Tlog,int Tmax){
    int i=0,ref,ind,dep,verif=-1;
    if(*Tlog==Tmax){
        printf("PB: tableau trop petit pour insérer un nouveau stage");
        return -1;
    }
    printf("Quel est la référence du stage que vous voulez ajouter ? (-1 pour quitter) : ");
    scanf("%d",&ref);
    ind=rechercheStag(Tab_Ref,*Tlog,ref);
    while(ind>-1){ //test si la ref du stage est déjà dans le tableau ou non
        if(ref==-1) 
            return -1;
        printf("Ce stage est déjà présent, veuillez rentrer la référence d'un nouveau stage (-1 pour quitter) : ");
        scanf("%d",&ref);
        ind=rechercheStag(Tab_Ref,*Tlog,ref);
    }
    printf("Quel est le département de ce stage  %d ? : ",ref);
    scanf("%d",&dep);
    printf("Etes vous sûr de vouloir rajouter le stage %d avec le département %d ? \n(-1 pour non, 0ind pour quitter, autre nombre pour oui) : ",ref,dep);
    scanf("%d",&verif);
    while (verif==-1){
        if (verif==0){
            return -1;
        }
        printf("Redonnez le département du stage %d ? : ",ref);
        scanf("%d",&dep);
        printf("Etes vous sûr de vouloir rajouter le stage %d avec le département %d ? \n(-1 pour non, 0 pour quitter, autre nombre pour oui)",ref,dep);
        scanf("%d",&verif);
    }
    Tab_Ref[*Tlog]=ref;
    Tab_Dep[*Tlog]=dep;
    Tab_EtuAcc[*Tlog]=0;
    Tab_NCand[*Tlog]=0;
    *Tlog=*Tlog+1;
    return 0;
}



/// @brief Ajout d'une candidature a un stage si les conditions sont remplis.
/// @param Tab_Etu : Tableau contenant les numéros etudiants
/// @param Tab_Cand1 : Contient le premier numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe).
/// @param Tab_Cand2  : Contient le deuxieme numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe).
/// @param Tab_Cand3 : Contient le troisieme numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe).
/// @param TlogEtu Taille logique des ableaux associès aux etudiants
/// @param TlogCan Taille logique des tableaux associès aux stages
/// @param Tab_NCand : Tableau contenant le nombre de candidature pour un stage.
/// @param Tab_Ref : Tableau contenant la référence pour chaque stage.
/// @param Netu : Numéro de l'étudiant
/// @return : -1 si le programme a été arrété, 0 s'il a fontionné.
int ajoutCand(int Tab_Etu[], int Tab_Cand1[], int Tab_Cand2[], int Tab_Cand3[], int TlogEtu, int TlogCan, int Tab_NCand[],int Tab_Ref[],int Netu){
    int i,nbCand=0,ref,ind;
    char conf;
    for (i = 0; i < TlogCan; i++) {
        if (Tab_NCand[i]>0)
            if (Tab_Cand1[i] == Netu)
                nbCand=nbCand+1;
        if (Tab_NCand[i]>1)
            if (Tab_Cand2[i] == Netu)
                nbCand=nbCand+1;
        if (Tab_NCand[i]>2)
                nbCand=nbCand+1;
    }
    printf("Ajout d'une nouvelle candidature\nVous avez %d candidatures.\n",nbCand);
    if(nbCand==3){
        printf("Vous ne pouvez donc pas candidater à un nouveau stage, retour au menu :\n");
        return -1;
    }

    printf("Quel est la référence du stage auquel vous voulez candidater ? :");
    scanf("%d",&ref);
    ind=rechercheStag(Tab_Ref,TlogCan,ref);
    while(ind==-1){
        printf("Ce stage n'existe pas, veuillez en donner un autre : ");
        scanf("%d",&ref);
        ind=rechercheStag(Tab_Ref,TlogCan,ref);
    }
    printf("Ce stage a %d candidatures\n",Tab_NCand[ind]);
    if(Tab_NCand[ind]==3){
        printf("Ce stage est complet, impossible d'y ajouter une candidature\n");
        return -1;
    }
    printf("Etes vous sûr de vouloir vous inscrire au stage n°%d ? (O/N): ",ref);
    scanf("%*c%c",&conf);
    if (conf=='N'){
        printf("Annulation de la candidature, Retour au Menu :\n");
        return -1;
    }
    Tab_NCand[ind]=Tab_NCand[ind]+1;
    if(Tab_NCand[ind]==1)
        Tab_Cand1[ind]=Netu;
    if(Tab_NCand[ind]==2)
        Tab_Cand2[ind]=Netu;
    if(Tab_NCand[ind]==3)
        Tab_Cand3[ind]=Netu;
    printf("Candidature effectué pour le stage n°%d! Il a désormais %d candidatures.\n",ref,Tab_NCand[ind]);
}
    

/// @brief Fonction de sauvegarde des tables Tab_Etu/Rsta/Note dans le fichier Etudiant.don
/// @param Tab_Etu : Table contenant les Numéros des étudiants
/// @param Tab_RSta : Table contenant les Références du stage où les étudiants ont été acceptés 
/// @param Tab_Note : Table contenant les Notes des etudiants reçue durant leur stage
/// @param Tlog : Taille logique de ces tableaux
/// @param fich : le fichier où l'on va sauvegarder les tableaux
void sauvegardeEtu(int Tab_Etu[], int Tab_RSta[],float Tab_Note[],int Tlog,FILE *fich){
    int i=0;
    for(i=0;i<Tlog;i++){
        fprintf(fich,"%d    %.2f    %d\n",Tab_Etu[i],Tab_Note[i],Tab_RSta[i]);
    }
}

/// @brief Fonction de sauvegarde des tables Tab_Ref/Dep/EtuAcc/NCand/Cand1/Cand2/Cand3 dans le fichier Stage.don
/// @param Tab_Ref Tableau contenant les Références des stages
/// @param Tab_Dep Tableau contenant les Départements des stages
/// @param Tab_EtuAcc Tableau contenant si un stage a accépté un étudiant
/// @param Tab_NCand Tableau contenant le nombre de candidature d'étudiants
/// @param Tlog Taille logique de ces tableaux
/// @param Tab_Cand1 Contient le premier numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand2 Contient le deuxième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand3 Contient le troisième numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param fich : le fichier où l'on va sauvegarder les tableaux
void sauvegardeOffre(int Tab_Ref[], int Tab_Dep[],int Tab_EtuAcc[],int Tab_NCand[],int Tlog,int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[],FILE *fich){
    int i=0;
    for(i=0;i<Tlog;i++){
        fprintf(fich,"%d    %d\n",Tab_Ref[i],Tab_Dep[i]);
        fprintf(fich,"%d\n",Tab_EtuAcc[i]);
        if(Tab_EtuAcc[i]==0){
            fprintf(fich,"%d\n",Tab_NCand[i]);
            if (Tab_NCand[i]>0)
                fprintf(fich,"%d\n",Tab_Cand1[i]);
            if (Tab_NCand[i]>1)
                fprintf(fich,"%d\n",Tab_Cand2[i]);
            if (Tab_NCand[i]>2)
                fprintf(fich,"%d\n",Tab_Cand3[i]);
        }
        
    }
}
/// @brief Lit le fichier .mdpRespo pour avoir le mdp
/// @return le mdp décrypté
int OuvrmdpRespo(void){
    int motdp;
    FILE *MDP;
    MDP=fopen(".mdpRespo","r");
    if (MDP==NULL){
      printf("PB d'ouverture du fichier mdpRespo");
      return -1;
    }
    fscanf(MDP,"%d",&motdp);
    fclose(MDP);
    motdp=motdp/3;
    return motdp;
}

/// @brief Met le mot de passe du respo dans le fichier .mdpRespo et le crypte
/// @param motdp : mdp à changer
void SauvmdpRespo(int motdp){
    FILE *MDP;
    MDP=fopen(".mdpRespo","w");
    motdp=motdp*3;
    fprintf(MDP,"%d\n",motdp);
    fclose(MDP);
}

/// @brief Fonction de changement du mdp respo 
void changerMDP(void){
    int Amdp,Nmdp,verif;
    Amdp=OuvrmdpRespo();
    while(verif!=0){
        printf("Votre ancien mdp est : %d, quel est le nouveau mdp que vous voulez mettre ? : ",Amdp);
        scanf("%d",&Nmdp);
        printf("Etes vous sûr de vouloir passer du mdp : %d à celui-ci : %d ? (O pour oui, autre nombre pour non) : ",Amdp,Nmdp);
        scanf("%d",&verif);
    }
    SauvmdpRespo(Nmdp);
}
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
/// @return -1 si ça ne fonctionne pas 0 si c'est bon et 9 pour quitter l'application
int menuChoix(int Tab_Ref[], int Tab_EtuAcc[], int TlogEtu, int TlogCan, int Tab_Cand1[], int Tab_Cand2[], int Tab_Cand3[], int Tab_NCand[],int Tab_Dep[],int Tab_Etu[],int Tab_RSta[], float Tab_Note[],int tailleM)
{
  char id;
  int quit=1, Netu,mdp,motdp2,ind,trouve;
  mdp=OuvrmdpRespo();
  printf("##---------------------##\n");
  printf("Bienvenue sur votre système de gestion de stage, Êtes vous un Etudiant ou un Responsable de stages ? : E/R ou Q pour quitter l'appli : ");
  scanf("%c",&id);
  while(id!='R' && id!='E' && id!='Q')
  {
    printf("\n Erreur dans votre choix, veuillez recommencer\n");
    printf("##---------------------##\n");
    printf("Bienvenue sur votre système de gestion de stage, Êtes vous un Etudiant ou un Responsable de stages ? : E/R ou Q pour quitter l'appli : ");
    scanf("%*c%c",&id);
  }
  if(id=='Q'){
    printf("Vous quittez l'application, enregistrement des informations ... Aurevoir\n");
    printf("##---------------------##\n");
    return 9;
  }
  if(id=='E'){
    printf("Quel est votre numero d'étudiant ? : ");
    scanf("%d",&Netu);
    ind=recherche(Tab_Etu,TlogEtu,Netu,&trouve);
    if(trouve!=1){
        printf("Etes vous un nouvel etudiant ? (1 pour oui, 0 pour non): ");
        scanf("%d",&trouve);
        if (trouve==1)
            inserer_etu(Tab_Etu,Tab_RSta,Tab_Note,Netu,&TlogEtu,tailleM);
        else{ 
            printf("Vous avez alors du vous tromper de numéro d'étudiant,Retour au menu principal ! \n");
            return 0;
        }
    }
  }
  if(id=='R'){
    printf("Quel est votre mdp ? (code PIN) : ");
    scanf("%d",&motdp2);
    while(motdp2!=mdp){
        printf("Votre mdp n'est pas bon, veuillez réessayer : ");
        scanf("%d",&motdp2);
    }
  }
  while (quit!=0){
    if(id=='E'){
        printf("##---------------------##\n");
        menuEtudiant( Tab_Ref,  Tab_Dep, Tab_EtuAcc, TlogEtu, TlogCan, Netu, Tab_Etu, Tab_Cand1,Tab_Cand2,Tab_Cand3,Tab_NCand,&quit);
    }
    if(id=='R'){
        printf("##---------------------##\n");
        menuResponsable(Tab_Ref, Tab_EtuAcc, TlogEtu, TlogCan, Tab_Cand1, Tab_Cand2, Tab_Cand3, Tab_NCand,Tab_Dep, Tab_Etu,Tab_RSta,Tab_Note,tailleM,Netu,&quit);
    }
  }
  return 0;
}

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
/// @param tailleM Taille maximal des tableaux.
/// @param Netu Numéro etudiant.
/// @param quit variable pour savoir si on veux quitter le menu
void menuResponsable(int Tab_Ref[], int Tab_EtuAcc[], int TlogEtu, int TlogCan, int Tab_Cand1[], int Tab_Cand2[], int Tab_Cand3[], int Tab_NCand[],int Tab_Dep[],int Tab_Etu[],int Tab_RSta[], float Tab_Note[],int tailleM,int Netu,int *quit)
{
  int choix;
  int ref, valeur;
  char critere;
  printf(" 1/ Affichage des stages avec candidature \n 2/ Affichage des stages sans candidature \n 3/ Liste des étudiants sans stages \n 4/ Informations sur un stage \n 5/ Recherche de stages selon un critère \n 6/ Affectation d'un stage à un étudiant \n 7/ Ajout note de stage \n 8/ Affectation d'un étudiant à un stage \n 9/ Changer MDP  \n 10/ Quitter \n Votre Réponse : ");
  scanf("%d",&choix);
  while (choix>9)
  {
    printf("Erreur, veuillez recommencer.\n");
    printf(" 1/ Affichage des stages avec candidature \n 2/ Affichage des stages sans candidature \n 3/ Liste des étudiants sans stages \n 4/ Informations sur un stage \n 5/ Recherche de stages selon un critère \n 6/ Affectation d'un stage à un étudiant \n 7/ Ajout note de stage \n 8/ Affectation d'un étudiant à un stage \n 9/ Changer MDP  \n 10/ Quitter \n Votre Réponse : ");
    scanf("%d",&choix);
  }
  printf("##---------------------##\n");
  if(choix==1)
    affichageToutStageAvecCandidature(Tab_Ref,Tab_EtuAcc, TlogCan, Tab_Cand1, Tab_Cand2, Tab_Cand3,Tab_NCand);
  if(choix==2)
    afficherStagesNonPourvus(Tab_Ref,Tab_Dep,Tab_EtuAcc,TlogCan);
  if(choix==3)
    afficherEtudiantsSansStage(Tab_Etu,Tab_RSta,TlogEtu);
  if(choix==4){
    printf("Donné la reference du stage pour différentes informations: ");
    scanf("%d",&ref);
    afficherInfoStage(Tab_Ref, Tab_Dep,Tab_EtuAcc,Tab_NCand,Tab_Cand1,Tab_Cand2, Tab_Cand3, TlogCan,ref);
  }
  if(choix==5){
    printf("Voulez vous chercher un stage par numéro ou departement ? : n/d");
    scanf("%*c%c",&critere);
    if(critere=='n')
    {
        printf("Donner la ref du stage que vous voulez chercher : ");
        scanf("%d",&valeur);
    }
    if(critere == 'd')
    {
        printf("Donner le departement du stage que vous voulez rechercher : ");
        scanf("%d",&valeur);
    }
    afficherStagesParCritere(Tab_Ref, Tab_Dep, TlogCan,critere, valeur);
  }
  if(choix==6)
    ajoutNote(Tab_Etu,Tab_RSta,Tab_Note,TlogEtu);
  if(choix==7)
    accepteEtu(Tab_Etu,Tab_RSta, Tab_Ref, Tab_EtuAcc,Tab_NCand, Tab_Cand1, Tab_Cand2, Tab_Cand3, TlogEtu, TlogCan,ref, Netu);
  if(choix==8)
    changerMDP();
  if(choix==9)
    *quit=0;
}




/// @brief Menu etudiant qui lui affiche les différentes action réalisable.
/// @param Tab_Ref Tableau contenant les Références des stages
/// @param Tab_Dep Tableau contenant le departement des stages
/// @param Tab_EtuAcc Tableau contenant si un stage a accépté un étudiant
/// @param TlogEtu Taille logique des ableaux associès aux etudiants
/// @param TlogCan Taille logique des tableaux associès aux stages
/// @param Netu Numéro etudiant
/// @param Tab_Etu Table contenant les Numéros des étudiants
/// @param Tab_Cand1 Contient le premier numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand2 Contient le deuxieme numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_Cand3 Contient le troisieme numéro etudiant de la liste des étudiants ayant fais une demande pour la fomation (s'il existe)
/// @param Tab_NCand Tableau contenant le nombre de candidature d'étudiants
/// @param quit variable pour savoir si on veux quitter le menu
void menuEtudiant(int Tab_Ref[], int Tab_Dep[], int Tab_EtuAcc[], int TlogEtu, int TlogCan,int Netu, int Tab_Etu[],int Tab_Cand1[],int Tab_Cand2[],int Tab_Cand3[],int Tab_NCand[],int *quit)
{
  int choix;
  printf(" 1/ Affichage de la liste des stages disponibles \n 2/ Affichage des candidatures \n 3/ Ajouter une candidature \n 9/ Quitter\nVotre Réponse : ");
  scanf("%d",&choix);
  while(choix >3 && choix <9)
  {
    printf("Erreur, veuillez recommencer.\n");
    printf(" 1/ Affichage de la liste des stages disponibles \n 2/ Affichage des candidatures \n 3/ Ajouter une candidature \n 9/ Quitter\nVotre Réponse : ");
    scanf("%d",&choix);
  }
  if(choix==1)
    afficherStagesNonPourvus(Tab_Ref,Tab_Dep,Tab_EtuAcc,TlogCan);
  if(choix==2)
    afficherCandidaturesEtudiant(Tab_Ref,TlogCan,Tab_NCand,Tab_Cand1, Tab_Cand2,Tab_Cand3,Netu);
  if(choix==3)
    ajoutCand(Tab_Etu,Tab_Cand1,Tab_Cand2,Tab_Cand3,TlogEtu,TlogCan,Tab_NCand,Tab_Ref,Netu);
  if(choix==9)
    *quit=0;
}


/// @brief Fonction principale pour charger et sauvegarder les données des étudiants et des stages.
void global(void) {
    int Tab_Ref[300], Tab_Dep[300], Tab_EtuAcc[300], Tab_Ncand[300], Tab_Cand1[300], Tab_Cand2[300], Tab_Cand3[300], Tmax=300, TlogEtu, TlogSta,  Tab_Etu[300],Tab_RSta[300], NEtu, val, ref,valeur, dept;
    float Tab_Note[300];
    char critere;
    FILE *flot;
    flot=fopen("Etudiant.don","r");
    TlogEtu=chargementEtu(Tab_Etu,Tab_RSta,Tab_Note,Tmax, flot); //respon , eleve,quittermenu etu//
    flot=fopen("Stage.don","r");
    TlogSta=chargementOffre(Tab_Ref, Tab_Dep, Tab_EtuAcc, Tab_Ncand, Tmax, Tab_Cand1, Tab_Cand2, Tab_Cand3, flot);
    //menuChoix(Tab_Ref, Tab_EtuAcc, TlogEtu, Netu,  Tab_Cand1,  Tab_Cand2,  Tab_Cand3, Tab_Ncand, Tab_Dep, Tab_Etu, Tab_RSta,Tab_Note);
    sauvegardeOffre(Tab_Ref, Tab_Dep,Tab_EtuAcc,Tab_Ncand,TlogSta,Tab_Cand1,Tab_Cand2,Tab_Cand3,flot);
    flot=fopen("Etudiant.don","r");
    sauvegardeEtu(Tab_Etu,Tab_RSta, Tab_Note, TlogEtu,flot);
}

