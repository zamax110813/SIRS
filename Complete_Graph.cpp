#include"Complete_Graph.h"

Complete_Graph::Complete_Graph(int n,int init_s,int init_i,int init_r):Graph(n,n-1,init_s,init_i,init_r){
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
    //感染ノードに隣接した非対策脆弱ノードをsus_adj_infに記録,感染ノードに隣接した対策脆弱ノードをsus_adj_inf_cに記録
    for(int i=0;i<n;i++){
        if(statevec_i[i]){
            for(int j=0;j<adjacent_list[i].size();j++)if(statevec_s[adjacent_list[i][j]])sus_adj_inf[adjacent_list[i][j]]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(sus_adj_inf[i])num_sus_adj_inf++;
    }
}

void Complete_Graph::Build_Graph(void){
    for(int i=0;i<avg_degree;i++){
        for(int j=0;j<total_nodes;j++){
            int from=j;
            int to=(i+j+1)%total_nodes;
            adjacent_matrix[from][to]=1;
            adjacent_matrix[to][from]=1;
            nodes[from].add_degree();
            nodes[to].add_degree();
        }
    }
    for(int i=0;i<total_nodes;i++){
        for(int j=0;j<total_nodes;j++){
            if(adjacent_matrix[i][j])adjacent_list[i].push_back(j);
        }
    }
}

void Complete_Graph::handle(Event* p){

}