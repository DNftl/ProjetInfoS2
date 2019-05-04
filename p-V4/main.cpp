#include <iostream>
#include <fstream>
#include "General/svgfile.h"
#include "Classe/graph.h"

int main()
{
  int choix=0,quitter=0;
  Graph A;
  A.lecture();
Svgfile svgout;
 A.dessiner(&svgout,0,0);


 while (quitter!=3)
 {
  do
    {
      choix=0;
       std::cout <<std::endl;
        std::cout <<std::endl;
      std::cout<<"choisisez l'action à realiser:"<<std::endl;
      std::cout<<"  1. Afficher les tableaux de sommets et d'aretes"<<std::endl;
      std::cout<<"  2. Trier le tableau d'aretes"<<std::endl;
      std::cout<<"  3. quitter"<<std::endl;
      std::cout<<"  4. Kruskal"<<std::endl;
            std::cout<<"  5. Pareto"<<std::endl;


        std::cin>>choix;

    }while (choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5);


    if (choix==1)//afficher tableaux
      A.affichage();

    if (choix==2)//trier arête
    {
      do
      {
        choix=0;
        std::cout<<"  selon quel poids souhaitez vous trier les arêtes"<<std::endl;
        std::cin>>choix;
      }while (choix!=1 && choix!=2);
      if (A.trier(choix)==1)
        std::cout<<"les arêtes ont été triés, voici le nouvel ordre: "<<std::endl;
        A.affichage();
    }
    if (choix==4)
    {
        A.kruskal(&svgout,&A);
    }

     if (choix==5)
    {
             A.pareto(&svgout,&A);

    }

    if (choix==3)
      return 0;
 }
return 0;
}

