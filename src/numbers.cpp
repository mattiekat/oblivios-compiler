#include <cstdint>
#include <string>

#include "numbers.h"

std::string Numbers::removeUscores(const std::string& input) {
    std::string clean = "";

    for(const char& i : input)
        if(i != '_') clean += i;
    if(clean.empty()) clean = "0";
    return clean;
}

#define READ_VAL(base) std::stoull(input, 0, base)


uint64_t Numbers::readBin(const std::string& input) { return READ_VAL(2);  }
uint64_t Numbers::readOct(const std::string& input) { return READ_VAL(8);  }
uint64_t Numbers::readDec(const std::string& input) { return READ_VAL(10); }
uint64_t Numbers::readHex(const std::string& input) { return READ_VAL(16); }