//
// Created by apu on 14.10.24.
//
#include <string>
#include <variant>
#include <vector>
#include <map>
#include <cstdint>
#include <memory>

#ifndef BENCODE_PARSER_HPP
#define BENCODE_PARSER_HPP

// define bencode_val using a struct to allow recursive definition
using bencode_val = std::variant<
    int64_t,                               // integer
    std::vector<uint8_t>,                  // byte string
    std::vector<bencode_val>,              // list (vector of bencode_val)
    std::map<std::string, bencode_val*>     // dictionary (map of string to bencode_val)
>;

class Bencode {
public:
};

#endif //BENCODE_PARSER_HPP
