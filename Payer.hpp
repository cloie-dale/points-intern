#ifndef PAYER_HPP
#define PAYER_HPP

#include <string>

using namespace std;

class Payer {
    public:
        Payer(string name, int point, string stamp);
        Payer() {
            payer = "";
            points = 0;
            date = "";
            time = "";
        }
        bool operator>(Payer rhs);
        string getPayer();
        int getPoints();
        string getDate();
        string getTime();
        void setPoints(int new_points);
        void addPoints(int new_points);

    private:
        string payer;
        int points;
        string date;
        string time;

};

#endif