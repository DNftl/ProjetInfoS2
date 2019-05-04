#include "../Classe/graph.h"
#include <fstream>
#include <iostream>
#include "../Classe/Sommet.h"
#include "../Classe/Arrete.h"

void Graph::affichage()
{
for(int i=0; i<nbSommet;i++)
{
std::cout<<"idS: "<<i<<" x: "<<tabSommet[i]->getm_x();
std::cout<<"   y: "<<tabSommet[i]->getm_y();
std::cout<<"   marquage: "<<tabSommet[i]->getm_marquage()<<std::endl;

}

for(int i=0; i<nbArrete;i++)
{
std::cout<<"idA: "<<i<<"  S1: "<<tabArrete[i]->getm_S1();
std::cout<<"  S2: "<<tabArrete[i]->getm_S2();
std::cout<<"  pd1: "<<tabArrete[i]->getm_pd1();
std::cout<<"  pd2: "<<tabArrete[i]->getm_pd2();
std::cout<<"  marquage: "<<tabArrete[i]->getm_marquage()<<std::endl;

}



}
