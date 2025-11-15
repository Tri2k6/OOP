#include "Vehicles.h"

Vehicles::Vehicles() {
    m_fuel = 0;
    m_weight = 0;
}

Vehicles::Vehicles(double Fuel, double Weight) {
    m_fuel = Fuel;
    m_weight = Weight;
}

Vehicles::~Vehicles() {}

void Vehicles::addFuel(double amount) {
    if (amount < 0) return;
    m_fuel += amount;
}

void Vehicles::addGoods(double weight) {
    if (weight < 0) return;
    m_weight += weight;
}

void Vehicles::removeGoods(double weight) {
    if (weight < 0) return;
    m_weight -= weight;
}

void Vehicles::removeFuel(double amount) {
    if (amount < 0) return; 
    m_fuel -= amount;
}

double Vehicles::getFuel() const {
    return m_fuel;
}

bool Vehicles::run(double Km) {
    float FuelNeed = CalcFuelConsumption(Km);
    if (m_fuel >= FuelNeed) {
        m_fuel -= FuelNeed;
        return true;
    } 
    return false;
}
