#include"Graph.h"

Graph::Graph(int n,int k,int s,int i,int r){
    total_nodes=n;
    avg_degree=k;
    statevec_s.assign(total_nodes,0);
    statevec_i.assign(total_nodes,0);
    statevec_r.assign(total_nodes,0);
    total_s=s;
    total_i=i;
    total_r=r;
    num_sus_adj_inf=0;
    adjacent_matrix.assign(total_nodes,vector<int>(total_nodes,0));
    adjacent_list.resize(total_nodes);
    sus_adj_inf.assign(total_nodes,0);
    nodes.assign(total_nodes,Node());
}

void Graph::recv(Event* p){
    switch(p->type_of_event){
        //R->Sへの遷移
        case discovery:
        {
            int index=functions::choose(statevec_r);
            statevec_r[index]=0;
            statevec_s[index]=1;
            total_r--;
            total_s++;
            return;
        }
        case removal://S->Rへの遷移
        {
            int index=functions::choose(statevec_s);//脆弱ノードからランダムに一つ選択
            statevec_s[index]=0;
            statevec_r[index]=1;
            total_s--;
            total_r++;
            return;
        }
        case infection://S->Iへの遷移
        {
            int index=functions::choose(statevec_s);//脆弱ノードの中からランダムに選択
            nodes[index].set_state(Infected);//状態変更
            total_i++;
            total_s--;
            statevec_i[index]=1;
            statevec_s[index]=0;
            return;
        }
        case recovery://I->Rへの遷移
        {
            int index=functions::choose(statevec_i);
            nodes[index].set_state(Recovered);
            total_i--;
            total_r++;
            statevec_i[index]=0;
            statevec_r[index]=1;
            return ;
        }
    }
}

void Graph::out_params(void){
    cout<<"total_nodes : "<<total_nodes<<" ";
    cout<<"total_s : "<<total_s<<" ";
    cout<<"total_i : "<<total_i<<" ";
    cout<<"total_r : "<<total_r<<" ";
    cout<<"avg_degree : "<<avg_degree<<endl;
}

void Graph::out_graph(void){
    for(int i=0;i<total_nodes;i++){
        for(int j=0;j<adjacent_list[i].size();j++){
            cout<<adjacent_list[i][j]<<" ";
        }
        cout<<endl;
    }
}

int Graph::get_total_nodes(void){
    return total_nodes;
}

int Graph::get_num_sus_adj_inf(void){
    return num_sus_adj_inf;
}

int Graph::get_num_s(void){
    return total_s;
}

int Graph::get_num_i(void){
    return total_i;
}

int Graph::get_num_r(void){
    return total_r;
}