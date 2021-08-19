//
// Created by User on 2021-08-14.
//

#include "cours.h"
#include <bits/stdc++.h>

cours::~cours() {
    graphe::liberer_graphe(cursus);
}

void cours::ajout_cours(string nom, bool obli) {
    cursus.insert(graphe::nouveau_graphe(nom, obli));
}

void cours::ajout_arrete(string pre, string sui) {
    Graphe* p = nullptr;
    Graphe* s = nullptr;

    for (auto it = cursus.begin(); it != cursus.end()  || (!p && !s); it++){
        if ((*it)->nom_cours == pre)
            p = *it;
        else if ((*it)->nom_cours == sui)
            s = *it;
    }
    if (p && s)
        graphe::ajout_prealable(p, s);
}

void cours::imprimer_cursus() {
    for (auto it = cursus.begin(); it != cursus.end(); it++){
        cout<<"Sommet : ";
        graphe::print_sommet(*it);
        cout<<endl;
        cout<<endl;
        cout<<"Prealables : ";
        graphe::print_prealable(*it);
        cout<<endl;
        cout<<endl;
        cout<<"Avant : ";
        graphe::print_avant(*it);
        cout<<endl;
    }
}

void cours::reinitialiser_cursus() {
    for (auto it = cursus.begin(); it != cursus.end(); it++)
        (*it)->fait = false;
}

queue<Graphe *> cours::requete1(set<string> cours_obt) {
    queue<Graphe*> fin;
    for(auto it = cursus.begin(); it != cursus.end(); it++){

        if ((*it)->obligatoire || (cours_obt.find((*it)->nom_cours)!= cours_obt.end())){
            recherche(*it,fin);
        }
    }
    reinitialiser_cursus();
    return fin;
}

void cours::recherche(Graphe * graphe, queue<Graphe *>& queue) {
    if (!(graphe->fait)){
        for (auto i = (graphe->cours_avant).begin(); i !=(graphe->cours_avant).end() ; i++) {
            recherche(*i,queue);
        }
        queue.push(graphe);
        (graphe->fait) = true;
    }
}

queue<set<Graphe*>> cours::requete_n(set<string> cours_obt,int n) {
    queue<Graphe*> temp = requete1(cours_obt);
    queue<set<Graphe*>> fin;
    set<Graphe*> courante;
    int i = 0;
    while (!temp.empty()){
        if(courante.size()>=n ||!(intersection(courante,temp.front()->cours_avant).empty())){

            fin.push(courante);
            courante.clear();
        }
        courante.insert(temp.front());
        temp.pop();
        i++;
    }
    fin.push(courante);
    return fin;
}

set<Graphe*> cours::intersection(set<Graphe *> s1, set<Graphe *> s2) {
    set<Graphe*> inter;
    for(auto it=s1.begin();it!=s1.end();it++){
        if (s2.find(*it)!=s2.end())
            inter.insert(*it);
    }

    return inter;
}
