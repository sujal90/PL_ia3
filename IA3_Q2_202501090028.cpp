#include <iostream>
#include <iomanip>
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
    MangoHashTable hashTable;
    hashTable.insert(28);
    hashTable.insert(6);
    hashTable.insert(97);
    hashTable.insert(97);
    hashTable.display();
    cout << "\nSearch Mango-97: " << hashTable.search(97) << '\n';
    cout << "Search Mango-99: " << hashTable.search(99) << " (-1 means absent)\n";
    return 0;
}
