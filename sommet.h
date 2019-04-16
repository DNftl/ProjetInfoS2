#ifndef SOMMET_H
#define SOMMET_H
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Sommet
{
    public:
        ///constructeur qui re¡oit en params les donn»es du sommet
        Sommet(std::string,double,double);
        void ajouterSommet(const Sommet*);
        void afficherData()const ;
        std::string getId() const {return m_idS;}
        void afficherSommet()const;
        ~Sommet();

    protected:

    private:
        /// Voisinage : liste d'adjacence
        std::vector<const Sommet*> m_sommet;

        /// Donn»es sp»cifiques du sommet
        std::string m_idS; // Identifiant
        double m_x, m_y; // Position

};

#endif // SOMMET_H
