#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream outFile("config.txt");
    outFile << "AAAAABBBBBCCCCC";
    outFile.close();

    fstream file("config.txt", ios::in | ios::out);
    if (!file) {
        cout << "Failed to open config.txt" << endl;
        return 1;
    }

    file.seekp(5);
    file << "XXXXX";
    file.close();

    ifstream inFile("config.txt");
    string content;
    getline(inFile, content);
    cout << content << endl;
    inFile.close();
}
