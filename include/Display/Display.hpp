//
// Created by John on 3/12/2024.
//
#include <AbstractNode.hpp>

#ifndef LOGICGATESANDEVENTS_DISPLAY_HPP
#define LOGICGATESANDEVENTS_DISPLAY_HPP

class Display : public AbstractNode
{
private:
    // Don't need this, because the Display has NO observers!!!
    std::list<IObserver*> connectedNodes_;
    AbstractNode* input_;
    bool state_ = false;

public:

    void SetInput(AbstractNode* input);

    bool GetState() const override;

    void Update(bool state) override;

};

#endif //LOGICGATESANDEVENTS_DISPLAY_HPP
