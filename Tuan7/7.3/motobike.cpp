#include "motobike.h"

double Motobike::CalcFuelConsumption(double Km) const {
    double baseRate = 2.0; 
    double addRate = (m_weight / 10.0) * 0.1;
    double totalRate = baseRate + addRate;

    return (Km / 100.0) * totalRate;
}

Motobike::Motobike() : Vehicles()  {}

Motobike::Motobike(double initFuel, double initWeight) : Vehicles(initFuel, initWeight) {}

Motobike::~Motobike(){}