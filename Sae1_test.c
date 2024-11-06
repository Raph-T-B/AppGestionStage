#include"Sae1.h"

void testChargementEtu(void) {
    int Tab_Etu={101,124,236,520};
    int Tab_RSta={-1,2001,-1,5623};
    float Tab_Note={-1.0,-1.0,-1.0,-1.0};
    int Tmax=20;
    chargementEtu(Tab_Etu, Tab_RSta, Tab_Note, Tmax);
}


int main(void){
    return 0;
}