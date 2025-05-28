#ifndef MYTIME_HPP
#define MYTIME_HPP

#include <iostream>
#include <string>

class MyTime {
public:
    int hours;   // Hora (0-23)
    int minutes; // Minutos (0-59)

public:
    MyTime(int h = 0, int m = 0);
    virtual std::string Time() const;
    virtual MyTime operator+(const MyTime& other) const;
    friend std::ostream& operator<<(std::ostream& os, const MyTime& time);
};

#endif 