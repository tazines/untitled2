//
// Created by User on 2021-08-14.
//

#ifndef GRAPHE_H
#define GRAPHE_H
#include <string>
#include <set>
#include <iostream>
using namespace std;

typedef struct Graphe {
    set<struct Graphe*>  cours_pre;//je suis prealable a
    set<struct Graphe*>  cours_avant;//ils sont prealable a moi
    string nom_cours;
    bool obligatoire;
    bool fait;
} Graphe;


class graphe {
public:
    static Graphe* nouveau_graphe(string nom, bool obligatoire);
    static void ajout_prealable(Graphe* coursp, Graphe* cours);
    static void print_sommet(Graphe* graphe);
    static void print_prealable(Graphe* graphe);
    static void print_avant(Graphe* graphe);
    static void liberer_graphe(set<Graphe*> g);
};


#endif //UNTITLED2_GRAPHE_H
