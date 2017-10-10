#ifndef _H_CONCERT_
#define _H_CONCERT_

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Concert {

        public:
        Concert();
        Concert(std::string name, std::vector<std::string> pFriends, int pDesire, std::tm* pDate);

        friend std::string friendsList(std::vector<std::string> pFriends);
        bool operator<(const Concert& other) const;
        friend std::ostream& operator<<(std::ostream& stream, const Concert& object);

        private:
        std::string concertName;
        std::vector<std::string> friends;
        int desire;
        std::tm date;
};
#endif
