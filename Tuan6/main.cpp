#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <string>

using namespace std;

struct Company {
    string name;
    string MST;
    string address;
};
struct HashTable {
    static const int SIZE = 2000;
    list<Company> table[SIZE];
};

vector<Company> read(string file_name) {
    ifstream fin(file_name);
    vector<Company> companies;
    string line;
    getline(fin, line);

    while (getline(fin, line)) {
        Company c;
        stringstream ss(line);
        getline(ss, c.name, '|');
        getline(ss, c.MST, '|');
        getline(ss, c.address);
        companies.push_back(c);
    }
    fin.close();
    return companies;
}

long long hashString(string name) {
    const int p = 31;
    const int m = 2000;

    int start;
    if (name.size() > 20) {
        start = name.size() - 20;
    }
    else {
        start = 0;
    }

    string s = name.substr(start);

    long long hashval = 0;
    long long ppow = 1;

    for (int i = 0; i < (int)s.size(); i++) {
        hashval = (hashval + (s[i] * ppow) % m) % m;
        ppow = (ppow * p) % m;
    }
    return hashval;
}

HashTable* createHT(const vector<Company>& list) {
    HashTable* ht = new HashTable();

    for (const Company& c : list) {
        long long idx = hashString(c.name);
        ht->table[idx].push_back(c);
    }
    return ht;
}

Company* search(HashTable* hash_table, string name) {
    long long idx = hashString(name);

    for (Company& c : hash_table->table[idx]) {
        if (c.name == name) {
            return &c;
        }
    }
    return nullptr;
}

int main(int argc, char* argv[]) {

    if (argc < 4) {
        cerr <<"cach xai: ./main ./MST.txt ./input.txt ./output.txt" << endl;
        return 1;
    }

    string mst_file = argv[1];
    string input_file = argv[2];
    string output_file = argv[3];

    vector<Company> companies = read(mst_file);
    HashTable* ht = createHT(companies);

    ifstream fin(input_file);
    ofstream fout(output_file);

    string query_name;
    while (getline(fin, query_name)) {
        Company* c = search(ht, query_name);
        if (c != nullptr) {
            fout << c->name << "|" << c->MST << "|" << c->address << "\n";
        }
    }

    fin.close();
    fout.close();
    delete ht;

    return 0;
}
