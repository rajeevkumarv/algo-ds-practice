//
// Created by rajverm2 on 19/05/20.
//
#include <std_def.h>
#include "UndirectedGraph.h"

void print_adjacents(UndirectedGraph& G,char v){
    std::cout<<"Adjacent vertices of "<<v<< " is ";
    auto adj_vertices = G.adjacent_vertices(v);
    std::copy(adj_vertices.begin(),adj_vertices.end(),std::ostream_iterator<char>(std::cout,", "));
    std::cout<<std::endl;
}

int main(){
    UndirectedGraph G;
    G.add_edge('B','A');
    G.add_edge('A','B');
    G.add_edge('C','M');
    G.add_edge('C','D');
    G.add_edge('A','F');
    G.add_edge('F','G');
    G.add_edge('F','B');

    print_adjacents(G,'C');
    print_adjacents(G,'F');
}