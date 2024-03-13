//
// Created by John on 3/13/2024.
//
#include <NodeInterface.hpp>

#ifndef LOGICGATESANDEVENTS_ABSTRACTGATE_HPP
#define LOGICGATESANDEVENTS_ABSTRACTGATE_HPP



class AbstractNode : public ISubject, public IObserver
{
protected:
    std::list<IObserver*> observers_;

public:
    // ISubject interface methods
    void Attach(IObserver *observer) override{
        observers_.push_back(observer);
    }
    void Detach(IObserver *observer) override{
        observers_.remove(observer);
    }
    void Notify() override {
        for (auto observer : observers_) {
            observer->Update(GetState());
        }
    }

    virtual LogicState::eLogicState GetState() const = 0;

    // IObserver interface methods
    virtual void Update(LogicState::eLogicState state) override = 0;
};

#endif //LOGICGATESANDEVENTS_ABSTRACTGATE_HPP
