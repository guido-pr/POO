#ifndef MYTIME_HPP
#define MYTIME_HPP

#include <string>
#include <ostream>

class MyTime {
protected:
    int hours;
    int minutes;

    void normalize(); // Ajusta horas e minutos para estarem dentro dos limites

public:
    MyTime(int h = 0, int m = 0);

    int getHoras() const;
    int getMinutos() const;

    virtual std::string Time() const; 

    virtual MyTime operator+(const MyTime& other) const; 
    
    virtual void print(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const MyTime& time);

    virtual ~MyTime();
};

#endif
