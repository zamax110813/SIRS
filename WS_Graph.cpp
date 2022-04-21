#include"WS_Graph.h"

//n:全ノード数,e:全エッジ数,k:平均次数,prob:辺の再接続確率,
WS_Graph::WS_Graph(int n,int k,double prob,int init_s,int init_i,int init_r):Graph(n,k,init_s,init_i,init_r){
    reconnect_prob=prob;
    Build_Graph();
    vector<double> used(n,1.0);
    for(int i=0;i<total_s;i++){
        int tmp=functions::choose(used);
        statevec_s[tmp]=1;
        nodes[tmp].set_state(Susceptible);
        used[tmp]=0;
    }
    for(int i=0;i<total_i;i++){
        int tmp=functions::choose(used);
        statevec_i[tmp]=1;
        nodes[tmp].set_state(Infected);
        used[tmp]=0;
        for(int i=0;i<adjacent_list[tmp].size();i++){
            nodes[adjacent_list[tmp][i]].add_adj_inf();
        }
    }
    for(int i=0;i<total_r;i++){
        int tmp=functions::choose(used);
        statevec_r[tmp]=1;
        nodes[tmp].set_state(Recovered);
        used[tmp]=0;
    }
}

void WS_Graph::handle(Event* p){

}

void WS_Graph::Build_Graph(void){
    for(int i=0;i<(avg_degree/2);i++){
        for(int j=0;j<total_nodes;j++){
            int from=j;
            int to=(i+j+1)%total_nodes;
            adjacent_matrix[from][to]=1;
            adjacent_matrix[to][from]=1;
            nodes[from].add_degree();
            nodes[to].add_degree();
        }
    }
    for(int i=0;i<(avg_degree/2);i++){
        for(int j=0;j<total_nodes;j++){
            int from=j;
            int to=(i+j+1)%total_nodes;
            if(functions::random_double()<reconnect_prob){
                int tmp=functions::random_int(total_nodes);
                if(nodes[tmp].get_degree()>=total_nodes-1)continue;
                if(tmp!=from&&adjacent_matrix[from][tmp]==0){
                    adjacent_matrix[from][to]=0;
                    adjacent_matrix[to][from]=0;
                    nodes[to].sub_degree();
                    adjacent_matrix[from][tmp]=1;
                    adjacent_matrix[tmp][from]=1;
                    nodes[tmp].add_degree();
                }else{
                    while(tmp==from||adjacent_matrix[from][tmp]==1){
                        tmp=functions::random_int(total_nodes);
                    }
                    adjacent_matrix[from][to]=0;
                    adjacent_matrix[to][from]=0;
                    nodes[to].sub_degree();
                    adjacent_matrix[from][tmp]=1;
                    adjacent_matrix[tmp][from]=1;
                    nodes[tmp].add_degree();
                }
            }
        }
    }
    for(int i=0;i<total_nodes;i++){
        for(int j=0;j<total_nodes;j++){
            if(adjacent_matrix[i][j])adjacent_list[i].push_back(j);
        }
    }
}
