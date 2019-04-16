#include "arete.h"


Arete::Arete(std::string idA,double x,double y):m_idA{idS},m_x{x},m_y{y}
{
}
void Sommet::ajouterSommet(const Sommet* sommet){
    m_sommet.push_back(sommet);
}
 void Sommet::afficherData() const{
     std::cout<<"    "<<m_idS<<" : "<<m_x<<" "<<m_y<<std::endl;
 }
void Sommet::afficherSommet() const{
    std::cout<<std::endl;
    for(auto v:m_sommet) {
        v->afficherData();
    }
}

Sommet::~Sommet()
{
    //dtor
}
