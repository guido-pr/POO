#include <iostream>
#include "MyCalendar.hpp"

int main() {
    MyCalendar agenda;

    OrderedDateTime dt1(7, 7, 2024, 15, 30, 0);
    OrderedDateTime dt2(8, 7, 2024, 10, 0, 0);
    OrderedDateTime dt3(7, 7, 2024, 18, 0, 0);

    agenda.addEvent(dt1, "Reunião de equipe");
    agenda.addEvent(dt2, "Consulta médica");
    agenda.addEvent(dt3, "Jantar com amigos");

    std::cout << "Eventos cadastrados:\n";
    agenda.listEvents();

    std::cout << "\nRemovendo evento das 18h...\n";
    agenda.removeEvent(dt3);

    std::cout << "\nEventos após remoção:\n";
    agenda.listEvents();

    std::cout << "\nBuscando evento das 15:30:\n";
    std::string evento = agenda.getEvent(dt1);
    if (!evento.empty())
        std::cout << evento << '\n';
    else
        std::cout << "Nenhum evento encontrado.\n";

    return 0;
}