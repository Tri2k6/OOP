#include "truck.h"

double Truck::CalcFuelConsumption(double Km) const {
    double baseRate = 20.0;
    double addRate = (m_weight / 1000.0);
    double totalRate = baseRate + addRate;
    return (Km / 100.0) * totalRate;
}

Truck::Truck(double initFuel, double initWeight) : Vehicles(initFuel, initWeight) {}

Truck::~Truck() {}