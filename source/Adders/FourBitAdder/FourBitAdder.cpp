//
// Created by John on 5/11/2024.
//
#include <Adders/FourBitAdder/FourBitAdder.hpp>
#include "Switch/Switch.hpp"

FourBitAdder::FourBitAdder() {
    adder1 = new FullAdder();
    adder2 = new FullAdder();
    adder3 = new FullAdder();
    adder4 = new FullAdder();

    //carryIn = new Switch(LogicState::OFF);
    //SetCarryIn(carryIn);
}

void FourBitAdder::SetInputX1(AbstractNode *input) {
    inputX1 = input;
    input->Attach(this);

    adder1->SetInputX(inputX1);

    connectNodes_.push_back(input);
    //FourBitAdder::Update(GetState());
    adder1->Update(GetState());
}

void FourBitAdder::SetInputX2(AbstractNode *input) {
    inputX2 = input;
    input->Attach(this);

    adder2->SetInputX(inputX2);

    connectNodes_.push_back(input);
    //FourBitAdder::Update(GetState());
    adder2->Update(GetState());
}

void FourBitAdder::SetInputX3(AbstractNode *input) {
    inputX3 = input;
    input->Attach(this);

    adder3->SetInputX(inputX3);

    connectNodes_.push_back(input);
    adder3->Update(GetState());
}

void FourBitAdder::SetInputX4(AbstractNode *input) {
    inputX4 = input;
    input->Attach(this);

    adder4->SetInputX(inputX4);

    connectNodes_.push_back(input);
    adder4->Update(GetState());
}

void FourBitAdder::SetInputY1(AbstractNode *input) {
    inputY1 = input;
    input->Attach(this);

    adder1->SetInputY(inputY1);

    connectNodes_.push_back(input);
    adder1->Update(GetState());
}

void FourBitAdder::SetInputY2(AbstractNode *input) {
    inputY2 = input;
    input->Attach(this);

    adder2->SetInputY(inputY2);

    connectNodes_.push_back(input);
    adder2->Update(GetState());
}

void FourBitAdder::SetInputY3(AbstractNode *input) {
    inputY3 = input;
    input->Attach(this);

    adder3->SetInputY(inputY3);

    connectNodes_.push_back(input);
    adder3->Update(GetState());
}

void FourBitAdder::SetInputY4(AbstractNode *input) {
    inputY4 = input;
    input->Attach(this);

    adder4->SetInputY(inputY4);

    connectNodes_.push_back(input);
    adder4->Update(GetState());
}

void FourBitAdder::SetCarryIn(AbstractNode *input) {
    carryIn = input;
    input->Attach(this);
    adder1->SetCarryIn(carryIn);
}

void FourBitAdder::Update(LogicState::eLogicState state) {

    adder2->SetCarryIn(adder1->GetCarryOutNode());
    adder3->SetCarryIn(adder2->GetCarryOutNode());
    adder4->SetCarryIn(adder3->GetCarryOutNode());

    adder1->Update(adder1->GetState());
    adder2->Update(adder2->GetState());
    adder3->Update(adder3->GetState());
    adder4->Update(adder4->GetState());




    outputSumState1_ = adder1->GetState();
    outputSumState2_ = adder2->GetState();
    outputSumState3_ = adder3->GetState();
    outputSumState4_ = adder4->GetState();
    outputCarryState_ = adder4->GetCarryOut();

}

LogicState::eLogicState FourBitAdder::GetState() const {
    if (inputX1 && inputX2 && inputX3 && inputX4 && inputY1 && inputY2 && inputY3 && inputY4)
    {
        // TODO: Is this even what we want?
        return adder4->GetState();
    }
    return LogicState::DISABLED;
}

LogicState::eLogicState FourBitAdder::GetCarryOut() const {
    return adder4->GetCarryOut();
}

LogicState::eLogicState FourBitAdder::GetStateSum1() const {
    return outputSumState1_;
}

LogicState::eLogicState FourBitAdder::GetStateSum2() const {
    return outputSumState2_;
}

LogicState::eLogicState FourBitAdder::GetStateSum3() const {
    return outputSumState3_;
}

LogicState::eLogicState FourBitAdder::GetStateSum4() const {
    return outputSumState4_;
}
