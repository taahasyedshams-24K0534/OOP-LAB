#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    ifstream file("vehicles.txt");
    if(!file.is_open()){
        cout << "Error: Could not open vehicles.txt" << endl;
        return 1;
    }

    string line;
    while(getline(file, line)){
        if(line.empty() || line.substr(0, 2) == "//"){
            continue; 
        }

        istringstream iss(line);
        string type, id, name, yearStr, extraData, certification;
        getline(iss, type, ',');
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, yearStr, ',');
        getline(iss, extraData, ',');
        getline(iss, certification);

        if(type == "Autonomous Car"){
            size_t colonPos = extraData.find(":");
            if(colonPos != string::npos){  
                string versionStr = extraData.substr(colonPos + 1);  
                float softwareVersion = stof(versionStr); 
                cout << "Vehicle ID: " << id << ", Software Version: " << softwareVersion << endl;
            }
        }
        else if(type == "ElectricVehicle"){
            size_t colonPos = extraData.find(":");
            if(colonPos != string::npos){  
                string batteryStr = extraData.substr(colonPos + 1);  
                int batteryCapacity = stoi(batteryStr); 
                cout << "Vehicle ID: " << id << ", Battery Capacity: " << batteryCapacity << endl;
            }
        }
    }

    file.close();
}
