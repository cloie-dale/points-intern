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
    
    //read in payers from transcations.csv
    ifstream transaction;
    transaction.open(inFile);

    getline(transaction, labels);

    while (getline(transaction, labels)){
        //find the first coloumn in labels and set to payer
        int index = labels.find(',');
        payer = labels.substr(0,index);

        //finds second column of labels and sets the points
        labels = labels.substr(index+1);
        index = labels.find(',');
        string str_points = labels.substr(0,index);
        points = stoi(str_points);

        //finds the third column of labels and sets timestamps
        labels = labels.substr(index+1);
        stamp = labels.substr(1,labels.size()-2);

        curr = Payer(payer, points, stamp);
        payers.push_back(curr);
        
    }

    points = atoi(argv[1]);

    // use insertion sort to sort the payers from oldest to newest
    for(int i = 0; i < payers.size(); i++) {
        int j = i;
        while ( j > 0 && payers.at(j-1) > payers.at(j)) {
            curr = payers.at(j-1);
            payers.at(j - 1) = payers.at(j);
            payers.at(j) = curr;
            j--;
        }
    }

    //find any negative transactions and pay them using the oldest positive non-zero transaction from the same payer
    for(int i = 0; i < payers.size(); i++) {
        curr = payers.at(i);
        int j = 0;
        Payer use;
        while (curr.getPoints() < 0 && j < payers.size()) {
            use = payers.at(j);
            // chacks if payer is the same, use and curr are not the same transaction, and use is a postive transaction
            if (use.getPayer() == curr.getPayer() && j != i && use.getPoints() > 0) {
                //use points does not have enough points to cover the curr transaction
                if (curr.getPoints() > use.getPoints()) {
                    curr.addPoints(use.getPoints());
                    use.setPoints(0);
                }
                //use has enough points to cover the curr transaction
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

    //pay points starting at the oldest transaction
    for (int i = 0; points > 0 && i < payers.size(); i++) {
        curr = payers.at(i);
        int temp;
        //ensures that no transaction goes below zero
        if (curr.getPoints() != 0) {
            //curr has enough points to cover the whole cost
            if (curr.getPoints() >= points) {
                curr.addPoints(-points);
                points = 0;
            } 
            //curr does not have enough points to cover the cost
            else {
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

    //finds all of the payers and adds all of the transactions for each payer together
    for(int i = 0; i < payers.size(); i++) {
        curr = payers.at(i);
        bool add = true;

        //finds transactions from the same payer and adds points
        for(int j = 0; j < final_payers.size(); j++) {
            Payer final_curr = final_payers.at(j);
            if(curr.getPayer() == final_curr.getPayer()) {
                add = false;
                final_curr.addPoints(curr.getPoints());
            }
            final_payers.at(j) = final_curr;
        }

        //adds payer to final_payer vector if they are not already in final_vector
        if (add) {
            final_payers.push_back(curr);
        }
    }
   
   //outputs each payer and their total
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