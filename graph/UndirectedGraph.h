//
// Created by rajverm2 on 19/05/20.
//

#ifndef ALGO_PRACTICE_UNDIRECTEDGRAPH_H
#define ALGO_PRACTICE_UNDIRECTEDGRAPH_H

#include <std_def.h>

class UndirectedGraph {
public:
    void add_vertex(char v){
        adjacency_list.insert(std::make_pair(v,std::set<char>()));
    }
    void add_edge(char u,char v){
        adjacency_list[u].insert(v);
    }
    const std::set<char>& adjacent_vertices(char u){
        return adjacency_list[u];
    }

    bool is_edge_exist(char u,char v){
        auto itr = adjacency_list.find(u);
        if(itr != adjacency_list.end()){
            return itr->second.find(v) != itr->second.end();
        }
        return false;
    }

private:
    std::unordered_map<char,std::set<char>> adjacency_list;
};


#endif //ALGO_PRACTICE_UNDIRECTEDGRAPH_H
