#ifndef MYBETTERTIME_HPP
#define MYBETTERTIME_HPP

#include "MyTime.hpp"
#include <string>

class MyBetterTime : public MyTime {
protected:
    int segundos;

    void normalize(); // Ajusta os valores para intervalo válido

public:
    MyBetterTime(const MyTime& time);
    MyBetterTime(int h = 0, int m = 0, int s = 0);
    MyBetterTime(const std::string& timeStr);

    int getSegundos() const;
    void SetTime(const std::string& timeStr);

    virtual std::string Time() const override;
    virtual MyBetterTime operator+(const MyBetterTime& other) const;
    MyBetterTime operator+(int segundos) const;

    virtual void print(std::ostream& os) const override;
    friend std::ostream& operator<<(std::ostream& os, const MyBetterTime& time);
};

#endif
