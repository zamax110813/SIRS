#ifndef OBJ_H
#define OBJ_H

#include"Event.h"

class Event;

class Obj{
public:
	virtual void handle(Event* p)=0;
	virtual void recv(Event* p)=0;
protected:
	Obj* target;
};

#endif


#pragma once
