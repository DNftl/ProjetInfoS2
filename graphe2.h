#ifndef GRAPHE2_H_INCLUDED
#define GRAPHE2_H_INCLUDED

#include "sommet.h"
#include "arete.h"

class graphe2
{
    public:
        ///constructeur qui charge le graphe en m»moire
        //format du fichier ordre/liste des sommets/taille/liste des arÕtes
        graphe2(std::string);
        ~graphe2();
        void afficherT2() const;
        ///lance un parcours en largeur á partir du sommet d'identifiant id

    protected:

    private:
};

#endif // GRAPHE2_H_INCLUDED
