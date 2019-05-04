#ifndef Graph_H_INCLUDED
#define Graph_H_INCLUDED
#include "Sommet.h"
#include "Arrete.h"
#include <fstream>
#include <vector>
#include "../General/svgfile.h"

class Graph
{
  public:
    Graph();
    void affichage();
    void lecture();
    int trier(int choix);
    void dessiner (Svgfile *ecran,int a,int b);
    void kruskal(Svgfile *ecran,Graph *A);
    void pareto(Svgfile *ecran,Graph *A);

  private:
   std::vector<Sommet*> tabSommet;
   std::vector<Arrete*> tabArrete;
   int nbArrete, nbSommet;
};


#endif
