#ifndef DATE_H_
#define DATE_H_
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Date {
        int month {01}, 
            day {01},
            year {1900};
        
    public:
        string static const MONTHS[12];

        Date() = default;
        Date(int m, int d, int y) : 
            month{m}, day{d}, year{y} {}

        void setMonth(int m);
        void setDay(int d);
        void setYear(int y);

        const int getMonth();
        const int getDay();
        const int getYear();

        string print();

        static bool compare(const Date, const Date);

};

#endif