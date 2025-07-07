#include "OrderedDateTime.hpp"
#include <tuple>

OrderedDateTime::OrderedDateTime(int day, int month, int year, int hour, int minute, int second)
    : MyDateTime(day, month, year, hour, minute, second) {}

bool OrderedDateTime::operator<(const OrderedDateTime& other) const {
    if (getYear() != other.getYear()) 
        return getYear() < other.getYear();
    
    if (getMonth() != other.getMonth()) 
        return getMonth() < other.getMonth();

    if (getDay() != other.getDay()) 
        return getDay() < other.getDay();

    if (getHoras() != other.getHoras()) 
        return getHoras() < other.getHoras();

    if (getMinutos() != other.getMinutos()) 
        return getMinutos() < other.getMinutos();

    return getSegundos() < other.getSegundos();
}
