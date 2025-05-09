#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile("large_log.txt");
    outFile << "This is a sample log file containing multiple lines of data.";
    outFile.close();

    ifstream inFile("large_log.txt");
    char buffer[11] = {};

    inFile.read(buffer, 10);
    cout << buffer << endl;
    cout << inFile.tellg() << endl;

    inFile.read(buffer, 10);
    cout << buffer << endl;
    cout << inFile.tellg() << endl;

    inFile.close();
}
