#include<bits/stdc++.h>
#include"Complete_Graph.h"
#include"Scheduler.h"
#include"Event_Generator.h"

namespace parameters{
    double simulation_time;//シミュレーション実行時間
    int num_s;//脆弱ホスト数
    int num_i;//感染ホスト数
    int num_r;//保護ホスト数
    int total_nodes;//全ホスト数
    double alpha;//ホスト一台当たりのマルウェア感染率
    double deltas;//ホスト一台当たりの脆弱性除去率
    double deltai;//ホスト一台当たりのマルウェア除去率
    double eta;//ホスト一台当たりの脆弱性発見率
    double avg_degree;//グラフの平均次数
    double recon_prob;//グラフの辺の再接続確率
    int graph;//グラフの種類
    double interval;//計測間隔
}

int main(int argc,char *argv[]){
    parameters::simulation_time=atof(argv[1]);
    parameters::total_nodes=atoi(argv[2]);
    parameters::num_s=atoi(argv[3]);
    parameters::num_i=atoi(argv[4]);
    parameters::num_r=atoi(argv[5]);
    parameters::alpha=atof(argv[6]);
    parameters::deltas=atof(argv[7]);
    parameters::deltai=atof(argv[8]);
    parameters::eta=atof(argv[9]);
    parameters::avg_degree=atoi(argv[10]);
    parameters::recon_prob=atof(argv[11]);
    parameters::graph=atoi(argv[12]);
    parameters::interval=atof(argv[13]);
    Scheduler* scheduler=new Scheduler();
    Graph* graph;
    if(parameters::graph==0){
        graph=new Complete_Graph(parameters::total_nodes,parameters::num_s,parameters::num_i,parameters::num_r);
    }else if(parameters::graph==1){
        
    }else if(parameters::graph==2){

    }
    Event_Generator* generator=new Event_Generator(parameters::alpha,parameters::deltas,parameters::deltai,parameters::eta,parameters::interval,graph);
    scheduler->init(parameters::simulation_time);  
    generator->start();
    scheduler->run();
    return 0;
}