#ifndef Arrete_H_INCLUDED
#define Arrete_H_INCLUDED



class Arrete
{
  public:
    Arrete (int id, int S1, int S2,float pd1,float pd2);
        Arrete ();


    void affichage();
    int getm_S1()const;
    int getm_S2()const;
    int getm_idA()const;
    int getm_pd1()const;
    int getm_pd2()const;
    void setm_marquage();
    int getm_marquage();
    void resetm_marquage();



  private:
    int m_S1,m_S2,m_idA;
    float m_pd1,m_pd2;
    int m_marquage;

};


#endif
