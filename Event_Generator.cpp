#include"Event_Generator.h"
using namespace std;

Event_Generator* Event_Generator::instance_;

//k:ホスト一台当たりの脆弱性発見率,l
Event_Generator::Event_Generator(double alpha,double deltas,double deltai,double eta,double interval,Graph* G){
    this->target_graph=G;
    this->eta=eta;
    this->deltas=deltas;
    this->alpha=alpha;
    this->deltai=deltai;
    this->interval=interval;
    rate_vector.assign(4,0);
    lambda=0;
}

double Event_Generator::culc_interval(){
	return -(log(1 - (functions::random_double())))/lambda;
}

void Event_Generator::start(){
  renew_rate();
  Event* e=new Event;
  Event* p=new Event;
  p->type_of_event=measure;
  set_transition(e);
  Scheduler::instance().schedule(this,e,culc_interval());
  Scheduler::instance().schedule(this,p,0);
}

void Event_Generator::renew_rate(){
    double S=target_graph->get_num_s();
    double I=target_graph->get_num_i();
    double R=target_graph->get_num_r();
    rate_vector[0]=alpha*S*I;//脆弱状態から感染状態への遷移率
    rate_vector[1]=deltas*S;//脆弱状態から保護状態への遷移率
    rate_vector[2]=eta*(I+1)*R;//保護状態から脆弱状態への遷移率
    rate_vector[3]=deltai*I;//感染状態から保護状態への遷移率
    lambda=0;
    for(int i=0;i<4;i++)lambda+=rate_vector[i];
}

void Event_Generator::set_transition(Event* p){
  int i=functions::choose(rate_vector);
  if(i==0){
    p->type_of_event=infection;
  }else if(i==1){
    p->type_of_event=removal;
  }else if(i==2){
    p->type_of_event=discovery;
  }else if(i==3){
    p->type_of_event=recovery;
  }
}

void Event_Generator::handle(Event* p){
    if(p->type_of_event==measure){
        int S=target_graph->get_num_s();
        int I=target_graph->get_num_i();
        int R=target_graph->get_num_r();
        cout<<p->time<<" "<<S<<" "<<I<<" "<<R<<endl;
        Event* e=new Event;
        e->type_of_event=measure;
        Scheduler::instance().schedule(this,e,interval);
        return ;
    }
    target_graph->recv(p);
    renew_rate();
    Event* e=new Event;
    set_transition(e);
    Scheduler::instance().schedule(this,e,culc_interval());
}

void Event_Generator::recv(Event* p){

}