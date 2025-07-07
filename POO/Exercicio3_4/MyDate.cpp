#include "MyDate.hpp"
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>

// Função auxiliar para verificar se o ano é bissexto
bool MyDate::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Função auxiliar para validar a data
bool MyDate::isValidDate(int year, int month, int day) const {
    if (month < 1 || month > 12 || day < 1) {
        return false;
    }

    // Dias máximos em cada mês
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Ajustar fevereiro para anos bissextos
    if (month == 2 && isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    return day <= daysInMonth[month - 1];
}

// Construtor que recebe uma string no formato "YYYY-MM-DD"
MyDate::MyDate(const std::string& date) {
    SetDate(date); // Delegar para o método SetDate
}

// Método para alterar a data
void MyDate::SetDate(const std::string& date) {
    // Verificar o formato da string
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        throw std::invalid_argument("Formato invalido! Use 'YYYY-MM-DD'.");
    }

    // Extrair ano, mês e dia da string
    int y, m, d;
    char separator1, separator2;
    std::istringstream iss(date);
    if (!(iss >> y >> separator1 >> m >> separator2 >> d) || separator1 != '-' || separator2 != '-') {
        throw std::invalid_argument("Formato invalido! Use 'YYYY-MM-DD'.");
    }

    // Validar a data
    if (!isValidDate(y, m, d)) {
        throw std::invalid_argument("Data invalida!");
    }

    // Atribuir os valores
    year = y;
    month = m;
    day = d;
}

// Método para retornar a data por extenso
std::string MyDate::Date() const {
    const std::string months[] = {
        "janeiro", "fevereiro", "março", "abril", "maio", "junho",
        "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"
    };

    std::ostringstream oss;
    
    if (formatoLongo) {
        oss << day << " de " << months[month - 1] << " de " << year;
    } else {
        oss << year << "-"
            << (month < 10 ? "0" : "") << month << "-"
            << (day < 10 ? "0" : "") << day;
    }
    // Faltava este fechamento
    return oss.str();
}

// Métodos para obter os valores individuais
int MyDate::GetDay() const {
    return day;
}

int MyDate::GetMonth() const {
    return month;
}

int MyDate::GetYear() const {
    return year;
}

bool MyDate::GetFormatoLongo() const {
    return formatoLongo;
}

void MyDate::SetFormatoLongo(bool longo) {
    formatoLongo = longo;
}

MyDate MyDate::operator+(int dias) const {
    int d = GetDay() + dias;
    int m = GetMonth();
    int y = GetYear();

    std::ostringstream oss;
    oss << y << "-"
        << (m < 10 ? "0" : "") << m << "-"
        << (d < 10 ? "0" : "") << d;

    if (!isValidDate(y, m, d)) {
        throw std::invalid_argument("Data invalida!");
    }
    return MyDate(oss.str());
}

MyDate MyDate::operator+(const MyDate& other) const {
    int new_day = GetDay() + other.GetDay();
    int new_month = GetMonth() + other.GetMonth();
    int new_year = GetYear() + other.GetYear();

    std::ostringstream oss;
    oss << new_year << "-"
        << (new_month < 10 ? "0" : "") << new_month << "-"
        << (new_day < 10 ? "0" : "") << new_day;
        
    if (!isValidDate(new_year, new_month, new_day)) {
        throw std::invalid_argument("Data invalida!");
    }

    return MyDate(oss.str());
}

std::ostream& operator<<(std::ostream& os, const MyDate& date) {
    os << date.Date();
    return os;
}
