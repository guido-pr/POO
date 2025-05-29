#ifndef MYDATETIME_HPP
#define MYDATETIME_HPP

#include "MyDate.hpp"
#include "MyBetterTime.hpp"
#include <string>
#include <ostream>

class MyDateTime : public MyDate, public MyBetterTime {
public:
    MyDateTime(int day, int month, int year, int hour = 0, int minute = 0, int second = 0);
    MyDateTime(const std::string& datetimeStr);
    std::string DateTime() const;
    friend std::ostream& operator<<(std::ostream& os, const MyDateTime& dt);
    MyDateTime operator+(const MyDateTime& other) const;
    MyDateTime operator+(int value) const;
    using MyDate::operator+;
};

#endif