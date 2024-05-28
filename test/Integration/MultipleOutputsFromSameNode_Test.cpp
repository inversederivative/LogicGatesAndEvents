//
// Created by John on 5/6/2024.
//

#include <gtest/gtest.h>
#include <Switch/Switch.hpp>
#include <LogicGates/AndGate/AndGate.hpp>
#include <Display/Display.hpp>
#include "LogicGates/XorGate/XorGate.hpp"

TEST(MultipleTests, TestMultiple)
{

    Switch* switch1 = new Switch();


    AndGate* andGate = new AndGate();

    Display* display1 = new Display();
    Display* display2 = new Display();

    andGate->SetInputX(switch1);
    andGate->SetInputY(switch1);

    display1->SetInput(andGate);
    display2->SetInput(andGate);

    switch1->ChangeState(LogicState::ON);

    ASSERT_EQ(display1->GetState(),display2->GetState());
}

TEST(MultipleTests, RecreateUnrealScenario)
{
    auto s1 = new Switch();
    auto s2 = new Switch();

    auto ag = new AndGate();
    auto xg = new XorGate();

    auto d1 = new Display();

    ag->SetInputX(s1);
    ag->SetInputY(s2);

    s1->ChangeState(LogicState::ON);
    s2->ChangeState(LogicState::ON);

    ASSERT_EQ(ag->GetState(), LogicState::ON);

    xg->SetInputX(s1);
    xg->SetInputY(s2);

    s1->ChangeState(LogicState::OFF);
    s2->ChangeState(LogicState::OFF);

    s1->ChangeState(LogicState::ON);
    s2->ChangeState(LogicState::ON);

    ASSERT_EQ(ag->GetState(), LogicState::ON);
    ASSERT_EQ(xg->GetState(), LogicState::OFF);

}

TEST(test1, test2)
{
    std::string Name = "MyName" + std::to_string(0);
    ASSERT_EQ(Name, "MyName0");

}