
#include "Payer.hpp"

using namespace std;

Payer::Payer(string name, int point, string stamp) {
    payer = name;

    points = point;
    
    int index = stamp.find('T');

    date = stamp.substr(0,index);
    time = stamp.substr(index);
}

bool Payer::operator>(Payer rhs) {
    if(this->date > rhs.getDate()) return true;
    if(this->date == rhs.getDate() && this->time > rhs.getTime()) return true;
    return false;
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

void Payer::setPoints(int new_points) {
    points = new_points;
}

void Payer::addPoints(int new_points) {
    this->points += new_points;
}