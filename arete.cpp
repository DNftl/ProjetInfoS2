#include "arete.h"
#include "sommet.h"
#include <iostream>


Arete::Arete(std::string idA, Sommet* s1, Sommet* s2):m_idA{idA}, m_s1(s1),m_s2{s2}
{
}

/*void Arete::ajouterArete(const Arete* Arete){
    m_arete.push_back(Arete);
}*/
 void Arete::afficherDataArete() const{
     std::cout<<m_idA<<" "<<m_s1->getId()<<" "<<m_s2->getId()<<std::endl;
 }

 void Arete::afficherDataArete2() const{
    std::cout<<m_idA<<" "<<m_pds1<<" "<<m_pds2<<std::endl;
 }
void Arete::afficherArete()const {
    std::cout<<std::endl;
    for(auto v:m_arete) {
        v->afficherDataArete();
    }
}

Sommet::~Sommet()
{
    //dtor
}

