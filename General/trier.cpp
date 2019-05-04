#include <fstream> 
#include <iostream>
#include "../Classe/Sommet.h"
#include "../Classe/Arrete.h"
#include "../Classe/graph.h"

//on trie les arête par ordre de poids croissant
int Graph::trier(int choix)
{
 if (choix==1)
 {
  for(int i=0;i<nbArrete;i++)
  {
    for(int j=0;j<nbArrete;j++)
    {
      if (tabArrete[i]->getm_pd1()<tabArrete[j]->getm_pd1())
      {
        Arrete *temp; 
      temp=tabArrete[i];

      tabArrete[i]=tabArrete[j];
      tabArrete[j]=temp;
      }
    }
  }
 }
//std::vector <Arrete*> triePD1;
//triePD1=tabArrete;//triepD1 est un tableau tempon


if (choix==2)
 {
  for(int i=0;i<nbArrete;i++)
  {
    for(int j=0;j<nbArrete;j++)
    {
      if (tabArrete[i]->getm_pd2()<tabArrete[j]->getm_pd2())
      {
        Arrete *temp; 
      temp=tabArrete[i];

      tabArrete[i]=tabArrete[j];
      tabArrete[j]=temp;
      }
    }
  }
 } 
 return 1;
}
