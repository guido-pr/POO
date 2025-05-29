#include "MyBetterTime.hpp"
#include <sstream>
#include <iomanip>
#include <stdexcept>

MyBetterTime::MyBetterTime(int h, int m, int s)
    : MyTime(h, m), segundos(s) {
    normalize();
}

MyBetterTime::MyBetterTime(const std::string& timeStr) {
    char sep1, sep2;
    std::istringstream iss(timeStr);
    iss >> hours >> sep1 >> minutes >> sep2 >> segundos;

    if (sep1 != ':' || sep2 != ':' || iss.fail()) {
        throw std::invalid_argument("Formato de tempo inválido. Esperado HH:MM:SS");
    }
    normalize();
}

MyBetterTime::MyBetterTime(const MyTime& time)
    : MyTime(time), segundos(0) {
}

void MyBetterTime::normalize() {
    if (segundos >= 60 || segundos < 0 || minutes >= 60 || minutes < 0 || hours < 0) {
        int total = hours * 3600 + minutes * 60 + segundos;
        if (total < 0) total = 0;

        hours = (total / 3600) % 24;
        minutes = (total % 3600) / 60;
        segundos = total % 60;
    }
}

int MyBetterTime::getSegundos() const {
    return segundos;
}

void MyBetterTime::SetTime(const std::string& timeStr) {
    std::istringstream iss(timeStr);
    char sep1, sep2;
    int h, m, s;

    if (!(iss >> h >> sep1 >> m >> sep2 >> s) || sep1 != ':' || sep2 != ':') {
        throw std::invalid_argument("Formato inválido. Use HH:MM:SS.");
    }

    hours = h;
    minutes = m;
    segundos = s;
}

std::string MyBetterTime::Time() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << hours << ":"
        << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << segundos;
    return oss.str();
}
   
MyBetterTime MyBetterTime::operator+(const MyBetterTime& other) const {
    int total = (hours + other.hours) * 3600 +
                (minutes + other.minutes) * 60 +
                (segundos + other.segundos);
    return MyBetterTime(0, 0, total);
}

MyBetterTime MyBetterTime::operator+(int segundos) const {
    int total = hours * 3600 + minutes * 60 + this->segundos + segundos;
    return MyBetterTime(0, 0, total);
}

void MyBetterTime::print(std::ostream& os) const {
    os << Time();
}

std::ostream& operator<<(std::ostream& os, const MyBetterTime& time) {
    time.print(os); // permite polimorfismo
    return os;
}
