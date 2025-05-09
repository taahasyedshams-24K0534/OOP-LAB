#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file("sensor_log.txt");
    if (!file) {
        cout << "Failed to open file." << endl;
        return 1;
    }

    file << "Sensor1: 25.3C\n";
    streampos pos1 = file.tellp();
    cout << "Write position after 1st line: " << pos1 << endl;

    file << "Sensor2: 26.1C\n";
    streampos pos2 = file.tellp();
    cout << "Write position after 2nd line: " << pos2 << endl;

    file.close();
}
