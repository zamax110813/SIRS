#ifndef EVENT_GENERATOR_H
#define EVENT_GENERATOR_H

#include"Obj.h"
#include<bits/stdc++.h>
#include"Graph.h"
#include"functions.h"
#include"Scheduler.h"
#include<vector>

using namespace std;

class Event_Generator:public Obj{
  public:
    static Event_Generator& instance(){
      return (*instance_);
    };
    Event_Generator(double alpha,double deltas,double deltai,double eta,double interval,Graph* G);
    void start();
    void handle(Event* p);
    void recv(Event* p);
    void renew_rate();
    void set_transition(Event *p);
  private:
    Graph* target_graph;
    double culc_interval();
    double eta;
    double deltas;
    double alpha;
    double deltai;
    double discovery_rate;
    double recovery_rate;
    double infection_rate;
    double removal_rate;
    double lambda;
    double interval;
    vector<double> rate_vector;
    static Event_Generator* instance_;
};


#endif
#pragma once