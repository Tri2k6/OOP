#pragma once

#include "Vehicles.h"

class Motobike : public Vehicles {
protected:
    double CalcFuelConsumption(double Km) const override;
public:
    Motobike();
    Motobike(double initFuel, double initWeight);
    ~Motobike() override;
};