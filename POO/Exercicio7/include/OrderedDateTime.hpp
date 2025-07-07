#ifndef ORDEREDDATETIME_HPP
#define ORDEREDDATETIME_HPP

#include "MyDateTime.hpp"

class OrderedDateTime : public MyDateTime {
public:
    OrderedDateTime(int day, int month, int year, int hour = 0, int minute = 0, int second = 0);

    bool operator<(const OrderedDateTime& other) const;
};

#endif
