#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "../vector/vector.h"
#include "../string/string.h"

class Parser
{
public:
/*
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
    static bool is_colon (const char&);*/
public:
    Parser(const String&);
    ~Parser() = default;
    void parse_code();
    vector<String> get_tokens() const;
private:
    vector<String> tokens;
    String m_str;
};

#include "parser.hpp"

#endif