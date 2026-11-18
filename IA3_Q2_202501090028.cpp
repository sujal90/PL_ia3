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
};

int main() {
    MangoHashTable hashTable;
    cout << "Mango hash table initialized with 23 slots\n";
    cout << "Division hash test for key 97: " << hashTable.hashKey(97) << '\n';
    return 0;
}
