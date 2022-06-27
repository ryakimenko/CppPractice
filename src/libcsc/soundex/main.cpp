#include "soundex.h"
#include <fstream>
#include <iostream>
#include <map>
#include <nlohmann/json.hpp>
#include <sstream>
#include <vector>

using json = nlohmann::json;

void to_json(json& j, const std::multimap<std::string, std::string>& mmap)
{
    for (auto&& hash : mmap) {
        auto range = mmap.equal_range(hash.first);
        std::vector<std::string> names;
        for (auto i = range.first; i != range.second; ++i) {
            names.emplace_back(i->second);
        }
        std::sort(names.begin(), names.end());
        j[hash.first] = names;
        names.clear();
    }
}

json convert_csv_to_json(std::ifstream& namesFile)
{
    std::multimap<std::string, std::string> soundexMap;
    std::string name{};
    while (std::getline(namesFile, name)) {
        soundexMap.insert(
                {libcsc::soundex_hash(name.substr(0, name.find(','))),
                 name.substr(0, name.find(','))});
    }
    json result(soundexMap);
    to_json(result, soundexMap);
    return result;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "\nNo input and ouput files\n ";
        exit(-1);
    }
    if (argc == 2) {
        std::ifstream namesFile(argv[1]);
        if (!namesFile.is_open()) {
            std::cout << "\nCannot open input file ";
            exit(-1);
        }
        json result = convert_csv_to_json(namesFile);
        std::ofstream out("out.json", std::ios_base::out);
        if (!out.is_open()) {
            std::cout << "\nCannot open standart output file ";
            exit(-1);
        }
        out << result.dump(4);
    }
    if (argc == 3) {
        std::ifstream namesFile(argv[1]);
        if (!namesFile.is_open()) {
            std::cout << "\nCannot open input file ";
            exit(-1);
        }
        json result = convert_csv_to_json(namesFile);
        std::ofstream out(argv[2], std::ios_base::out);
        if (!out.is_open()) {
            std::cout << "\nCannot open output file ";
            exit(-1);
        }
        out << result.dump(4);
    } else {
        std::cout << "\nLaunch program should looks like this:\n\t./soundexApp "
                     "\"inputFile\" \"outputFile\"(optional) ";
        exit(-1);
    }
    return 0;
}
