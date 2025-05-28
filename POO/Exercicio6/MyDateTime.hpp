#ifndef MYDATETIME_HPP
#define MYDATETIME_HPP

#include "MyBetterTime.hpp"
#include "MyDate.hpp"
#include <string>

class MyDateTime : public MyDate, public MyBetterTime {
public:
    MyDateTime(int day, int month, int year, int h, int m, int s);
    MyDateTime(const std::string& datetimeStr);
    std::string DateTime() const;
};

#endif