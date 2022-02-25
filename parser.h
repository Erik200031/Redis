#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

class Parser
{
public:
    static bool is_white_space (const char&);
    static bool is_left_chevron (const char&);
    static bool is_right_chevron (const char&);
    static bool is_left_parenthese (const char&);
    static bool is_right_parenthese (const char&);
    static bool is_left_bracket (const char&);
    static bool is_right_bracket (const char&);
    static bool is_left_brace (const char&);
    static bool is_right_brace (const char&);
    static bool is_comma (const char&);
    static bool is_semicolon (const char&);
    static bool is_colon (const char&);
public:
    Parser(const std::string&);
    ~Parser();
    void parse_code();
    std::vector<std::string> get_tokens() const;
private:
    std::ifstream fin;
    std::vector<std::string> tokens;
};

#include "parser.hpp"

#endif