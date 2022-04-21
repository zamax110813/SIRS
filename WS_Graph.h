#ifndef WS_GRAPH_H
#define WS_GRAPH_H

#include<bits/stdc++.h>
#include"Node.h"
#include"Graph.h"
#include"Event.h"
#include"functions.h"

using namespace std;

class WS_Graph:public Graph{
private:
    double reconnect_prob;//辺の再接続確率
public:
    WS_Graph(int n,int k,double prob,int init_s,int init_i,int init_r);
    void Build_Graph(void) override;
    void handle(Event* p);
};

#endif