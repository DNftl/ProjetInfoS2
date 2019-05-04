#include "../Classe/graph.h"
#include <fstream>
#include <iostream>
#include <math.h>

void Graph::pareto(Svgfile *ecran,Graph *A)
{
    std::vector<bool> tabMarquage;
    std::vector<bool> tabMarquage2;

    std::vector< std::vector<bool> > tabSolution;
    std::vector<int> tabSolution2;

    int possibilite=pow(nbArrete,2);
    int nombre=0, nbAM=0;


//génération du tableau de solution
    std::cout <<std::endl;
    std::cout <<"generation du tableau de solution.. "<<std::endl;

    for(int i=0; i<possibilite; i++)
    {
        nombre=i;
        tabMarquage.clear();
        tabMarquage2.clear();

        for (int j=0; j<nbArrete; j++)
        {
            tabMarquage.push_back(nombre%2);
            nombre=nombre/2;

        }
        tabSolution.push_back(tabMarquage);


    }


//on affiche les solutions

    std::cout <<std::endl;
    std::cout <<"on affiche les solutions:"<<std::endl;

    for(int i=0; i<tabSolution.size(); i++)
    {
        std::cout <<"possibilite "<<i<<std::endl;
        for(int j=0; j<nbArrete; j++)
        {
            std::cout <<tabSolution[i][j];
        }
        std::cout <<std::endl;
    }


// on supprime les solutions quin'incluent pas tous les sommets
    std::cout <<"on supprime les solutions qui n'incluent pas tous les sommets.."<<std::endl;
    std::cout <<"on supprime les solutions qui ne sont pas connexe.."<<std::endl;
    std::cout <<std::endl;

    for(int i=0; i<tabSolution.size(); i++)
    {
        nombre=0,nbAM=1;
        //on définie tous les sommets à la valeur 0
        for(int j=0; j<nbSommet; j++)
        {
            tabSommet[j]->resetm_marquage();
        }

        //on cherche les sommets non ajouté dans la solution i
        for(int j=0; j<nbArrete; j++)
        {
            if(tabSolution[i][j]==1)
            {
                int S1=tabArrete[j]->getm_S1();
                int S2=tabArrete[j]->getm_S2();
                tabSommet[S1]->setm_marquage();
                tabSommet[S2]->setm_marquage();
                nbAM+=1;
            }
        }
        for (int q=0; q<nbSommet; q++)
        {
            nombre+=tabSommet[q]->getm_marquage();
        }

        std::cout<<"nombre de sommets du graph lambda: "<<nombre<<"nombre de sommet total: "<<nbSommet<<std::endl;

        if (nombre<nbSommet || nbAM!=nbSommet)
        {
            std::cout<<"on supprime la case :";

            for(int s=0; s<nbArrete; s++)
            {
                std::cout <<tabSolution[i][s];
            }
            std::cout <<std::endl;
            std::cout <<std::endl;

            tabSolution.erase(tabSolution.begin()+i);
            i--;

        }
        else
        {
            std::cout<<"case valide"<<std::endl;

            std::cout <<std::endl;
        }



    }

    //on réaffiche toutes solutions
    std::cout <<std::endl;
    std::cout <<"Solution finales :"<<std::endl;
    std::cout <<std::endl;

    for(int i=0; i<tabSolution.size(); i++)
    {
        std::cout <<"possibilite :"<<i<<std::endl;
        for(int j=0; j<nbArrete; j++)
        {
            std::cout <<tabSolution[i][j];
        }
        std::cout <<std::endl;
    }


// on crée le tableau de solution par poids
    std::cout <<std::endl;
    std::cout <<"on cree le tableau de solution par poids.."<<std::endl;
    std::cout <<"on trie le tableau de solution par poids.."<<std::endl;
    std::cout <<std::endl;
    for(int i=0; i<tabSolution.size(); i++)
    {

        int pd=0;

        for(int q=0; q<nbArrete; q++)
        {
            if(tabSolution[i][q]==1)
            {
                pd+=tabArrete[q]->getm_pd1();
                pd+=tabArrete[q]->getm_pd2();
            }
        }
        tabSolution2.push_back(pd);
    }



    //on trie le tableau de poids
    for(int i=0; i<tabSolution2.size(); i++)
    {

        for(int j=0; j<tabSolution2.size(); j++)
        {
            if (tabSolution2[i]<tabSolution2[j])
            {
               std::vector<bool> temp;
               temp.clear();
               int temp2=0;
                temp=tabSolution[i];
                temp2=tabSolution2[i];

                tabSolution[i]=tabSolution[j];
                tabSolution[j]=temp;
                tabSolution2[i]=tabSolution2[j];
                tabSolution2[j]=temp2;

            }
        }
    }

int pd1=0,pd2=0;
    std::cout <<"on trouve le Front de Pareto:"<<std::endl;
    std::cout <<std::endl;
    for(int i=0; i<tabSolution.size(); i++)
    {
        std::cout <<"solution "<<i<<std::endl;
        for(int j=0; j<nbArrete; j++)
        {
            std::cout <<tabSolution[i][j];
        }
            std::cout<<std::endl<<"poids:";

            for(int q=0; q<nbArrete; q++)
            {
                if(tabSolution[i][q]==1)
                {
                    pd1+=tabArrete[q]->getm_pd1();
                    pd2+=tabArrete[q]->getm_pd2();
                }
            }
std::cout<<pd1<<";"<<pd2<<std::endl;
            std::cout <<std::endl;
            pd1=0;
            pd2=0;
        }

int choix=0;
    std::cout <<"quels solution voulez vous dessiner? tapez 0 pour afficher les première du front de Pareto"<<std::endl;

    std::cin>>choix;

    std::cout <<std::endl;



    // on dessine toutes les solutions

  if(choix==0)
  {


    for(int i=0; i<tabSolution.size(); i++)
    {
        //on définie toutes les aretes à 0
        for(int j=0; j<nbArrete; j++)
        {
            tabArrete[j]->resetm_marquage();
        }

        for(int q=0; q<nbArrete; q++)
        {

            if(tabSolution[i][q]==1)
            {
                tabArrete[q]->setm_marquage();

            }
        }

        for (int i=0; i<nbArrete; i++)
        {
        }
        A->dessiner(ecran,(i+1)*2,0);

    }

  }

  else
    {

    for(int j=0; j<nbArrete; j++)
        {
            tabArrete[j]->resetm_marquage();
        }

        for(int q=0; q<nbArrete; q++)
        {

            if(tabSolution[choix][q]==1)
            {
                tabArrete[q]->setm_marquage();

            }
        }
        A->dessiner(ecran,(choix+1)*2,1);

  }
}

