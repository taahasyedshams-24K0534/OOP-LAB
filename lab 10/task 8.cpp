#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("config.txt");
    outFile << "AAAAABBBBBCCCCC";
    outFile.close();

    fstream file("config.txt", ios::in | ios::out);
    file.seekp(5);
    file << "XXXXX";
    file.close();

    ifstream inFile("config.txt");
    string content;
    getline(inFile, content);
    cout << content << endl;
    inFile.close();

    return 0;
}
