#ifndef MYDATE_HPP
#define MYDATE_HPP

#include <string>
#include <ostream>

class MyDate {
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int year) const;
    bool isValidDate(int year, int month, int day) const;
    void addDays(int dias);

    static bool formatoLongo;
    std::string getErrorMessage(int year, int month, int day) const;
public:
    // Construtores
    MyDate(int dia);
    MyDate(int dia, int mes);
    MyDate(int dia, int mes, int ano);
    MyDate(const std::string& dateStr);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Métodos principais
    void SetDate(const std::string& dateStr);
    std::string Date() const;

    // Formato
    static void SetFormatoLongo(bool longo);

    // Operadores de soma
    MyDate operator+(const MyDate& other) const;
    MyDate operator+(int dias) const;

    // Operador amigo para int + MyDate
    friend MyDate operator+(int dias, const MyDate& data);

    virtual void print(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const MyDate& date);
    static MyDate DataCorretaAproximada(int dia, int mes, int ano);
};

#endif
