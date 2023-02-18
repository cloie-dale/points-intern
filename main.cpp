#include <iostream>
#include <fstream>
#include <string>

#include "Payer.hpp"

using namespace std;


int main(int argc, char** argv) {
    string inFile = argv[2];
    if (argc != 3 ) {
        cout << "Usage: ./ points(int) filename.csv" << endl;
        return 1;
    }

    ifstream transactions;
    transations.open(inFile);

    Payer* payers = new Payer(transactions);

    for(int i = 1; !transactions.fail(); i++) {
        payers[i] = Payer(transactions);
    }

    delete[] payers;

    return 0;
}