
#include<iostream>
#include<fstream>
#include<string>
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
        cout<<"Read Line: "<<line<<endl;
    }

    file.close();
    
}
