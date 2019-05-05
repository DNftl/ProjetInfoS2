#ifndef Sommet_H_INCLUDED
#define Sommet_H_INCLUDED


class Sommet
{
  public:
    Sommet (int id, int x, int y);
    void affichage();
    int getm_x()const;
    int getm_y()const;
    int getm_idS()const;
    void setm_marquage();
    int getm_marquage();
    void resetm_marquage();


  private:
    int m_x,m_y,m_idS;
        int m_marquage;

};


#endif
