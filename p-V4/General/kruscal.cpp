#include "../Classe/graph.h"
#include <fstream>
#include <iostream>

void Graph::kruskal(Svgfile *ecran,Graph *A)
{
    int choix,total1=0,total2=0;
    int S1=0;
    int S2=0;
    for (int i=0; i<nbArrete; i++)
    {
        tabArrete[i]->resetm_marquage();
    }
    for (int i=0; i<nbSommet; i++)
    {
        tabSommet[i]->resetm_marquage();
    }


    do
    {
        choix=0;
        std::cout<<"En fonction de quel poid souhaitez-vous faire tourner kruskal? tapez 1 ou 2?"<<std::endl;
        std::cin>>choix;
    }
    while(choix!=1 && choix!=2);

    if (A->trier(choix)==1)
        std::cout<<"les aretes ont ete tries, voici le nouvel ordre: "<<std::endl;
    A->affichage();

    S1=(tabArrete[0]->getm_S1());
    S2=(tabArrete[0]->getm_S2());
    tabSommet[S1]->setm_marquage();
    tabSommet[S2]->setm_marquage();
    total1+=tabArrete[0]->getm_pd1();
    total2+=tabArrete[0]->getm_pd2();


    for (int i=1; i<nbArrete; i++)
    {
        S1=(tabArrete[i]->getm_S1());
        S2=(tabArrete[i]->getm_S2());


        if (tabSommet[S1]->getm_marquage()==1 && tabSommet[S2]->getm_marquage()==1)
        {
           tabArrete[i]->setm_marquage(); //arete non selectionner
        }

        else
        {
            if (tabSommet[S1]->getm_marquage()==0)
                tabSommet[S1]->setm_marquage();


            if(tabSommet[S2]->getm_marquage()==0)
                tabSommet[S2]->setm_marquage();

        }
        if (tabArrete[i]->getm_marquage()==1)
        {
          total1+=tabArrete[i]->getm_pd1();
            total2+=tabArrete[i]->getm_pd2();
        }

    }
    A->dessiner(ecran,1,0);

    std::cout<<std::endl;
    std::cout<<"On fait tourner l'algorithme de Kruskal... "<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
        std::cout<<"voici les aretes qui ont ete selectionner: "<<std::endl;

    A->affichage();

    std::cout<<"le cout total est donc: "<<total1<<";"<<total2<<std::endl;

}
