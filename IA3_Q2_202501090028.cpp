// Data Structures - Internal Activity 3, Question 2
// PRN: 202501090028
// Seed S = 28; Scenario = Mango varieties (PRN % 3 = 2)
// Dataset: v[i] = (28 + 13*i) % 100, i = 0..19
// Hash: division method; collision resolution: linear probing
// Table size 23 is a documented implementation choice.
#include <iostream>
#include <iomanip>
#include <string>
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

    int search(int key) const {
        int start = hashKey(key);

        for (int step = 0; step < SIZE; ++step) {
            int index = (start + step) % SIZE;
            if (table[index] == -1) return -1;
            if (table[index] == key) return index;
        }

        return -1;
    }

    void display() const {
        cout << "\nIndex | Variety code | Label\n";
        cout << "-----------------------------\n";
        for (int i = 0; i < SIZE; ++i) {
            cout << setw(5) << i << " | ";
            if (table[i] == -1) cout << "Empty\n";
            else cout << setw(12) << table[i] << " | Mango-" << table[i] << '\n';
        }
    }
};

int main() {
    constexpr long long PRN = 202501090028LL;
    constexpr int SEED = static_cast<int>(PRN % 10000);
    cout << "PRN: " << PRN << "\nScenario: Mango varieties\n";
    cout << "Seed: " << SEED << " | Table size: 23 | Division hashing + linear probing\n\n";

    MangoHashTable hashTable;
    for (int i = 0; i < 20; ++i) {
        int key = (SEED + 13 * i) % 100;
        hashTable.insert(key);
    }

    hashTable.display();
    cout << "\nSearch Mango-97: " << hashTable.search(97) << '\n';
    cout << "Search Mango-99: " << hashTable.search(99) << " (-1 means absent)\n";
    return 0;
}
