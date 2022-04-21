#include"Node.h"

Node::Node(){
    adj_inf=0;
    degree=0;
    this->state=Susceptible;
}

int Node::get_degree(void){
    return degree;
}

int Node::get_adj_inf(void){
    return adj_inf;
}

void Node::add_degree(void){
    degree++;
}

void Node::sub_degree(void){
    degree--;
}

void Node::set_state(STATE state){
    this->state=state;
}

void Node::add_adj_inf(void){
    adj_inf++;
}

void Node::sub_adj_inf(void){
    adj_inf--;
}

