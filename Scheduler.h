#ifndef SCHEDULER_H
#define SCHEDULER_H

#include<bits/stdc++.h>
#include"Event.h"

using namespace std;

class Scheduler {

public:
	static Scheduler& instance()
	{
		return (*instance_);
	}
	void schedule(Obj* h, Event* e, double delay);
	virtual void run();
	virtual void insert(Event* e);
	virtual Event* deque();
	Scheduler();
	virtual ~Scheduler();
	inline double clock() const
	{
		return (clock_);
	}
	void init(double time);
protected:
	void dispatch(Event* p);
	void dispatch(Event* p, double t);
	double clock_;
	static Scheduler* instance_;
	Event* queue_;
	double finish_time_;
};

#endif


