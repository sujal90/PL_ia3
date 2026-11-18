#include <iostream>
#include <vector>
using namespace std;

class MangoHashTable {
    static constexpr int SIZE = 23;
    vector<int> table;

public:
    MangoHashTable() : table(SIZE, -1) {}
};

int main() {
    MangoHashTable hashTable;
    cout << "Mango hash table initialized with 23 slots\n";
    return 0;
}
