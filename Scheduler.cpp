#include"Scheduler.h"

Scheduler* Scheduler::instance_;

Scheduler::Scheduler()
{
	clock_ = 0;
	queue_ = 0;
	instance_ = this;
}

Scheduler::~Scheduler()
{
	instance_ = nullptr;
}

void Scheduler::schedule(Obj* h, Event* e, double delay)
{
	e->handler = h;
	double t = clock_ + delay;
	e->time = t;
	insert(e);
}

void Scheduler::run() {
	instance_ = this;
	Event* p;
	while (clock_ <= finish_time_) {
		p = deque();
		dispatch(p, p->time);
	}
}

void Scheduler::insert(Event* e)
{
	double t = e->time;
	Event** p;
	for (p = &queue_; *p != 0; p = &(*p)->next)
		if (t < (*p)->time)
			break;
	e->next = *p;
	*p = e;
}

Event* Scheduler::deque()
{
	Event* e = queue_;
	if (e != 0) queue_ = e->next;
	return(e);
}

void Scheduler::dispatch(Event* p, double t)
{
	clock_ = t;
	p->handler->handle(p);
}

void Scheduler::dispatch(Event* p)
{
	dispatch(p, p->time);
}

void Scheduler::init(double time)
{
	finish_time_ = time;
}
