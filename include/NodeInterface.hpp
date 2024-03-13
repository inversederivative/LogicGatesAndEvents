//
// Created by John on 3/12/2024.
//
#include <iostream>
#include <list>

#ifndef LOGICGATESANDEVENTS_ABSTRACTNODE_HPP
#define LOGICGATESANDEVENTS_ABSTRACTNODE_HPP

// Here we will implement our Observer Pattern
class IObserver
{
public:
    virtual ~IObserver()= default;
    virtual void Update(bool state) = 0;
};

class ISubject
{
public:
    virtual ~ISubject()= default;
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};

#endif //LOGICGATESANDEVENTS_ABSTRACTNODE_HPP
