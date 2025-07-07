#ifndef MYCALENDAR_HPP
#define MYCALENDAR_HPP

#include <map>
#include <string>
#include <iostream>
#include "OrderedDateTime.hpp"

class MyCalendar {
private:
    std::map<OrderedDateTime, std::string> eventos;

public:
    bool addEvent(const OrderedDateTime& dt, const std::string& descricao);
    bool removeEvent(const OrderedDateTime& dt);
    std::string getEvent(const OrderedDateTime& dt) const;
    void listEvents(std::ostream& os = std::cout) const;
};
#endif 