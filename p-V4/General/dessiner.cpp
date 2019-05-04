#include "../Classe/graph.h"
#include <iostream>
#include <fstream>
#include <sstream>//pour ostringstream
#include <stdlib.h>// pour valeur absolue


void Graph::dessiner(Svgfile *ecran,int a,int b)
{
    if (a==0&& b==0)
    {
        for (int i=0; i<nbArrete; i++)
        {
            //afficher le poids:

            std::ostringstream oss;
            oss<<tabArrete[i]->getm_pd1()<<","<<tabArrete[i]->getm_pd2();//methode trouvé sur developpez.net
            std:: string poid =oss.str();

            int S2=tabArrete[i]->getm_S2();
            int S1=tabArrete[i]->getm_S1();
            int x=(tabSommet[S2]->getm_x()+tabSommet[S1]->getm_x()+4)/2;
            x=abs(x);
            int y=(tabSommet[S2]->getm_y()+tabSommet[S1]->getm_y()+26)/2;
            y=abs(y);

            ecran->addText(x,y,poid,"black");

            //arêtes:
            ecran->addLine(tabSommet[tabArrete[i]->getm_S1()]->getm_x(),tabSommet[tabArrete[i]->getm_S1()]->getm_y(),tabSommet[tabArrete[i]->getm_S2()]->getm_x(),tabSommet[tabArrete[i]->getm_S2()]->getm_y(),"red" );
        }

        for (int i=0; i<nbSommet; i++)
        {
            //Sommets:
            ecran->addDisk(tabSommet[i]->getm_x(), tabSommet[i]->getm_y(),5, "black");
            ecran->addText(tabSommet[i]->getm_x()+5,tabSommet[i]->getm_y()+5,tabSommet[i]->getm_idS(),"black");

        }
    }


    if (a==1 && b==0)
    {
        ecran->addText(400,75,"Kruskal:","black");
        for (int i=0; i<nbArrete; i++)
        {
            if(tabArrete[i]->getm_marquage()==1 )
            {
               ecran->addLine((tabSommet[tabArrete[i]->getm_S1()]->getm_x()+300),tabSommet[tabArrete[i]->getm_S1()]->getm_y(),(tabSommet[tabArrete[i]->getm_S2()]->getm_x()+300),tabSommet[tabArrete[i]->getm_S2()]->getm_y(),"red" );

            }
        }

        for (int i=0; i<nbSommet; i++)
        {
            //Sommets:
            ecran->addDisk((tabSommet[i]->getm_x()+300), tabSommet[i]->getm_y(),5, "black");
        }
    }
        if (a!=0 && a!=1 && b==0)
    {
        a-=1;
        a=a*100;
        for (int i=0; i<nbArrete; i++)
        {

            if(tabArrete[i]->getm_marquage()==0 )
            {
                int S1=tabArrete[i]->getm_S1();
                int S2=tabArrete[i]->getm_S2();
               ecran->addLine((tabSommet[S1]->getm_x()+a),tabSommet[S1]->getm_y()+275,(tabSommet[S2]->getm_x()+a),tabSommet[S2]->getm_y()+275,"red" );

            }
        }

        for (int i=0; i<nbSommet; i++)
        {
            //Sommets:
            ecran->addDisk((tabSommet[i]->getm_x()+a), tabSommet[i]->getm_y()+275,5, "black");
        }
    }

    if (b==1)
    {
        for (int i=0; i<nbArrete; i++)
        {

            if(tabArrete[i]->getm_marquage()==0 )
            {
                int S1=tabArrete[i]->getm_S1();
                int S2=tabArrete[i]->getm_S2();
               ecran->addLine((tabSommet[S1]->getm_x()),tabSommet[S1]->getm_y()+275,(tabSommet[S2]->getm_x()),tabSommet[S2]->getm_y()+275,"red" );

            }
        }

        for (int i=0; i<nbSommet; i++)
        {
            //Sommets:
            ecran->addDisk((tabSommet[i]->getm_x()), tabSommet[i]->getm_y()+275,5, "black");
        }
    }

}
