#ifndef INCLUDED_GRAPH_H
#define INCLUDED_GRAPH_H

#include<bits/stdc++.h>
#include<vector>
#include"Node.h"
#include"Obj.h"
#include"functions.h"

using namespace std;

class Graph:public Obj{
protected:
    int total_nodes;//全ノード数
    int total_s;//脆弱ホスト数
    int total_i;//感染ホスト数
    int total_r;//保護ホスト数
    int avg_degree;//平均次数
    int num_sus_adj_inf;//感染ノードに隣接してる脆弱ノード数
    vector<double> statevec_s;//脆弱状態かどうかの配列 
    vector<double> statevec_i;//感染状態かどうかの配列 
    vector<double> statevec_r;//保護状態かどうかの配列 
    vector<vector<int> > adjacent_matrix;//隣接行列
    vector<vector<int> > adjacent_list;//隣接リスト
    vector<Node> nodes;//各ホストを格納する配列
    vector<double> sus_adj_inf;//感染ノードに隣接してる脆弱ノードは1,それ以外は0
public:
    Graph(int n,int k,int s,int i,int r);
    int get_num_sus_adj_inf(void);
    int get_total_nodes(void);
    int get_num_s(void);
    int get_num_i(void);
    int get_num_r(void);
    void out_params(void);
    void out_graph(void);
    virtual void Build_Graph(void)=0;
    virtual void handle(Event* p)=0;
    void recv(Event* p);
};

#endif