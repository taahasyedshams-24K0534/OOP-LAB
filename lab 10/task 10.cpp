
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream file("data_records.txt");
    if (!file) {
        cout << "Failed to open data_records.txt" << endl;
        return 1;
    }

    file.seekg(18, ios::beg); 
    string record;
    getline(file, record);
    cout << record << endl;

    file.close();
}
