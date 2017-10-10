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
        sDate = asctime(date);
}

Concert::Concert(std::string name, std::vector<std::string> pFriends, int pDesire, std::tm* pDate) {
        concertName = name;
        friends = pFriends;
        desire = pDesire;
        date = *pDate;
        sDate = asctime(pDate);
}

bool Concert::operator<(const Concert& other) const {
        time_t time1, time2;
        struct tm* d1, d2;
        const char* date1 = sDate.c_str();
        strptime(date1, "%b %d %Y", d1);
        strptime(date2, "%b %d %Y", &d2);
        time1 = mktime(d1);
        time2 = mktime(&d2);
        double timeDiff = difftime(time1, time2);
        if ((int)timeDiff > 0 && desire > other.desire) {
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
                 << "Desire: " << object.desire << std::endl << "Date: " << object.sDate;
        return stream;
}
