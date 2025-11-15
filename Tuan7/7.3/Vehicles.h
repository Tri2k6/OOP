#pragma once

class Vehicles {
protected:    
    double m_fuel;
    double m_weight;
    virtual double CalcFuelConsumption(double Km) const = 0;
public:
    Vehicles();
    Vehicles(double Fuel, double Weight);
    virtual ~Vehicles();

    void addFuel(double amount);
    void removeFuel(double amount);

    void addGoods(double weight);
    void removeGoods(double weight);

    double getFuel() const;
    
    virtual bool run(double Km);
};