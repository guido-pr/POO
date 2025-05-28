#ifndef MYBETTERTIME_HPP
#define MYBETTERTIME_HPP

#include "MyTime.hpp"
#include <string>

class MyBetterTime : public MyTime {
protected:
    int seconds;

public:
    MyBetterTime(int h = 0, int m = 0, int s = 0);
    MyBetterTime(const std::string& timeStr);
    virtual std::string Time() const override;
    virtual MyTime operator+(const MyTime& other) const override;
    MyBetterTime operator+(const MyBetterTime& other) const;
    friend std::ostream& operator<<(std::ostream& os, const MyBetterTime& time);
};

#endif