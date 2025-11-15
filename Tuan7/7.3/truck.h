#pragma once

#include "Vehicles.h"

class Truck : public Vehicles {
protected:
    double CalcFuelConsumption(double km) const override;

public:
    Truck(double initialFuel = 0.0f, double initialGoods = 0.0f);

    ~Truck() override;
};