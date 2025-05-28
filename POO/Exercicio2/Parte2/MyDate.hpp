#ifndef MYDATE_HPP
#define MYDATE_HPP

#include <string>

class MyDate {
private:
    int day;
    int month;
    int year;
    bool isLeapYear(int year) const;
    bool isValidDate(int year, int month, int day) const;
public:
    MyDate(const std::string& date);
    void SetDate(const std::string& date);
    std::string Date() const;
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;
};

#endif