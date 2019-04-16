#ifndef GRAPHE_H
#define GRAPHE_H
#include <string>
#include <unordered_map>
#include "sommet.h"
#include "arete.h"

class graphe
{
    public:
        ///constructeur qui charge le graphe en m»moire
        //format du fichier ordre/liste des sommets/taille/liste des arÕtes
        graphe(std::string);
        graphe(std::string,int);
        ~graphe();
        void afficherT1() const;
        void afficherT2() const;
        ///lance un parcours en largeur á partir du sommet d'identifiant id

    protected:

    private:
        /// Le r»seau est constitu» d'une collection de sommets
        std::unordered_map<std::string,Sommet*> m_sommets;//stock»e dans une map (cl»=id du sommet, valeur= pointeur sur le sommet)
        std::unordered_map<std::string,Arete*>m_arete;
};

#endif // GRAPHE_H
