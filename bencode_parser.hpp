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

struct BencodeData {
    std::variant<
        int,
        std::vector<uint8_t>,
        std::unique_ptr<std::vector<BencodeData>>,
        std::map<std::string, std::unique_ptr<BencodeData>>
    > value;
};

class BencodeParser {
public:
    const std::string data;
    size_t idx = 0;

    char peek() const {
        return data[idx];
    }

    char consume() {
        return data[idx++];
    }

    BencodeParser(std::string data) : data(std::move(data)) {
    }

    BencodeData parse() {
        char ch = peek();
        if (ch == 'i') return parse_integer();
        if (ch == 'l') return parse_list();
        if (ch == 'd') return parse_dict();
        if (isdigit(ch)) return parse_string();
    }

private:
    BencodeData parse_integer() {
        consume();
        while (true) {

        }
    }

    BencodeData parse_list() {

    }

    BencodeData parse_dict() {

    }

    BencodeData parse_string() {

    }
};



#endif //BENCODE_PARSER_HPP
