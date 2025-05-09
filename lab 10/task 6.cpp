#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class InventoryItem {
private:
    int itemID;
    char itemName[20];

public:
    InventoryItem(int id = 0, const char* name = "") {
        itemID = id;
        strncpy(itemName, name, sizeof(itemName) - 1);
        itemName[sizeof(itemName) - 1] = '\0';
    }

    int getItemID() const {
        return itemID;
    }

    const char* getItemName() const {
        return itemName;
    }

    void writeToFile(const char* filename) const {
        ofstream outFile(filename, ios::binary);
        if (!outFile) {
            cout << "Error opening file for writing!" << endl;
            return;
        }
        outFile.write(reinterpret_cast<const char*>(this), sizeof(InventoryItem));
        outFile.close();
    }

    void readFromFile(const char* filename) {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cout << "Error opening file for reading!" << endl;
            return;
        }
        inFile.read(reinterpret_cast<char*>(this), sizeof(InventoryItem));
        inFile.close();
    }

    void printItem() const {
        cout << "Item ID: " << itemID << endl;
        cout << "Item Name: " << itemName << endl;
    }
};

int main() {
    InventoryItem item1(101, "ItemOne");
    item1.writeToFile("inventory.dat");

    InventoryItem item2;
    item2.readFromFile("inventory.dat");

    cout << "Loaded Inventory Item:" << endl;
    item2.printItem();

}
