#include "MyCalendar.hpp"

bool MyCalendar::addEvent(const OrderedDateTime& dt, const std::string& descricao) {
    auto result = eventos.insert({dt, descricao});
    return result.second;
}

bool MyCalendar::removeEvent(const OrderedDateTime& dt) {
    return eventos.erase(dt) > 0;
}

std::string MyCalendar::getEvent(const OrderedDateTime& dt) const {
    auto it = eventos.find(dt);
    if (it != eventos.end())
        return it->second;
    return "";
}

void MyCalendar::listEvents(std::ostream& os) const {
    for (const auto& par : eventos) {
        os << par.first << " - " << par.second << '\n';
    }
}