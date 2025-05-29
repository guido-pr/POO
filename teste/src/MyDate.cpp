#include "MyDate.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <array>

bool MyDate::formatoLongo = true;

// Construtores
MyDate::MyDate(int dia) : MyDate(dia, 1, 2000) {}
MyDate::MyDate(int dia, int mes) : MyDate(dia, mes, 2000) {}
MyDate::MyDate(int dia, int mes, int ano) {
    if (!isValidDate(ano, mes, dia)) {
        throw std::runtime_error(getErrorMessage(ano, mes, dia));
    }
    day = dia;
    month = mes;
    year = ano;
}

MyDate::MyDate(const std::string& dateStr) {
    SetDate(dateStr);
}

int MyDate::getDay() const {
    return day;
}
 
 int MyDate::getMonth() const {
 return month;
}
 
 int MyDate::getYear() const {
    return year;
}

void MyDate::SetDate(const std::string& dateStr) {
    std::istringstream iss(dateStr);
    char sep1, sep2;
    int y, m, d;

    if (!(iss >> y >> sep1 >> m >> sep2 >> d) || sep1 != '-' || sep2 != '-') {
        throw std::invalid_argument("Formato inválido. Use YYYY-MM-DD.");
    }

    if (!isValidDate(y, m, d)) {
        throw std::invalid_argument("Data inválida.");
    }

    year = y;
    month = m;
    day = d;
}

bool MyDate::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

bool MyDate::isValidDate(int y, int m, int d) const {
    if (y < 0 || m < 1 || m > 12 || d < 1) return false;

    std::array<int, 12> daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeapYear(y)) return d <= 29;

    return d <= daysInMonth[m - 1];
}

std::string MyDate::Date() const {
    if (formatoLongo) {
        static const std::string meses[12] = {
            "janeiro", "fevereiro", "março", "abril", "maio", "junho",
            "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"
        };
        std::ostringstream oss;
        oss << day << " de " << meses[month - 1] << " de " << year;
        return oss.str();
    } else {
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << day << "/"
            << std::setw(2) << std::setfill('0') << month << "/"
            << std::setw(2) << std::setfill('0') << (year % 100);
        return oss.str();
    }
}

void MyDate::SetFormatoLongo(bool longo) {
    formatoLongo = longo;
}

MyDate MyDate::operator+(const MyDate& other) const {
    int newDay = day + other.day;
    int newMonth = month + other.month;
    int newYear = year + other.year;

    // Ajusta mês e ano se necessário
    while (newMonth > 12) {
        newMonth -= 12;
        newYear++;
    }

    // Cria data e ajusta dias extras
    MyDate result(1, newMonth, newYear);
    result.addDays(newDay - 1); // começa no dia 1 e avança newDay - 1
    return result;
}

MyDate MyDate::operator+(int dias) const {
    MyDate result = *this;
    result.addDays(dias);
    return result;
}

MyDate operator+(int dias, const MyDate& data) {
    return data + dias;
}

void MyDate::addDays(int dias) {
    static const std::array<int, 12> diasPorMes = {31,28,31,30,31,30,31,31,30,31,30,31};
    day += dias;

    while (true) {
        int maxDias = diasPorMes[month - 1];
        if (month == 2 && isLeapYear(year)) maxDias = 29;

        if (day <= maxDias) break;

        day -= maxDias;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

std::string MyDate::getErrorMessage(int year, int month, int day) const {
    if (year < 0) {
        return "Ano invalido: " + std::to_string(year) + ". O ano nao pode ser negativo.";
    }
    if (month < 1 || month > 12) {
        return "Mes invalido: " + std::to_string(month) + ". O mes deve estar entre 1 e 12.";
    }
    
    if (day < 1) {
        return "Dia invalido: " + std::to_string(day) + ". O dia nao pode ser menor que 1.";
    }
    
    std::array<int, 12> daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
    int maxDay = daysInMonth[month - 1];
    if (month == 2 && isLeapYear(year)) maxDay = 29;
    
    if (day > maxDay) {
        return "Dia invalido: " + std::to_string(day) + 
               ". O mes " + std::to_string(month) + 
               " tem no maximo " + std::to_string(maxDay) + " dias" + 
               (isLeapYear(year) && month == 2 ? " (ano bissexto)" : "") + ".";
    }
    
    return "Data invalida por razao desconhecida.";
}

MyDate MyDate::DataCorretaAproximada(int dia, int mes, int ano) {
    int originalDia = dia;
    int originalMes = mes;
    int originalAno = ano;
    
    while (true) {
        try {
            return MyDate(dia, mes, ano);
        } catch (const std::runtime_error& e) {
            std::cerr << "Erro: " << e.what() << " Ajustando valores..." << std::endl;
            
            // Ajusta os valores conforme necessário
            if (dia > 28) dia--;
            else if (dia < 1) dia++;
            
            if (mes > 12) mes--;
            else if (mes < 1) mes++;
            
            if (ano > 2100) ano--;
            else if (ano < 0) ano++;
            
            // Se voltou aos valores originais (caso raro de loop infinito)
            if (dia == originalDia && mes == originalMes && ano == originalAno) {
                dia = 1; mes = 1; ano = 2000; // Valor padrão seguro
            }
        }
    }
}

void MyDate::print(std::ostream& os) const {
    os << Date();
}

std::ostream& operator<<(std::ostream& os, const MyDate& date) {
    date.print(os); // permite polimorfismo
    return os;
}
