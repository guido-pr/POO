#include "MyTime.hpp"
#include <iomanip>
#include <sstream>

MyTime::MyTime(int h, int m) : hours(h), minutes(m) {
    normalize();
}

void MyTime::normalize() {
    if (minutes >= 60 || minutes < 0 || hours < 0) {
        int totalMinutes = hours * 60 + minutes;
        if (totalMinutes < 0) totalMinutes = 0;

        hours = (totalMinutes / 60) % 24;
        minutes = totalMinutes % 60;
    }
}

std::string MyTime::Time() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << hours << ":"
        << std::setw(2) << std::setfill('0') << minutes;
    return oss.str();
}

// Implementação dos métodos getters
int MyTime::getHoras() const {
    return hours;
}
   
int MyTime::getMinutos() const {
    return minutes;
}

MyTime MyTime::operator+(const MyTime& other) const {
    int totalMinutes = (hours + other.hours) * 60 + minutes + other.minutes;
    return MyTime(0, totalMinutes); // o construtor já normaliza
}

void MyTime::print(std::ostream& os) const {
    os << Time();
}

std::ostream& operator<<(std::ostream& os, const MyTime& time) {
    time.print(os); // permite polimorfismo
    return os;
}

MyTime::~MyTime() {}
