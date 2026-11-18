#include <iostream>
#include <vector>
using namespace std;

class MangoHashTable {
    static constexpr int SIZE = 23;
    vector<int> table;

public:
    MangoHashTable() : table(SIZE, -1) {}

    int hashKey(int key) const {
        return key % SIZE;
    }

    bool insert(int key) {
        int start = hashKey(key);

        for (int step = 0; step < SIZE; ++step) {
            int index = (start + step) % SIZE;

            if (table[index] == key) {
                cout << "Duplicate key ignored\n";
                return false;
            }

            if (table[index] == -1) {
                table[index] = key;
                cout << "Insert " << key
                     << " at index " << index
                     << " after " << step
                     << " collisions\n";
                return true;
            }
        }

        cout << "Hash table full\n";
        return false;
    }
};

int main() {
    MangoHashTable hashTable;
    hashTable.insert(28);
    hashTable.insert(6);
    hashTable.insert(97);
    return 0;
}
