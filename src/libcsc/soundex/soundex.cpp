#include "soundex.h"

#include <algorithm>
#include <iostream>
namespace libcsc {

static void tranform_consonants(std::string& str)
{
    char new_val = 0;
    std::replace_if(
            str.begin(),
            str.end(),
            [&](char x) {
                switch (x) {
                case 'B':
                case 'F':
                case 'P':
                case 'V':
                    new_val = '1';
                    return true;
                case 'C':
                case 'G':
                case 'J':
                case 'K':
                case 'Q':
                case 'S':
                case 'X':
                case 'Z':
                    new_val = '2';
                    return true;
                case 'T':
                case 'D':
                    new_val = '3';
                    return true;
                case 'L':
                    new_val = '4';
                    return true;
                case 'M':
                case 'N':
                    new_val = '5';
                    return true;
                case 'R':
                    new_val = '6';
                    return true;
                default:
                    return false;
                }
            },
            new_val);
}

std::string soundex_hash(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    const char firstLetter = *(std::find_if(str.begin(), str.end(), [](char x) {
        return (x >= 'A' && x <= 'Z');
    }));

    auto newEnd = std::remove_if(str.begin() + 1, str.end(), [](char x) {
        return ((x) == 'H' || (x) == 'W');
    });
    str.erase(newEnd, str.end());

    tranform_consonants(str);

    newEnd = std::unique(str.begin(), str.end());
    str.erase(newEnd, str.end());

    newEnd = std::remove_if(str.begin() + 1, str.end(), [](char x) {
        return ((x) == 'A' || (x) == 'E' || (x) == 'I' || (x) == 'O'
                || (x) == 'U' || (x) == 'Y');
    });
    str.erase(newEnd, str.end());

    str[0] = toupper(firstLetter);

    str.resize(4, '0');
    return str;
}
} // namespace libcsc