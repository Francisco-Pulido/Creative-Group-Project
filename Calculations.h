#include <string>
#include <vector>


/*This function calculates the vehicle emission, and how much emission can be saved from the vechicle. The input parameters of this
*function are total driven mileages per year, mileages per gallon, emission factor of passenger vehicle, and Non-CO2 vehicle emission
*ratio. The vehicle emission is calculated by the following formula:
*Vehicle Emission = (total driven mileages per year/mileages per gallon) * emission factor of passenger vehicle * Non-CO2 vehicle emission ratio.
*All calculated equations were extracted from the EPA excel sheet. The function returns the vehicle emission per year.
*/
double CalculateVehicleEmission(double drivenMilesPerYear, double mileagesPerGallon, const double EF_PassengerVeh, const double NonCO2VehEmissionRatio);


/*This function calculates the household energy emission, the energy was calculated the monthly bills of various energy consumption.
*The input parameters of the function are monthly bill, cost of fuel, emission factor, and total month of a year.
*The energy emission is calculated by the following formula:
*Energy emission = (monthly bill / cost of fuel) * emission factor * total month of a year.
*The function returns the calculated energy emission equivalence to CO2 (lbs) per year.
*/
double CalculatedEnergyEmission(double monthlyBill, const double costOfFuel, const double emissionFactor, const int totalMonth);


/*This function calculated the waste emission calculation. The waste emission was calculated from the number of household persons.
*The input parameters of the function are number of persons of a household and average waste emission.
*The calculated waste emission was calculated from the following equation:
*Waste Emission = number of persons * average waste emission.
*The function returns the calculated waste emission equivalence to CO2 (lbs) per year.
*/
double CalculatedWasteEmission(int numberOfPerson, const double averageWasteEmission);


/*This function calculated the saving emission from household energy resources. The input parameters of the function are plan for yearly
*energy saving and electric emission factor for the specific zip code. The saving energy is calculated from the following equation:
*Emission Saving = yearly energy saving * electric emission factor.
*The function returns the calculated energy saving equivalence to CO2 (lbs) per year.
*/
double EnergyEmissionSaving(double yearlyEnergySaving, const double emissionFactor);