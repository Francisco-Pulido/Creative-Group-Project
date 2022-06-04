#include <iostream>
#include <vector>
#include <string>
using namespace std;


//This function reads the CSV file. The CSV file contains the zip code, state code, and electricity emission factor for different zip codes
vector<vector<string>> ReadCSVFile();


/*This function search the user zip code from the CSV file contents. The vector of CSV file is very large over 41000 elements, therefore,
*it is passed as a reference and here the vector will not modify just search over it so it is a const reference. If the zip code is found then return true, otherwise it will
*return false.  Also, the function will set the value for state code and electricity emission factor as  reference parameters that
*can be accessed it from main function or from  where it call.
*/
bool SearchZipCode(const vector<vector<string>>& CSVFileEmissionContent, 
	string zipCode, string& state, double& electricityEmissionFactor);


//Below two functions checks the validity of userInput
int CheckValidInput(double& reduceActionOrNot, string message);
int CheckValidInput(int& reduceActionOrNot, string message);


/*This function writes the summary report of carbon footprint in a text file for a household. The function writes the summary a text file
*that name is CarbonFootPrintReport.txt. The function inputs parameters are helped to prepare the summary report. The inputs parameters
*are total family member, state code, zip code, total household energy emission, total vehicle emission, total waste emission,
*emission saving from the household energy, energy saving from vehicle, energy saving from waste, total emission after savings,
*how much emission a tree can absorb per year.
*/
int WriteSummaryReport(int totalFamilyMember, string state, string zipCode,
	double totalHouseholdEmissionBeforeSaving, double totalVehicleEmissionBeforeSaving,
	double wasteEmissionAfterRecyle, double totalHouseholdEmissionSaving, double totalVehicleEmissionSaving,
	double totalWasteEmissionSaving, double totalEmissionAfterSaving, int TREE_ABSORB_CO2);