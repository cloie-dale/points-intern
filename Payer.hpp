#ifndef PAYER_HPP
#define PAYER_HPP

#include <string>
#include <fstream>


class Payer {
    public:
        Payer(ifstream);
        string getPayer();
        int getPoints();
        string getDate();
        string getTime();

    private:
        string payer;
        int points;
        string date;
        string time;

};

#endif