#include <iostream>
#include <queue>
#include <stack>
#include<unordered_map>
#include<unordered_set>
#include "sommet.h"

Sommet::Sommet(std::string idS,double x,double y):m_idS{idS},m_x{x},m_y{y}
{
}
/*void Sommet::ajouterSommet(const Sommet* sommet){
    m_sommet.push_back(sommet);
}*/
 void Sommet::afficherData() const{
     std::cout<<m_idS<<" "<<m_x<<" "<<m_y<<std::endl;
 }
void Sommet::afficherSommet() const{
    std::cout<<std::endl;
    for(auto v:m_sommet) {
        v->afficherData();
    }
}


/*Sommet::~Sommet()
{
    //dtor
}*/
