#pragma once
#include <iostream>
#include <vector>
#include <list>

// A simple hash function for an example
int simpleHashFunction(int key, int tableSize) {
    return key % tableSize;
}

class HashTable {
public:
    HashTable(int size) {
        tableSize = size;
        table.resize(size);
    }

    void insert(int key, int value) {
        int index = simpleHashFunction(key, tableSize);
        table[index].push_back(std::make_pair(key, value));
    }

    bool search(int key, int& value) {
        int index = simpleHashFunction(key, tableSize);
        for (auto& entry : table[index]) {
            if (entry.first == key) {
                value = entry.second;
                return true;
            }
        }
        return false;
    }

    bool remove(int key) {
        int index = simpleHashFunction(key, tableSize);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return true;
            }
        }
        return false;
    }

    void print() {
        for (int i = 0; i < tableSize; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (auto& entry : table[i]) {
                std::cout << "(" << entry.first << ", " << entry.second << ") ";
            }
            std::cout << std::endl;
        }
    }

private:
    int tableSize;
    std::vector<std::list<std::pair<int, int>>> table;
};