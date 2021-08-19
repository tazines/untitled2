//
// Created by User on 2021-08-14.
//

#ifndef UNTITLED2_COURS_H
#define UNTITLED2_COURS_H
#include "graphe.h"
#include <queue>

class cours {
public :
    ~cours();
    void ajout_cours(string nom, bool obli);
    void ajout_arrete(string pre, string sui);
    set<Graphe*> cursus;
    void imprimer_cursus();

    queue<Graphe*> requete1(set<string> cours_obt);
    queue<set<Graphe *>> requete_n(set<string> cours_obt, int n);

private:
    void reinitialiser_cursus();

    void recherche(Graphe *graphe, queue<Graphe *>& queue);
    set<Graphe*> intersection(set<Graphe*> s1, set<Graphe*> s2 );


};


#endif //UNTITLED2_COURS_H
