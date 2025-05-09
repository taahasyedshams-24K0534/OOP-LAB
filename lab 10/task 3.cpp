#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    ifstream file("vehicles.txt");
    if(!file.is_open()){
        cout<<"Error: Could not open vehicles.txt"<<endl;
        return 1;
    }

    string line;
    while(getline(file,line)){
        if(line.empty()||line.substr(0,2)=="//"){
            continue;
        }

        istringstream iss(line);
        string temp,yearStr;

        getline(iss,temp,',');
        getline(iss,temp,',');
        getline(iss,temp,',');
        getline(iss,yearStr,',');

        int year=stoi(yearStr);
        cout<<"Year (as int): "<<year<<endl;
    }

    file.close();
}
