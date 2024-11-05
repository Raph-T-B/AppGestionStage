#include"Sae1.h"

void testafficherStagesPourvus(void)
{
    int Tab_Ref[]= {5008,2001,8000,5623};
    int Tab_Dep[]= {26,56,80,63};
    int Tab_EtuAcc[]= {0,1,0,1};
    int Tab_Etu[]={101,124,236,520};
    int Tlog=4;
    afficherStagesPourvus(Tab_Ref,Tab_Dep,Tab_EtuAcc, Tab_Etu, Tlog);
}

int main(void){
    testafficherStagesPourvus();
    return 0;
}