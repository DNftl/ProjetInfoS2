#include <fstream>
#include <iostream>
#include "graphe.h"
#include "arete.h"

graphe::graphe(std::string nomFichier){
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    std::string id;
    std::string idA;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i)
        {
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        m_sommets.insert({id,new Sommet{id,x,y}});
        }



    int taille;
    std::string id1;
    std::string id2;


    ifs >> taille;

    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");


    //lecture des aretes
    for (int i=0; i<taille; ++i){
        //lecture des ids des deux extrémités
        ifs>>idA; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id1; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
        ifs>>id2; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");


        m_arete.insert({idA,new Arete(idA,m_sommets.find(id1)->second,m_sommets.find(id2)->second)});
        ///(m_sommets.find(id))->second->ajouterSommet((m_sommets.find(id_voisin))->second);
        ///(m_sommets.find(id_voisin))->second->ajouterSommet((m_sommets.find(id))->second);//remove si graphe orienté
    }
}


/// /// /// ///

graphe::graphe(std::string nomFichier,int x){
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int taille;
        ifs >> taille;


    float pds1;
    float pds2;
    std::string idA; //idA du deuxieme fichier

    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");

    float poids;
    ifs >> poids;
    //lecture des sommets
    for (int i=0; i<taille; ++i)
        {
        ifs>>idA; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>pds1; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>pds2; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        m_sommets.insert({idA,new Sommet{idA,pds1,pds2}});
        }
    }





void graphe::afficherT1() const{
    //std::cout<<"graphe : "<<std::endl;
    std::cout<< m_sommets.size() <<std::endl;

    for( const auto& it:m_sommets){
      //std::cout<< "sommets : ";
      it.second->afficherData(); ///affiche les sommets
      //it.second->afficherSommet(); ///affiche les aretes
    }

    std::cout<<m_arete.size() <<std::endl;
    for( const auto& it:m_arete){
    //std::cout<< "arete : ";
    it.second->afficherDataArete(); ///affiche les sommets*/

}
}

void graphe::afficherT2() const{

    std::cout<<std::endl;
    std::cout<<m_arete.size() <<std::endl;
    for( const auto& it:m_arete){
    //std::cout<< "arete : ";
    it.second->afficherDataArete2(); ///affiche les sommets*/
}

}
graphe::~graphe()
{
    //dtor
}

