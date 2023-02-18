#include <iostream>
#include <fstream>
#include <string>

#include "Payer.hpp"

using namespace std;

Payer::Payer(ifstream transaction) {
    string temp;
    transaction >> temp;
    payer = temp;

    int point;
    transcation >> point;
    points = point;

    transaction >> temp;
    int index = temp.find('T');

    date = temp.substr(0,index);
    time = temp.substr(index);
}

string Payer::getPayer() {
    return payer;
}

int Payer::getPoints() {
    return points;
}

string Payer::getDate() {
    return date;
}

string Payer::getTime() {
    return time;
}