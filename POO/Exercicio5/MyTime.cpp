#include "MyTime.hpp"
#include <iomanip>
#include <string>
#include <ostream>

MyTime::MyTime(int h, int m) : hours(h), minutes(m) {
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    if (hours >= 24) {
        hours %= 24;
    }
}

std::string MyTime::Time() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << hours << ":"
        << std::setw(2) << std::setfill('0') << minutes;
    return oss.str();
}

MyTime MyTime::operator+(const MyTime& other) const {
    int totalMinutes = (hours + other.hours) * 60 + (minutes + other.minutes);
    int newHours = (totalMinutes / 60) % 24;
    int newMinutes = totalMinutes % 60;
    return MyTime(newHours, newMinutes);
}

std::ostream& operator<<(std::ostream& os, const MyTime& time) {
    os << time.Time();
    return os;
}