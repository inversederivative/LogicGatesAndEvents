//
// Created by John on 3/13/2024.
//
#include <gtest/gtest.h>
#include <Switch/Switch.hpp>
#include <LogicGates/AndGate/AndGate.hpp>
#include <Display/Display.hpp>

TEST(LogicGates_IntegrationTests, IntegrationTest)
{
    // 1. Setup
    auto switchX1 = new Switch();
    auto switchX2 = new Switch();
    auto switchY1 = new Switch();
    auto switchY2 = new Switch();

    auto andGate1 = new AndGate();
    auto andGate2 = new AndGate();
    auto andGate3 = new AndGate();

    auto display = new Display();


    // 2. Do Work
    andGate1->SetInputX(switchX1);
    andGate1->SetInputY(switchY1);
    andGate2->SetInputX(switchX2);
    andGate2->SetInputY(switchY2);

    andGate3->SetInputX(andGate1);
    andGate3->SetInputY(andGate2);

    display->SetInput(andGate3);


    // 3. Test
    switchX1->ChangeState(LogicState::ON);
    switchY1->ChangeState(LogicState::ON);
    switchX2->ChangeState(LogicState::ON);
    switchY2->ChangeState(LogicState::OFF);

    // Merely setting the switches should trigger the observers to update the states appropriately.
    // Nothing else should be required.

    EXPECT_EQ(display->GetState(), LogicState::OFF);

    switchY2->ChangeState(LogicState::ON);

    EXPECT_EQ(display->GetState(), LogicState::ON);

}


TEST(TestingMap, MapTest)
{
    AndGate* andGate = new AndGate();

    Display* display = new Display();

    std::unordered_map<AndGate*, Display*> map;

    //map[andGate] = display;
    map.emplace(andGate, display);

    EXPECT_EQ(map.size(), 1);
}