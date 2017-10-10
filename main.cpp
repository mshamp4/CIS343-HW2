#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "Concert.h"

std::tm* randomDate();

std::string friendNames[15] = {"Kevin", "Mark", "Matt", "Kyle", "Steven", "Taylor", "Tom",
                                "Chris", "Tyler", "Emily", "Morgan", "Kylie", "Peter", "Parker", "Janet"};

std::string concerts[15] = {"Ac/Dc", "Kid Rock", "The Beatles", "Metallica", "Led Zeppelin", "Green Day",
                                "Nirvana", "U2", "Ramones", "Guns N' Roses", "Chuck Berry", "Jimi Hendrix"                                      , "Coldplay", "Bob Dylan", "Carlos Santana"};

int main(int argc, char* argv[]) {
        std::vector<Concert> list;
        for (int i = 0; i < 10; i++) {
                int randConcert = rand() % 15;
                int randFriends = rand() % 6 + 1;
                std::vector<std::string> friends;
                for (int j = 0; j < randFriends; j++) {
                        int randName = rand() % 15;
                        friends.push_back(friendNames[randName]);
                }
                int desire = rand() % 11;
                list.push_back(Concert(concerts[randConcert], friends, desire, randomDate()));
                friends.clear();
        }

        std::sort(list.begin(), list.end());

        for (int i = 0; i < list.size(); i++) {
                std::cout << list.at(i) << std:: endl;
        }
        return 0;
}

std::tm* randomDate() {
        time_t t;
        struct tm* date;
        time(&t);
        date = localtime(&t);
        date->tm_year = rand() % 6 + 2017;
        date->tm_mon = rand() % 12 + 1;
        date->tm_wday = rand() % 7;
        date->tm_mday = rand() % 29 + 1;
        return date;
}
