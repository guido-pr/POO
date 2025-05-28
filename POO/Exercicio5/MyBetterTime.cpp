#include "MyBetterTime.hpp"
#include <sstream>
#include <iomanip>
#include <stdexcept>

MyBetterTime::MyBetterTime(int h, int m, int s) : MyTime(h, m), seconds(s) {
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    if (hours >= 24) {
        hours %= 24;
    }
}

MyBetterTime::MyBetterTime(const std::string& timeStr) {
    std::istringstream iss(timeStr);
    char colon1, colon2;
    if (!(iss >> hours >> colon1 >> minutes >> colon2 >> seconds) || colon1 != ':' || colon2 != ':') {
        throw std::invalid_argument("Invalid time format. Expected hh:mm:ss");
    }

    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    if (hours >= 24) {
        hours %= 24;
    }
}

std::string MyBetterTime::Time() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << hours << ":"
        << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << seconds;
    return oss.str();
}

MyTime MyBetterTime::operator+(const MyTime& other) const {
    std::string otherTime = other.Time(); 

    int otherHours, otherMinutes, otherSeconds = 0; 
    char colon1, colon2;

    std::istringstream iss(otherTime);
    if (!(iss >> otherHours >> colon1 >> otherMinutes)) {
        throw std::invalid_argument("Invalid time format in other object.");
    }

    if (colon1 == ':' && iss >> colon2 && colon2 == ':' && iss >> otherSeconds) {}

    int totalSeconds = (hours + otherHours) * 3600 +
                        (minutes + otherMinutes) * 60 +
                        (seconds + otherSeconds);

    int newHours = (totalSeconds / 3600) % 24;
    int newMinutes = (totalSeconds / 60) % 60;
    int newSeconds = totalSeconds % 60;

    return MyBetterTime(newHours, newMinutes, newSeconds);
}

MyBetterTime MyBetterTime::operator+(const MyBetterTime& other) const {
    int totalSeconds = hours * 3600 + minutes * 60 + seconds +
                       other.hours * 3600 + other.minutes * 60 + other.seconds;
    int newHours = (totalSeconds / 3600) % 24;
    int newMinutes = (totalSeconds / 60) % 60;
    int newSeconds = totalSeconds % 60;
    return MyBetterTime(newHours, newMinutes, newSeconds);
}

std::ostream& operator<<(std::ostream& os, const MyBetterTime& time) {
    os << time.Time();
    return os;
}