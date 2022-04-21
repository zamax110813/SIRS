#ifndef INCLUDE_NODE_H
#define INCLUDE_NODE_H

enum STATE{
    Susceptible,
    Infected,
    Recovered
};

class Node{
    STATE state;//ノードの状態
    int degree;//次数
    int adj_inf;//隣接する感染ノード数
public:
    Node();
    int get_degree(void);
    int get_adj_inf(void);
    void add_degree(void);
    void sub_degree(void);
    void set_state(STATE state);
    void add_adj_inf(void);
    void sub_adj_inf(void);
};

#endif