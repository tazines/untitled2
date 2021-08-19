//
// Created by User on 2021-08-14.
//

#include "graphe.h"

Graphe *graphe::nouveau_graphe(string nom, bool obligatoire) {
    Graphe* nouveau_graphe = new Graphe;
    nouveau_graphe->nom_cours = nom;
    nouveau_graphe->obligatoire = obligatoire;
    nouveau_graphe->fait = false;
    return nouveau_graphe;}

void graphe::ajout_prealable(Graphe *coursp, Graphe *cours) {
    if (cours && coursp){
        (coursp->cours_pre).insert(cours);
        (cours->cours_avant).insert(coursp);
    }
}

void graphe::print_sommet(Graphe *graphe) {
    cout << "Nom du cours :" << (graphe->nom_cours) << endl;
    cout << "obligatoire : " << (graphe->obligatoire) <<endl;
}

void graphe::print_prealable(Graphe *graphe) {
    auto it = (graphe->cours_pre).begin();
    while (it !=(graphe->cours_pre).end()){
        cout<<((*it)->nom_cours)<<endl;
        it++;
    }
}

void graphe::print_avant(Graphe *graphe) {
    auto it = (graphe->cours_avant).begin();
    while (it !=(graphe->cours_avant).end()){
        cout<<((*it)->nom_cours)<<endl;
        it++;
    }
}

void graphe::liberer_graphe(set<Graphe *> g) {
    for (auto i = g.begin(); i != g.end(); i++)
        delete (*i);
}
