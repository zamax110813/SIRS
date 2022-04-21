#ifndef EVENT_H
#define EVENT_H

#include"Obj.h"

enum TRANSITION{
    infection,//脆弱状態から感染状態
    removal,//脆弱状態から保護状態
    discovery,//保護状態から脆弱状態
    recovery,//感染状態から保護状態
    measure//時間計測用
};

class Obj;

class Event{
public:
	double time;
	Obj* handler;
	Event* next;
    TRANSITION type_of_event;
};

#endif
#pragma once
