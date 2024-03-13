//
// Created by John on 3/12/2024.
//
#include <Switch/Switch.hpp>
#include <LogicGates/AndGate/AndGate.hpp>

int main()
{
    auto switchX1 = new Switch();
    auto switchY1 = new Switch();
    auto switchX2 = new Switch();
    auto switchY2 = new Switch();
    auto andGate1 = new AndGate();
    auto andGate2 = new AndGate();

    auto andGate3 = new AndGate();

    switchX1->ChangeState(true);
    switchY1->ChangeState(true);
    switchX2->ChangeState(true);
    switchY2->ChangeState(false);

    andGate1->SetInputX(switchX1);
    andGate1->SetInputY(switchY1); // Output is 1

    andGate2->SetInputX(switchX2);
    andGate2->SetInputY(switchY2); // Output is 1

    andGate3->SetInputX(andGate1);
    andGate3->SetInputY(andGate2); // Output should be 1



    std::cout << "The state of the and gate is: " << andGate3->GetState() << std::endl;

}