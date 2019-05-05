#include "Arrete.h"


Arrete::Arrete(int id, int S1, int S2,float pd1, float pd2){m_idA=id; m_S1=S1; m_S2=S2; m_pd1=pd1; m_pd2=pd2; m_marquage=1;}
Arrete::Arrete (){m_marquage=1;}


    int Arrete::getm_S1()const
    {return m_S1;}
    int Arrete::getm_S2()const
    {return m_S2;}
    int Arrete::getm_idA()const
    {return m_idA;}
    int Arrete::getm_pd1()const
    {return m_pd1;}
    int Arrete::getm_pd2()const
    {return m_pd2;}
    void Arrete::setm_marquage()
    {m_marquage=0;}
    int Arrete::getm_marquage(){return m_marquage;}
    void Arrete::resetm_marquage(){m_marquage=1;}





