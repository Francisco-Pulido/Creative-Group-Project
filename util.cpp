
#include "util.h"
#include <fstream>
#include <sstream>


vector<vector<string>> ReadCSVFile()
{
	vector<vector<string>> CSVEmissioncontent;
	vector<string> row;
	string line, word;
	fstream file("./EmissionRate.csv", ios::in); // The CSV file name is EmissionRate.csv
	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();

			stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			CSVEmissioncontent.push_back(row);
		}
	}
	else
		cout << "Could not read the EmissionRate.csv file \n";

	return CSVEmissioncontent;
}


bool SearchZipCode(const vector<vector<string>>& CSVFileEmissionContent, string zipCode, string& state, double& electricityEmissionFactor)
{
	bool isFound = false;
	const int ZIP_CODE_COL = 0, STATE_COL = 1, EMISSION_FACT_COL = 2; // column index 0 for zip code, column index 1 for state code, column index 2 for emission factor

	for (int i = 0; i < CSVFileEmissionContent.size(); i++)
	{
		if (CSVFileEmissionContent[i][ZIP_CODE_COL] == zipCode)
		{

			cout << "Zip code: " << CSVFileEmissionContent[i][ZIP_CODE_COL] << " ";
			state = CSVFileEmissionContent[i][STATE_COL];
			cout << "State: " << state << " ";
			electricityEmissionFactor = stod(CSVFileEmissionContent[i][EMISSION_FACT_COL]);
			cout << "Emission factor: " << electricityEmissionFactor << endl;
			isFound = true;
			break;
		}
	}
	return isFound;
}


int CheckValidInput(int& reduceActionOrNot, string message)
{
	cout << message;
	cin.clear();
	cin.ignore(256, '\n');  //ignore the character \n
	cin >> reduceActionOrNot;
	return 0;
}


int CheckValidInput(double& reduceActionOrNot, string message)
{
	cout << message;
	cin.clear();
	cin.ignore(256, '\n');  //ignore the character \n
	cin >> reduceActionOrNot;
	return 0;
}


int WriteSummaryReport(int totalFamilyMember, string state, string zipCode, double totalHouseholdEmissionBeforeSaving, double totalVehicleEmissionBeforeSaving, double wasteEmissionAfterRecyle, double totalHouseholdEmissionSaving, double totalVehicleEmissionSaving, double totalWasteEmissionSaving, double totalEmissionAfterSaving, int TREE_ABSORB_CO2)
{
	ofstream outFS;
	outFS.open("CarbonFootprint.txt");
	if (!outFS.is_open()) {
		cout << "Could not open file CarbonFootprint.txt." << endl;
	}

	outFS << "----Summary of Your Carbon Footprint----Annual CO2 Emissions (lbs.)----" << "\n\n";

	outFS << "Total members: " << totalFamilyMember << " State: " << state << " Zip-code: " << zipCode << "\n";
	outFS << "Carbon Emission (CO2) is from the Household Energies: " << totalHouseholdEmissionBeforeSaving << " (lbs)\n";
	outFS << "Carbon Emission (CO2) is from the Household Vehicles: " << totalVehicleEmissionBeforeSaving << " (lbs)\n";
	outFS << "Carbon Emission (CO2) is from the Household Wastes: " << wasteEmissionAfterRecyle << " (lbs)\n";
	outFS << "Current total Carbon Emission (CO2) is from the Household: " << (totalHouseholdEmissionBeforeSaving + totalVehicleEmissionBeforeSaving + wasteEmissionAfterRecyle) << " (lbs)\n";
	outFS << "Number of trees is required to absorb the total emission: " << round((totalHouseholdEmissionBeforeSaving + totalVehicleEmissionBeforeSaving + wasteEmissionAfterRecyle) / TREE_ABSORB_CO2) << "\n\n";

	outFS << "Carbon Emission (CO2) is Savings after Planning:" << endl;
	outFS << "Carbon Emission (CO2) is Savings from the Household Energies: " << totalHouseholdEmissionSaving << " (lbs)\n";
	outFS << "Carbon Emission (CO2) is Savings from the Household Vehicles: " << totalVehicleEmissionSaving << " (lbs)\n";
	outFS << "Carbon Emission (CO2) is Savings from the Household Wastes: " << totalWasteEmissionSaving << " (lbs)\n";
	outFS << "Total Carbon Emission (CO2) is from the Household: " << (totalHouseholdEmissionSaving + totalVehicleEmissionSaving + totalWasteEmissionSaving) << " (lbs)\n";
	outFS << "Total Savings are Equivalence to the number of trees: " << round((totalHouseholdEmissionSaving + totalVehicleEmissionSaving + totalWasteEmissionSaving) / TREE_ABSORB_CO2) << "\n\n";
	outFS << "New Total Carbon Emission (CO2) is after taking the saving actions: " << totalEmissionAfterSaving << " (lbs)\n";
	outFS << "Number of trees is required to absorb the new total emission: " << round((totalEmissionAfterSaving) / TREE_ABSORB_CO2) << "\n\n";

	outFS.close();

	return 0;
}