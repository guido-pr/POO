#include "MyDateTime.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

MyDateTime::MyDateTime(int day, int month, int year, int hour, int minute, int second)
    : MyDate(day, month, year), MyBetterTime(hour, minute, second) {
}

MyDateTime::MyDateTime(const std::string& datetimeStr) 
: MyDate("2000-01-01"), MyBetterTime(0, 0, 0) {
    std::istringstream iss(datetimeStr);
    std::string dateStr, timeStr;
    iss >> dateStr >> timeStr;
    
    if (iss.fail()) {
        throw std::invalid_argument("Formato inválido. Use YYYY-MM-DD HH:MM:SS");
    }
    
    MyDate::SetDate(dateStr);    
    MyBetterTime::SetTime(timeStr); 
}

std::string MyDateTime::DateTime() const {
    std::ostringstream oss;
    oss << std::setfill('0') 
        << std::setw(4) << getYear() << "-"
        << std::setw(2) << getMonth() << "-"
        << std::setw(2) << getDay() << " "
        << std::setw(2) << getHoras() << ":"
        << std::setw(2) << getMinutos() << ":"
        << std::setw(2) << getSegundos();
    return oss.str();
}

MyDateTime MyDateTime::operator+(const MyDateTime& other) const {
    MyDate newDate = MyDate::operator+(other);            // soma datas
    MyBetterTime newTime = MyBetterTime::operator+(other); // soma tempos

    return MyDateTime(newDate.getDay(), newDate.getMonth(), newDate.getYear(),
                      newTime.getHoras(), newTime.getMinutos(), newTime.getSegundos());
}

MyDateTime MyDateTime::operator+(int value) const {
    // Valor inteiro soma dias, por padrão
    MyDate newDate = MyDate::operator+(value);
    return MyDateTime(newDate.getDay(), newDate.getMonth(), newDate.getYear(),
                      getHoras(), getMinutos(), getSegundos());
}

std::ostream& operator<<(std::ostream& os, const MyDateTime& dt) {
    os << dt.DateTime();
    return os;
}

MyDateTime::~MyDateTime() {}
