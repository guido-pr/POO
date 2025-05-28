#ifndef MYDATE_HPP
#define MYDATE_HPP

#include <string>
#include <ostream>

class MyDate {
private:
    int day;
    int month;
    int year;
    bool formatoLongo;
    bool isLeapYear(int year) const;
    bool isValidDate(int year, int month, int day) const;
public:
    MyDate(int day, int month, int year);
    MyDate(const std::string& date);
    void SetDate(const std::string& date);
    std::string Date() const;
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;
    bool GetFormatoLongo() const;
    void SetFormatoLongo(bool longo);
    MyDate operator+(int dias) const;
    MyDate operator+(const MyDate& other) const;
    friend std::ostream& operator<<(std::ostream& os, const MyDate& date);
};

#endif