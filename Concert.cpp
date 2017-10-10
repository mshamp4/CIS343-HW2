#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Concert.h"

Concert::Concert() {
        concertName = "Default";
        size_t size = 5;
        std::vector<std::string> list(size, "NULL");
        friends = list;
        desire = 0;
        time_t t;
        struct tm* date;
        time(&t);
        date = localtime(&t);
}

Concert::Concert(std::string name, std::vector<std::string> pFriends, int pDesire, std::tm* pDate) {
        concertName = name;
        friends = pFriends;
        desire = pDesire;
        date = *pDate;
}

bool Concert::operator<(const Concert& other) const {
        if (date.tm_year <  other.date.tm_year) {
                return true;
        } else if (date.tm_mon < other.date.tm_mon && date.tm_year <= other.date.tm_year) {
                return true;
        } else if (date.tm_mday < other.date.tm_mday && date.tm_mon <= other.date.tm_mon &&
                         date.tm_year <= other.date.tm_year) {
                return true;
        } else if (date.tm_year == other.date.tm_year && date.tm_mon == other.date.tm_mon &&
                         date.tm_mday == other.date.tm_mday && desire > other.desire) {
                return true;
        } else {
                return false;
        }
}

std::string friendsList(std::vector<std::string> pFriends) {
        int size = pFriends.size();
        std::string list = "";
        for (int i = 0; i < size; i++) {
                 list += pFriends.at(i) + "\n";
        }
        return list;
}

std::ostream& operator<<(std::ostream& stream, const Concert& object) {
        stream << "Concert Name: " << object.concertName << std::endl
                 << "Friend(s) list:\n" << friendsList(object.friends)
                 << "Desire: " << object.desire << std::endl << "Date: " << object.date.tm_mon
                        << "/" << object.date.tm_mday << "/" << object.date.tm_year << std::endl;
        return stream;
}
