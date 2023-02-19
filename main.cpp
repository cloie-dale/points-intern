#include <iostream> 
#include <fstream>
#include <string>
#include <vector>

#include "Payer.hpp"

using namespace std;

int main(int argc, char** argv) {
    string inFile = argv[2];
    if (argc != 3 ) {
        cout << "Usage: ./ points(int) filename.csv" << endl;
        return 1;
    }

    vector<Payer> payers;

    string labels;
    string payer;
    int points;
    string stamp;
    Payer curr;
    
    ifstream transaction;
    transaction.open(inFile);

    getline(transaction, labels);

    while (getline(transaction, labels)){
        int index = labels.find(',');
        payer = labels.substr(0,index);

        labels = labels.substr(index+1);
        index = labels.find(',');
        string str_points = labels.substr(0,index);
        points = stoi(str_points);

        labels = labels.substr(index+1);
        stamp = labels.substr(1,labels.size()-2);

        curr = Payer(payer, points, stamp);
        payers.push_back(curr);
        
    }

    points = atoi(argv[1]);

    for(int i = 0; i < payers.size(); i++) {
        int j = i;
        while ( j > 0 && payers.at(j-1) > payers.at(j)) {
            curr = payers.at(j-1);
            payers.at(j - 1) = payers.at(j);
            payers.at(j) = curr;
            j--;
        }
    }

    for(int i = 0; i < payers.size(); i++) {
        curr = payers.at(i);
        int j = 0;
        Payer use;
        while (curr.getPoints() < 0 && j < payers.size()) {
            use = payers.at(j);
            if (use.getPayer() == curr.getPayer() && j != i && use.getPoints() > 0) {
                if (curr.getPoints() > use.getPoints()) {
                    curr.addPoints(use.getPoints());
                    use.setPoints(0);
                }
                else {
                    use.addPoints(curr.getPoints());
                    curr.setPoints(0);
                }
                payers.at(j) = use;
            }
        }
        payers.at(i) = curr;
        j++;
    }

    for (int i = 0; points > 0 && i < payers.size(); i++) {
        curr = payers.at(i);
        int temp;
        if (curr.getPoints() != 0) {
            if (curr.getPoints() >= points) {
                curr.addPoints(-points);
                points = 0;
            } else {
                points -= curr.getPoints();
                curr.setPoints(0);
            }
        }
        payers.at(i) = curr;
    }
    if (points > 0) {
        cout << "There are not enough points to complete request." << endl;
        return 1;
    }

    vector<Payer> final_payers;

    for(int i = 0; i < payers.size(); i++) {
        curr = payers.at(i);
        bool add = true;
        for(int j = 0; j < final_payers.size(); j++) {
            Payer final_curr = final_payers.at(j);
            if(curr.getPayer() == final_curr.getPayer()) {
                add = false;
                final_curr.addPoints(curr.getPoints());
            }
            final_payers.at(j) = final_curr;
        }

        if (add) {
            final_payers.push_back(curr);
        }
    }
   
    for(int i = 0; i < final_payers.size(); i++) {
        curr = final_payers.at(i);
        if (i == final_payers.size()-1) {
            cout << curr.getPayer() << ": " << curr.getPoints() << endl;
        } else {
        cout << curr.getPayer() << ": " << curr.getPoints() << "," << endl;
        }
    }

    return 0;
}