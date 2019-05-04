#include "../Classe/graph.h"
#include <fstream>
#include <iostream>
#include <vector>

       Graph::Graph(){}
       void Graph::lecture()
       {

          std::vector<int> tabArreteS1;
          std::vector<int> tabArreteS2;

         int idA, idS, S_x, S_y,S1 ,S2, nbPPA, i=0;
          float pd1, pd2;


          std::ifstream fichier("fichier_texte/SommetArrete.txt", std::ios::in);

        if(fichier)
        {


                fichier >> nbSommet;

                for (i=0;i<nbSommet;i++)
                  {
                  fichier >> idS >> S_x >>S_y;

                    tabSommet.push_back(new Sommet(idS,S_x,S_y));

                  }

                fichier >> nbArrete;

                for (i=0;i<nbArrete;i++)
                  {
                  fichier >> idA >> S1 >>S2;


                    tabArreteS1.push_back(S1);
                    tabArreteS2.push_back(S2);



                  }





                fichier.close();
        }
        else
                std::cerr << "Impossible d'ouvrir le fichier !" << std::endl; //cerr est la sortie standard des erreurs. On peut aussi utiliser cout sans aucun problème.

        std::ifstream fichier1("fichier_texte/poids.txt", std::ios::in);


        if(fichier1)
        {

                fichier1 >> nbArrete >> nbPPA; //on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée

                  ///test:
                 //std::cout<<"nb de poids par arrête:"<<nbPPA <<"  nb d' arrête:"<<nbArrete<<std::endl;

                for (i=0;i<nbArrete;i++)
                  {
                  fichier1 >> idA >> pd1 >>pd2;


                    tabArrete.push_back(new Arrete(idA,tabArreteS1[idA],tabArreteS2[idA],pd1,pd2));


                  }


                fichier1.close();
        }
        else
                std::cerr << "Impossible d'ouvrir le fichier !" << std::endl; //cerr est la sortie standard des erreurs. On peut aussi utiliser cout sans aucun problème.
       }


