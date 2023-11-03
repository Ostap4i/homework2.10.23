#include <iostream>
#include "HashTablh.h"
using namespace std;

int main() {

    HashTable hashTable(10);

    hashTable.insert(1, 42);
    hashTable.insert(2, 17);
    hashTable.insert(11, 99);

    hashTable.print();

    int value;
    if (hashTable.search(2, value)) {
      cout << "Key 2 found, value: " << value << endl;
    }
    else {
    cout << "Key 2 not found" << endl;
    }

    if (hashTable.remove(2)) {

        cout << "Key 2 removed" << endl;
    }
    else {
        cout << "Key 2 not found for removal" << endl;
    }

    hashTable.print();

    return 0;

}


