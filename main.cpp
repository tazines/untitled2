#include <iostream>
#include "graphe.h"
#include "cours.h"
void test0(){

    Graphe * g = graphe::nouveau_graphe("test",true);
    graphe::print_sommet(g);
    Graphe*	g2 = graphe::nouveau_graphe("test2", false);
    Graphe*	g3 = graphe::nouveau_graphe("test3", false);
    Graphe*	g4 = graphe::nouveau_graphe("tet4", false);
    Graphe*	g5 = graphe::nouveau_graphe("test5", false);
    set<Graphe*> s;
    s.insert(g);
    s.insert(g2);
    s.insert(g3);
    s.insert(g4);
    s.insert(g5);
    graphe::ajout_prealable(g, g3);
    graphe::ajout_prealable(g, g4);
    graphe::ajout_prealable(g, g5);
    graphe::ajout_prealable(g, g2);
    graphe::print_prealable(g);
    graphe::print_avant(g);
    graphe::print_avant(g2);
    graphe::liberer_graphe(s);
}

void test1(){
    cours test;
    test.ajout_cours("cour1", true);
    test.ajout_cours("cour2", true);
    test.ajout_cours("cour3", false);
    test.ajout_cours("cour4", true);
    test.ajout_cours("cour5", true);
    test.ajout_arrete("cour1","cour2");
    test.ajout_arrete("cour1","cour3");
    test.ajout_arrete("cour1","cour4");
    test.ajout_arrete("cour1","cour5");
    test.ajout_arrete("cour2","cour4");
    test.ajout_arrete("cour3","cour4");
    test.imprimer_cursus();
}

void test2(){
    cours test;
    test.ajout_cours("cour1", true);
    test.ajout_cours("cour2", true);
    test.ajout_cours("cour3", false);
    test.ajout_cours("cour4", true);
    test.ajout_cours("cour5", true);
    test.ajout_arrete("cour1","cour2");
    test.ajout_arrete("cour1","cour3");
    test.ajout_arrete("cour1","cour4");
    test.ajout_arrete("cour1","cour5");
    set<string> s;
    s.insert("co");
    queue<Graphe *> e = test.requete1(s);

    while(!e.empty()){
        graphe::print_sommet(e.front());
        e.pop();
    }
}

void test3(){
    cours test;
    test.ajout_cours("cour1", true);
    test.ajout_cours("cour2", true);
    test.ajout_cours("cour3", false);
    test.ajout_cours("cour4", true);
    test.ajout_cours("cour5", true);
    test.ajout_arrete("cour1","cour2");
    test.ajout_arrete("cour1","cour3");
    test.ajout_arrete("cour1","cour4");
    test.ajout_arrete("cour1","cour5");
    set<string> s;
    s.insert("cour3");
    queue<set<Graphe *>> e = test.requete_n(s,2);

    while(!e.empty()){
        cout <<"["<<endl;
        for (auto i = e.front().begin(); i != e.front().end(); i++)
            graphe::print_sommet(*i);
        cout<<"]"<<endl;
        e.pop();
    }
}

int main() {
    cout << "TEST 0 : ";
    test0();
    cout << "TEST 1 : ";
    test1();
    cout << "TEST 2 : ";
    test2();
    cout << "TEST 3 : ";
    test3();

    return 0;
}
