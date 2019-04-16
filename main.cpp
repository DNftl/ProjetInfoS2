#include <iostream>
#include "graphe.h"

int main()
{
    int x;
    graphe g{"fichierExemple1.txt"};
    graphe a{"fichierExemple2.txt",x};
    g.afficherT1();
    g.afficherT2();
    return 0;
}

//test commit
