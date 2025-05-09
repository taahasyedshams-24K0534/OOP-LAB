#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    ifstream file("vehicles.txt");
    if(!file.is_open()){
        cerr<<"Error: Could not open vehicles.txt"<<endl;
        return 1;
    }

    string line;
    while(getline(file,line)){
        if(line.empty()||line.substr(0,2)=="//"){
            continue;
        }

        istringstream iss(line);
        string type,id,name,year,extraData,certification;

        getline(iss,type,',');
        getline(iss,id,',');
        getline(iss,name,',');
        getline(iss,year,',');
        getline(iss,extraData,',');
        getline(iss,certification);

        cout<<"Type: "<<type<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Year: "<<year<<endl;
        cout<<"ExtraData: "<<extraData<<endl;
        cout<<"Certification: "<<certification<<endl;
        cout<<endl;
    }

    file.close();
}
