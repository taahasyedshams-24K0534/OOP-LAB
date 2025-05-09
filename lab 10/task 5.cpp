#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main() {
    ifstream file("vehicles.txt");

    if (!file.is_open()) {
        cout << "Error: Could not open vehicles.txt" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line.substr(0, 2) == "//") {
            continue; 
        }

        istringstream stream(line);
        string vehicleType, vehicleID, vehicleName, yearStr, extraData, certification;
        getline(stream, vehicleType, ',');
        getline(stream, vehicleID, ',');
        getline(stream, vehicleName, ',');
        getline(stream, yearStr, ',');
        getline(stream, extraData, ',');
        getline(stream, certification);

        if (vehicleType == "Autonomous Car") {
            size_t colPos = extraData.find(":");
            if (colPos != string::npos) {
                string softwareVersionStr = extraData.substr(colPos + 1);
                float softwareVersion = stof(softwareVersionStr);
                cout << "Vehicle ID: " << vehicleID << ", Software Version: " << softwareVersion << endl;
            }
        }
        else if (vehicleType == "ElectricVehicle") {
            size_t colPos = extraData.find(":");
            if (colPos != string::npos) {
                string batteryCapacityStr = extraData.substr(colPos + 1);
                int batteryCapacity = stoi(batteryCapacityStr); 
                cout << "Vehicle ID: " << vehicleID << ", Battery Capacity: " << batteryCapacity << endl;
            }
        }
        else if (vehicleType == "Hybrid Truck") {
            size_t colPos = extraData.find(":");
            size_t pipePos = extraData.find("|");

            if (colPos != string::npos && pipePos != string::npos) {
                string cargoStr = extraData.substr(colPos + 1, pipePos - colPos - 1);
                int cargoCapacity = stoi(cargoStr); 

                string batteryStr = extraData.substr(pipePos + 1);
                int batteryCapacity = stoi(batteryStr); 

                cout << "Vehicle ID: " << vehicleID << ", Cargo Capacity: " << cargoCapacity
                     << ", Battery Capacity: " << batteryCapacity << endl;
            }
        }
        else {
            cout << "Unknown vehicle type: " << vehicleType << endl;
        }
    }

    file.close();
}
