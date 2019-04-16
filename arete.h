#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "Sommet.h"
#include <vector>


class Arete
{
    public :
        Arete(std::string,Sommet*,Sommet*);
        ~Arete();
        //void ajouterArete(const Arete*);
        void afficherDataArete()const;
        void afficherDataArete2() const;
        void afficherArete() const;

    private :
        std::string m_idA;
        Sommet* m_s1;
        Sommet* m_s2;
        float m_pds1,m_pds2;
        std::vector< const Arete*> m_arete;

};


#endif // ARETE_H_INCLUDED
