#include "Calculations.h"
#include <iostream>


double CalculateVehicleEmission(double drivenMilesPerYear, double mileagesPerGallon, const double EF_PassengerVeh, const double NonCO2VehEmissionRatio)
{
    double vehicleEmission = (drivenMilesPerYear / mileagesPerGallon) * EF_PassengerVeh * NonCO2VehEmissionRatio;
    return vehicleEmission;
}


double CalculatedEnergyEmission(double monthlyBill, const double costOfFuel, const double emissionFactor, const int totalMonth)
{
    double calculatedEmission = (monthlyBill / costOfFuel) * emissionFactor * totalMonth;
    return calculatedEmission;
}


double CalculatedWasteEmission(int numberOfPerson, const double averageWasteEmission)
{
    double calculatedWasteEmission = numberOfPerson * averageWasteEmission;
    return calculatedWasteEmission;
}


double EnergyEmissionSaving(double yearlyEnergySaving, const double emissionFactor)
{
    double calculatedEnergyEmissionSaving = yearlyEnergySaving * emissionFactor;
    return calculatedEnergyEmissionSaving;
}