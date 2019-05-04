#include "Sommet.h"


Sommet::Sommet(int id, int x, int y){m_idS=id; m_x=x; m_y=y; m_marquage=0;}

int Sommet::getm_x() const
{return m_x;}
int Sommet::getm_y() const
{return m_y;}
int Sommet::getm_idS() const
{return m_idS;}
void Sommet::setm_marquage()
    {m_marquage=1;}
int Sommet::getm_marquage(){return m_marquage;}
void Sommet::resetm_marquage(){m_marquage=0;}

