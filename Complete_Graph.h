#ifndef INCLUDED_COMPLETE_GRAPH_H
#define INCLUDED_COMPLETE_GRAPH_H

#include<bits/stdc++.h>
#include"Node.h"
#include"Graph.h"
#include"Event.h"
#include"functions.h"

using namespace std;

class Complete_Graph:public Graph{
    public:
        Complete_Graph(int n,int init_s,int init_i,int init_r);
        void Build_Graph(void) override;
        void handle(Event* p);
};

#endif